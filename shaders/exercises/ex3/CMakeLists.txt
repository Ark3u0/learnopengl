cmake_minimum_required(VERSION 3.4)
project(shaders_ex3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h)

add_executable(shaders_ex3 ${SOURCE_FILES} ${HEADER_FILES})

# Link libraries to target
target_link_libraries(shaders_ex3 ${GLFW_LIBS} ${GLEW_LIBRARIES})

if (APPLE)
    target_link_libraries(shaders_ex3 "-framework OpenGL")
endif()
