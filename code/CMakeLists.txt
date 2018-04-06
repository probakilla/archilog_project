# CMakeLists.txt

cmake_minimum_required (VERSION 2.4)
project (shape_editor)

enable_language (CXX)
add_compile_options (-Wall -Wextra -Werror)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

include_directories (include/model)

option (DEBUG "DEBUG" OFF)
if (DEBUG)
  add_compile_options (-g)
endif (DEBUG)

add_subdirectory (src)

file (GLOB_RECURSE PROJECT_FILES src/model/*.cpp src/*.cpp include/model/*.hpp)

add_custom_target (
  format
  COMMAND echo ${PROJECT_FILES}
  | grep -o -G -e .[^/]*.cpp -e .[^/]*.hpp
  | cut -d "/" -f 2
  | sed s/^/--\ Formating\ file:\ /
  COMMAND clang-format -i ${PROJECT_FILES} > /dev/null)