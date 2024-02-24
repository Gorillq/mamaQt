cmake_minimum_required(VERSION 3.18)
project(mamaqt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CROSSCOMPILING ON)
set(CMAKE_PREFIX_PATH ~/Qt/6.6.2/gcc_64/bin)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(mamaqt main.cpp
        baza.h)
target_link_libraries(mamaqt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

