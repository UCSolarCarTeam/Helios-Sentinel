cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(Sentinel LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick SerialPort)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(Sentinel src/main.cpp
    src/Packets/Elysia/AuxBmsElysia.cpp src/Packets/Elysia/AuxBmsElysia.h src/Packets/Elysia/DriverControlsElysia.cpp
    src/Packets/Elysia/DriverControlsElysia.h src/Packets/Elysia/KeyMotorElysia.cpp src/Packets/Elysia/KeyMotorElysia.h
    src/Packets/Elysia/LightsElysia.cpp src/Packets/Elysia/LightsElysia.h src/Packets/Elysia/MotorDetailsElysia.cpp
    src/Packets/Elysia/MotorDetailsElysia.h src/Packets/Elysia/MotorFaultsElysia.cpp src/Packets/Elysia/MotorFaultsElysia.h
    src/Packets/B3.cpp src/Packets/B3.h src/Packets/Battery.cpp src/Packets/Battery.h src/Packets/BatteryFaults.cpp
    src/Packets/BatteryFaults.h src/Packets/KeyMotor.cpp src/Packets/KeyMotor.h src/Packets/Mbms.cpp src/Packets/Mbms.h
    src/Packets/MotorDetails.cpp src/Packets/MotorDetails.h src/Packets/Mppt.cpp src/Packets/Mppt.h src/Packets/ProximitySensors.cpp
    src/Packets/ProximitySensors.h src/Packets/Telemetry.cpp src/Packets/Telemetry.h src/Utils/PropertyDefinition.h src/Utils/SerialPortForwarder.cpp
    src/Utils/SerialPortForwarder.h src/Utils/setting.cpp src/Utils/setting.h src/Utils/util.cpp src/Utils/util.h



)

qt_add_resources(Sentinel "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(Sentinel PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::SerialPort
)

if (BUILD_QDS_COMPONENTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/qmlcomponents)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/qmlmodules)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

include(GNUInstallDirs)
install(TARGETS Sentinel
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
