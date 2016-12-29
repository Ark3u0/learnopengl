cmake_minimum_required(VERSION 3.4)
project(shaders_ex2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h)

add_executable(shaders_ex2 ${SOURCE_FILES} ${HEADER_FILES})

# Link libraries to target
target_link_libraries(shaders_ex2 ${GLFW_LIBS} ${GLEW_LIBRARIES})

if (APPLE)
    target_link_libraries(shaders_ex2 "-framework OpenGL")
endif()
