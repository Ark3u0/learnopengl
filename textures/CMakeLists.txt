cmake_minimum_required(VERSION 3.4)
project(textures)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

# Find Packages
find_package(glfw3 3.2 REQUIRED)
message(STATUS "GLFW3 in ${GLFW3_INCLUDE_DIR}")
find_package(GLEW REQUIRED)
message(STATUS "Found GLEW in ${GLEW_INCLUDE_DIR}")

# Set variables
set(GLFW_LIBS glfw)
set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h)

# Include headers
include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${SOIL_INCLUDE_DIR})


add_executable(textures ${SOURCE_FILES} ${HEADER_FILES})

# Link libraries to target
target_link_libraries(textures ${GLFW_LIBS} ${GLEW_LIBRARIES} ${SOIL_LIBRARIES})

if (APPLE)
    target_link_libraries(textures "-framework OpenGL")
endif()
