# CMakeLists.txt

cmake_minimum_required (VERSION 2.4)
project (shape_editor)

enable_language (CXX)

add_compile_options (-Wall -Wextra -Werror)

option (DEBUG "DEBUG" OFF)
if (DEBUG)
  add_compile_options (-g)
endif (DEBUG)

include_directories (include)

add_executable (shape_editor main.cpp)
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
