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
    src/Elysia/LightsElysia.h src/Elysia/LightsElysia.cpp
    src/SerialPortForwarder.cpp
    src/SerialPortForwarder.h
    src/Elysia/DriverControlsElysia.h src/Elysia/DriverControlsElysia.cpp
    src/util.h src/util.cpp
    src/BatteryFaults.h src/BatteryFaults.cpp
    src/KeyMotor.h src/KeyMotor.cpp
    src/Battery.h src/Battery.cpp
    src/MotorDetails.h src/MotorDetails.cpp
    src/Elysia/AuxBmsElysia.h src/Elysia/AuxBmsElysia.cpp
    src/Mppt.h src/Mppt.cpp
    src/B3.h src/B3.cpp
    src/ProximitySensors.h src/ProximitySensors.cpp
    src/Mbms.h src/Mbms.cpp
    src/Telemetry.h src/Telemetry.cpp
    src/Elysia/KeyMotorElysia.h
    src/Elysia/KeyMotorElysia.cpp
    src/Elysia/MotorDetailsElysia.h
    src/Elysia/MotorDetailsElysia.cpp
    src/Elysia/MotorFaultsElysia.h
    src/Elysia/MotorFaultsElysia.cpp
    src/PropertyDefinition.h
    src/Setting.h src/Setting.cpp
    src/Elysia/MpptElysia.h src/Elysia/MpptElysia.cpp
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
