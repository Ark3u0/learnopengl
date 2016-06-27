cmake_minimum_required(VERSION 3.5)
project(create_a_window)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find Packages
find_package(glfw3 3.2 REQUIRED)
find_package(GLEW REQUIRED)

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# Include headers
include_directories(${GLFW_INCLUDE_DIRS})

# Set variables
set(GLFW_LIBS glfw)
set(SOURCE_FILES main.cpp)

add_executable(create_a_window ${SOURCE_FILES})

# Link libraries to target
target_link_libraries(create_a_window ${GLFW_LIBS})

if (APPLE)
    target_link_libraries(create_a_window "-framework OpenGL")
endif()
