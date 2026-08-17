cmake_minimum_required(VERSION 3.28)

set(TARGET_NAME tetra-core)
project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES
        "src/*.cpp"
)

add_library(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC
        "src/"
)