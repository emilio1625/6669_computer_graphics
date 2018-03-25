cmake_minimum_required(VERSION 3.6)
project(tarea5)

set(SOURCE_FILES main.cpp)

add_executable(tarea5 ${SOURCE_FILES})
target_link_libraries(tarea5 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
