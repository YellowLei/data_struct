CMAKE_MINIMUM_REQUIRED( VERSION 3.5 )

set(cmake_cxx_compile 'g++')
set(cmake_build_type Debug)

project( SEARCH )

include_directories(../../sort/lib_sort/src)
link_directories(../../sort/lib_sort/lib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory( ${PROJECT_SOURCE_DIR}/src )
