set( libsearch_src search.cpp binaryTree.cpp AVLTree.cpp )

add_library(search SHARED ${libsearch_src})

add_library(search_static STATIC ${libsearch_src})

SET_TARGET_PROPERTIES(search_static PROPERTIES OUTPUT_NAME "search")

set_target_properties(search PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(search_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

set_target_properties(search PROPERTIES VERSION 1.2 soversion 1)

add_executable( main main.cpp )

target_link_libraries( main search sort)
