cmake_minimum_required(VERSION 3.4)
project(coordinate_systems)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h)

add_executable(coordinate_systems ${SOURCE_FILES} ${HEADER_FILES})

# Link Libraries
target_link_libraries(coordinate_systems ${GLFW_LIBS} ${GLEW_LIBRARIES} ${CMAKE_SOURCE_DIR}/lib/libSOIL.a)

if (APPLE)
    target_link_libraries(coordinate_systems "-framework OpenGL")
endif()