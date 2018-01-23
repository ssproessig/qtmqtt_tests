#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QDialog>

namespace Ui {
class MqttClient;
}

class MqttClient : public QDialog
{
    Q_OBJECT

public:
    explicit MqttClient(QWidget *parent = 0);
    ~MqttClient();

private:
    Ui::MqttClient *ui;
};

#endif // MQTTCLIENT_H
