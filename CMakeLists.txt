cmake_minimum_required(VERSION 3.24)
project(raylib_test VERSION 0.0.1)

#Dependencies
include(FetchContent)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare( # Check if the version of raylib is installed on the machine, if not then download and make available
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.zip
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
# We don't want to build the examples - we only need the library
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# Our project
set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib) # Link the raylib library to our project

# Checks if OSX and links appropriate frameworks
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()