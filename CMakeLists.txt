cmake_minimum_required (VERSION 3.9)
set(P_NAME test_qtmqtt)


project(${P_NAME})
set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 5.8 COMPONENTS Core Gui Widgets Mqtt REQUIRED)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_executable(
    ${P_NAME}
    main.cpp
    MqttClient.ui
    MqttClient.h
    MqttClient.cpp
)
target_link_libraries(
    ${P_NAME}
    Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Mqtt
)
