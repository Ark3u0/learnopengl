cmake_minimum_required(VERSION 3.4)
project(camera)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ./bin)

add_subdirectory(exercises/ex1)
add_subdirectory(exercises/ex2)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES shader.h camera.h)

add_executable(camera ${SOURCE_FILES} ${HEADER_FILES})

# Link Libraries
target_link_libraries(camera ${GLFW_LIBS} ${GLEW_LIBRARIES} ${CMAKE_SOURCE_DIR}/lib/libSOIL.a)

if (APPLE)
    target_link_libraries(camera "-framework OpenGL")
endif()