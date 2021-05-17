cmake_minimum_required(VERSION 3.19)
project(proj)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)


file(GLOB TEST_FILES CONFIGURE_DEPENDS
        "example/test/*.cpp"
        )

add_executable(Test
        example/test/main.cpp
        ${TEST_FILES}
        )

target_link_libraries(Test graphviewer)


file(GLOB FILES CONFIGURE_DEPENDS
        "./*.cpp"
        )

add_executable(main
        main.cpp
        ${FILES}
        )

target_link_libraries(main graphviewer)
