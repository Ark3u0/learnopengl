cmake_minimum_required(VERSION 3.4)
project(camera_ex2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h camera.h)

add_executable(camera_ex2 ${SOURCE_FILES} ${HEADER_FILES})

# Link Libraries
target_link_libraries(camera_ex2 ${GLFW_LIBS} ${GLEW_LIBRARIES} ${CMAKE_SOURCE_DIR}/lib/libSOIL.a)

if (APPLE)
    target_link_libraries(camera_ex2 "-framework OpenGL")
endif()