cmake_minimum_required(VERSION 3.6)
project(6669_computer_graphics)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

add_subdirectory(primitivas)
add_subdirectory(tarea4)
add_subdirectory(tarea5)
add_subdirectory(tarea6)
