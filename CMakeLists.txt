cmake_minimum_required(VERSION 3.4)
project(shaders)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/module/")

# Find Packages
find_package(glfw3 3.2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(SOIL REQUIRED)
message(STATUS "Found SOIL in ${SOIL_INCLUDE_DIR}")

# Set variables
set(GLFW_LIBS glfw)
set(SOIL_LIBS SOIL)

# Include headers
include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${SOIL_INCLUDE_DIR} ${GLM_INCLUDE_DIRS})

add_subdirectory(create_a_window)
add_subdirectory(hello_triangle)
add_subdirectory(shaders)
add_subdirectory(textures)
add_subdirectory(transformations)
add_subdirectory(coordinate_systems)




