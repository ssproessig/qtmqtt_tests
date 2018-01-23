#include "MqttClient.h"
#include "ui_MqttClient.h"

#include <QtMqtt/QtMqtt>



namespace Constants
{
    const QString usedTopic("/World");
    const QMqttTopicName topicName(usedTopic);
    const QMqttTopicFilter topicFilter(usedTopic);
}



struct MqttClient::Data
{
    explicit Data(QDialog* dialog)
        : ui(std::make_unique<Ui::MqttClient>())
        , mqttClient(std::make_unique<QMqttClient>())
    {
        ui->setupUi(dialog);

        // MQTT GUI code
        connect(ui->btnSendMessage, &QPushButton::clicked, [&](bool)
        {
            mqttClient->publish(
                Constants::topicName,
                ui->edToSend->text().toUtf8(),
                0, false
            );
        });



        // MQTT handling code
        auto c = mqttClient.get();
        connect(c, &QMqttClient::connected, [this]()
        {
            qDebug() << "Connected!";
            ui->tabWidget->setCurrentWidget(ui->tabMqtt);

            auto subscription = mqttClient->subscribe(Constants::topicFilter, 0);
            connect(subscription, &QMqttSubscription::messageReceived, [&](const QMqttMessage & message)
            {
                ui->lbReceived->setText(message.payload());
            });
        });
        connect(c, &QMqttClient::disconnected, [this]()
        {
            qDebug() << "Disconnected!";
            ui->tabWidget->setCurrentWidget(ui->tabConnection);
        });
        connect(c, &QMqttClient::errorChanged, [](QMqttClient::ClientError anError)
        {
            qWarning() << "Client error: " << anError;
        });
        connect(c, &QMqttClient::stateChanged, [](QMqttClient::ClientState aState)
        {
            qDebug() << "Client state: " << aState;
        });



        // MQTT connection and subscription management GUI code
        connect(ui->btnConnect, &QPushButton::clicked, [&](bool)
        {
            mqttClient->setHostname(ui->edHost->text());
            mqttClient->setPort(quint16(ui->edPort->value()));
            mqttClient->setUsername(ui->edUsername->text());
            mqttClient->setPassword(ui->edPassword->text());
            mqttClient->connectToHost();
        });
        connect(ui->btnDisconnect, &QPushButton::clicked, [&](bool)
        {
            mqttClient->disconnectFromHost();
        });
    }


    std::unique_ptr<Ui::MqttClient> ui;
    std::unique_ptr<QMqttClient> mqttClient;
};



MqttClient::MqttClient(QWidget* parent) :
    QDialog(parent),
    d(std::make_unique<Data>(this))
{
}

MqttClient::~MqttClient() {}
