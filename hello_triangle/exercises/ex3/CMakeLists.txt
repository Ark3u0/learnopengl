cmake_minimum_required(VERSION 3.4)
project(hello_triangle_ex3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

set(SOURCE_FILES main.cpp)

add_executable(hello_triangle_ex3 ${SOURCE_FILES})

# Link libraries to target
target_link_libraries(hello_triangle_ex3 ${GLFW_LIBS} ${GLEW_LIBRARIES})

if (APPLE)
    target_link_libraries(hello_triangle_ex3 "-framework OpenGL")
endif()
