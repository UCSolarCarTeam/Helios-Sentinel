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
    src/Utils/PropertyDefinition.h src/Utils/SerialPortForwarder.cpp
    src/Utils/SerialPortForwarder.h src/Utils/Setting.cpp src/Utils/Setting.h src/Utils/util.cpp src/Utils/util.h
    src/Packets/Elysia/AuxBmsElysia.cpp src/Packets/Elysia/AuxBmsElysia.h src/Packets/Elysia/BatteryElysia.cpp src/Packets/Elysia/BatteryElysia.h
    src/Packets/Elysia/BatteryFaultsElysia.cpp src/Packets/Elysia/BatteryFaultsElysia.h src/Packets/Elysia/DriverControlsElysia.cpp
    src/Packets/Elysia/DriverControlsElysia.h src/Packets/Elysia/KeyMotorElysia.cpp src/Packets/Elysia/KeyMotorElysia.h
    src/Packets/Elysia/LightsElysia.cpp src/Packets/Elysia/LightsElysia.h src/Packets/Elysia/MotorDetailsElysia.cpp
    src/Packets/Elysia/MotorDetailsElysia.h src/Packets/Elysia/MotorFaultsElysia.cpp src/Packets/Elysia/MotorFaultsElysia.h
    src/Packets/Helios/B3.cpp src/Packets/Helios/B3.h src/Packets/Helios/Battery.cpp src/Packets/Helios/Battery.h src/Packets/Helios/BatteryFaults.cpp
    src/Packets/Helios/BatteryFaults.h src/Packets/Helios/KeyMotor.cpp src/Packets/Helios/KeyMotor.h src/Packets/Helios/Mbms.cpp src/Packets/Helios/Mbms.h
    src/Packets/Helios/MotorDetails.cpp src/Packets/Helios/MotorDetails.h src/Packets/Helios/Mppt.cpp src/Packets/Helios/Mppt.h src/Packets/Helios/ProximitySensors.cpp
    src/Packets/Helios/ProximitySensors.h src/Packets/Helios/Telemetry.cpp src/Packets/Helios/Telemetry.h



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
