cmake_minimum_required(VERSION 3.25)
project(foru)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/home/kamilk/Qt/6.6.1/gcc_64/")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(foru main.cpp
        baza.h)
target_link_libraries(foru
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

