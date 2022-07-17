file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node/tree_node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node/element_coordinate/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/tree_node/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/tree_node/element_coordinate/*.h
)

add_library( stat_ast
   SHARED
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree.cpp
      ${SRC_FILES}
      ${HEADER_FILES}
)

target_include_directories( stat_ast
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/src
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tree
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree_node/element_coordinate
)

target_compile_options( stat_ast
   PRIVATE
      -Wall -fPIC
)
