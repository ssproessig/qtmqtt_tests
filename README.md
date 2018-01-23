# Testing MQTT capabilities of Qt 5.9/5.10

## Aim
This sample SHALL test means provided by `QtMqtt`. It requires you to

- run a MQTT broker ([mosquitto](https://mosquitto.org/), [eMQTT](http://emqtt.io/)) somewhere on your network
- have the broker setup with username/password authentication

## Tested with
- Qt 5.9 and 5.10 on Linux/macOs

## Prerequisites
Qt 5.9 and 5.10 do not yet come with the MQTT package (at least not the open-source packages).
Therefore the following steps have to be taken once:

```bash
$>  git clone git://code.qt.io/qt/qtmqtt.git`  # other URLs see https://code.qt.io/cgit/qt/qtmqtt.git/
$>  cd qtmqtt
$>  qmake
$>  make -j
$>  sudo make install
```

For some reason Qt 5.10 is fixed in the `.cmake` file created. To use it with CMake and e.g. Qt 5.9.0 you have to patch line 84
```diff
velociraptor:tmp ssp$ diff -u Qt5MqttConfig.cmake.orig Qt5MqttConfig.cmake
--- Qt5MqttConfig.cmake.orig	2018-01-23 21:01:52.000000000 +0100
+++ Qt5MqttConfig.cmake	2018-01-23 21:02:05.000000000 +0100
@@ -81,7 +81,7 @@
     foreach(_module_dep ${_Qt5Mqtt_MODULE_DEPENDENCIES})
         if (NOT Qt5${_module_dep}_FOUND)
             find_package(Qt5${_module_dep}
-                5.10.0 ${_Qt5Mqtt_FIND_VERSION_EXACT}
+                5.9.0 ${_Qt5Mqtt_FIND_VERSION_EXACT}
                 ${_Qt5Mqtt_DEPENDENCIES_FIND_QUIET}
                 ${_Qt5Mqtt_FIND_DEPENDENCIES_REQUIRED}
                 PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
```

## Building and running
Make sure CMake 3.9 (`cmake` binary) and Qt >= 5.9 (`qmake` binary) are on the `PATH`.
```
$>  cd qtmqtt_test
$>  cd .. && mkdir build
$>  cmake ../qtmqtt_test
$>  cmake --build .
$>  ./test_qtmqtt
```
