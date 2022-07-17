file(GLOB_RECURSE SRC_FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/*.h
   ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library( parser
   SHARED
      ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp
      ${SRC_FILES}
      ${HEADER_FILES}
)

target_include_directories( parser
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/src
      ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options( stat_ast
   PRIVATE
      -Wall -fPIC
)
