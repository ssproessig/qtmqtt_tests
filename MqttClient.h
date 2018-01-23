#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QDialog>
#include <memory>



class MqttClient : public QDialog
{
    Q_OBJECT

public:
    explicit MqttClient(QWidget* parent = nullptr);
    ~MqttClient();

private:
    struct Data;
    std::unique_ptr<Data> d;
};



#endif // MQTTCLIENT_H
