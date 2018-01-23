#include <QApplication>

#include "MqttClient.h"


int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    MqttClient c;
    c.show();

    return a.exec();
}
