cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(stat_controls LANGUAGES CXX)

message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# source .cpp file will be searched in
file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/types/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/constants/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node/element_coordinate/*.cpp
)

add_executable(stat_exec
    main.cpp
    ${SRC_FILES}
)

target_include_directories(stat_exec
    PUBLIC
         ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(stat_exec
   PROPERTIES RUNTIME_OUTPUT_DIRECTORY
      ${PROJECT_SOURCE_DIR}/bin
)

target_compile_options(stat_exec PUBLIC -g3 -o0)
