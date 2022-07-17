cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(stat_controls LANGUAGES CXX)
project(stat_controls VERSION 1.0.0)

message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# source .cpp file will be searched in
file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_executable(stat_exec
    main.cpp
    ${SRC_FILES}
    ${HEADER_FILES}
)

target_include_directories(stat_exec
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(stat_exec
   PROPERTIES RUNTIME_OUTPUT_DIRECTORY
      ${PROJECT_SOURCE_DIR}/bin
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/tree)

target_link_libraries(stat_exec
   PUBLIC
      stat_ast
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/parser)

target_compile_options(stat_exec PUBLIC -g3 -o0)
