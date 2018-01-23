#include "MqttClient.h"
#include "ui_MqttClient.h"


struct MqttClient::Data
{
    explicit Data(QDialog* dialog):
        ui(std::make_unique<Ui::MqttClient>())
    {
        ui->setupUi(dialog);

        connect(ui->btnSendMessage, &QPushButton::clicked, [](bool)
        {
            // TODO: publish to MQTT topic
        });

        // TODO: register for MQTT topic
    }


    std::unique_ptr<Ui::MqttClient> ui;
};



MqttClient::MqttClient(QWidget* parent) :
    QDialog(parent),
    d(std::make_unique<Data>(this))
{
}

MqttClient::~MqttClient() {}
