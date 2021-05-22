cmake_minimum_required(VERSION 3.19)
project(proj)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)

file(GLOB EXAMPLE_FILES CONFIGURE_DEPENDS
        "example/*.cpp"
        )

file(GLOB PROJ_FILES CONFIGURE_DEPENDS
        "src/*.cpp"
        "src/*.h"
        )

add_executable(Example
        example/main.cpp
        ${EXAMPLE_FILES}
        )

add_executable(Proj
        src/main.cpp
        ${PROJ_FILES}
        src/loader.cpp)

target_link_libraries(Example graphviewer)
target_link_libraries(Proj graphviewer)

