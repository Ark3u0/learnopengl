cmake_minimum_required(VERSION 3.4)
project(hello_triangle)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

add_subdirectory(exercises/ex1)
add_subdirectory(exercises/ex2)
add_subdirectory(exercises/ex3)

set(SOURCE_FILES main.cpp)

add_executable(hello_triangle ${SOURCE_FILES})

# Link libraries to target
target_link_libraries(hello_triangle ${GLFW_LIBS} ${GLEW_LIBRARIES})

if (APPLE)
    target_link_libraries(hello_triangle "-framework OpenGL")
endif()
