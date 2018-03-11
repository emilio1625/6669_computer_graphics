cmake_minimum_required(VERSION 3.6)
project(tarea4)

set(SOURCE_FILES main.cpp)

add_executable(tarea4 ${SOURCE_FILES})
target_link_libraries(tarea4 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
