cmake_minimum_required(VERSION 3.4)
project(textures)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

add_subdirectory(exercises/ex1)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h)

add_executable(textures ${SOURCE_FILES} ${HEADER_FILES})

# Link Libraries
target_link_libraries(textures ${GLFW_LIBS} ${GLEW_LIBRARIES} ${CMAKE_SOURCE_DIR}/lib/libSOIL.a)

if (APPLE)
    target_link_libraries(textures "-framework OpenGL")
endif()