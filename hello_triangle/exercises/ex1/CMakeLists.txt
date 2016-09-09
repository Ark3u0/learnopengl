cmake_minimum_required(VERSION 3.4)
project(ex1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ../../bin)

# Find Packages
find_package(glfw3 3.2 REQUIRED)
find_package(GLEW REQUIRED)

# Include headers
include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# Set variables
set(GLFW_LIBS glfw)
set(SOURCE_FILES main.cpp)

add_executable(ex1 ${SOURCE_FILES})

# Link libraries to target
target_link_libraries(ex1 ${GLFW_LIBS} ${GLEW_LIBRARIES})

if (APPLE)
    target_link_libraries(ex1 "-framework OpenGL")
endif()
