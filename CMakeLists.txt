cmake_minimum_required(VERSION 3.10)
project(QtSerial)

set(CMAKE_CXX_STANDARD 11)

include_directories(SerialPortToolDemo)
# 打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH  C:/Qt/Qt5.7.1/5.7/mingw53_32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#查找Qt的库
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

set(UI_FILES)
set(RC_FILES)
set(QRC_FILES)
set(Qt5SerialPort)

get_target_property(QtCore_location Qt5::Core LOCATION)
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
link_directories(${QT_DIR}/lib C:/Qt/Qt5.9.4/Tools/mingw530_32/lib)

add_executable(QtSerial
        SerialPortToolDemo/main.cpp
        SerialPortToolDemo/mainwindow.cpp
        SerialPortToolDemo/mainwindow.h
        SerialPortToolDemo/utils.cpp
        SerialPortToolDemo/utils.h)

qt5_use_modules(QtSerial Widgets Core SerialPort)