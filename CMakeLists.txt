cmake_minimum_required(VERSION 3.24)
project(Maturitna)

set(WARNING_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2")

#set(COMPILE_FLAGS "-O0 -pipe")
#set(COMPILE_FLAGS "-O1 -pipe")
#set(COMPILE_FLAGS "-O2 -pipe")
#set(COMPILE_FLAGS "-O3 -pipe")
set(COMPILE_FLAGS "-Ofast -pipe")
#set(COMPILE_FLAGS "-Og -pipe")
#set(COMPILE_FLAGS "-Os -pipe")

set(CMAKE_CXX_STANDARD 23)

Set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS} ${WARNING_FLAGS} -Werror")
#Set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS} ${WARNING_FLAGS}")
#Set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS}")

add_executable(Maturitna main.cpp Shapes/Sphere.cpp Shapes/Sphere.hpp userInput/inputControl.cpp userInput/inputControl.hpp userInput/config/configControl.cpp userInput/config/configControl.hpp userInput/config/ConfigFile.cpp userInput/config/ConfigFile.hpp Shapes/Shape.cpp Shapes/Shape.hpp miscFunctions.cpp miscFunctions.hpp)
