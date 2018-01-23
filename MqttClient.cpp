#include "MqttClient.h"
#include "ui_MqttClient.h"



MqttClient::MqttClient(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MqttClient)
{
    ui->setupUi(this);

    connect(ui->btnSendMessage, &QPushButton::clicked, [](bool)
    {
        // TODO: publish to MQTT topic
    });

    // TODO: register for MQTT topic
}


MqttClient::~MqttClient()
{
    delete ui;
}
