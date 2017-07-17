CMAKE_MINIMUM_REQUIRED( VERSION 3.5 )

set(cmake_cxx_compile 'g++')
set(cmake_build_type Debug)

project( SEARCH )

INCLUDE_DIRECTORIES(../search_lib/src)
LINK_DIRECTORIES(../search_lib/lib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory( ${PROJECT_SOURCE_DIR}/src )
