cmake_minimum_required(VERSION 3.24)
project(Maturita-Renderer)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_NAME "renderer")

set(WARNING_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2")

set(CPU_ARCH "-march=native")

#set(COMPILE_FLAGS "-O0 -pipe")
#set(COMPILE_FLAGS "-O1 -pipe")
#set(COMPILE_FLAGS "-O2 -pipe")
#set(COMPILE_FLAGS "-O3 -pipe")
#set(COMPILE_FLAGS "-Ofast -pipe")
set(COMPILE_FLAGS "-Og -pipe")
#set(COMPILE_FLAGS "-Os -pipe")

#set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS} ${CPU_ARCH} ${WARNING_FLAGS} -Werror")
Set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS} ${CPU_ARCH} ${WARNING_FLAGS}")
#Set(CMAKE_CXX_FLAGS "${COMPILE_FLAGS} ${CPU_ARCH}")

add_executable(${EXECUTABLE_NAME} main.cpp userInput/inputControl.cpp userInput/inputControl.hpp userInput/config/configControl.cpp userInput/config/configControl.hpp userInput/config/ConfigFile.cpp userInput/config/ConfigFile.hpp Shapes/Shape.hpp miscFunctions.cpp miscFunctions.hpp Shapes/Cuboid.cpp Shapes/Cuboid.hpp Shapes/Sphere.cpp Shapes/Sphere.hpp Shapes/Tetrahedron.cpp Shapes/Tetrahedron.hpp Shapes/Cylinder.cpp Shapes/Cylinder.hpp Renderer/Renderer.cpp Renderer/Renderer.hpp run.cpp run.hpp Renderer/rendererMisc.cpp Renderer/rendererMisc.hpp Renderer/Rotation.cpp Renderer/Rotation.hpp Renderer/Rotation.hpp Shapes/ShapeContainer.cpp Shapes/ShapeContainer.hpp Shapes/Shape.cpp test.cpp test.hpp Renderer/HitPoint.cpp Renderer/HitPoint.hpp errorHandling.cpp errorHandling.hpp debugMisc.cpp debugMisc.hpp benchmark.cpp benchmark.hpp)
