# CMakeLists.txt

cmake_minimum_required (VERSION 2.4)
project (shape_editor)

enable_language (CXX)
add_compile_options (-Wall -Wextra -Werror)
set (CMAKE_CXX_STANDARD 11)

# Custom directory var
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set (SRCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (MODEL_SRC_DIR ${SRCS_DIR}/model)

set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (MODEL_INC_DIR ${INCLUDE_DIR}/model)

include_directories (${MODEL_INC_DIR})

message ("-- CXX flag '-Wall -Wextra -Werror' enabled.")

# Debug option flag
option (DEBUG "DEBUG" OFF)

# No option enabled
if (DEBUG STREQUAL "OFF")
  message ("-- No option enabled")
  message ("-- CXX flag '-O2' enabled")
  add_compile_options (-O2)
endif ()
  

# Debug enabled
if (DEBUG STREQUAL "ON")
  message ("-- Option DEBUG=ON")
  message ("-- CXX flag '-g' added")
  add_compile_options (-g)
endif () # Debug option

add_subdirectory (src)

# Getting all project src and header files.
file (GLOB_RECURSE PROJECT_FILES
  ${SRCS_DIR}/*.cpp
  ${MODEL_SRC_DIR}/*.cpp
  ${MODEL_INC_DIR}/*.hpp)

# Automated format with .clang-format
add_custom_target (
  format
  COMMAND echo ${PROJECT_FILES}
  | grep -o -G -e .[^/]*.cpp -e .[^/]*.hpp
  | cut -d "/" -f 2
  | sed s/^/--\ Formating\ file:\ /
  COMMAND clang-format -i ${PROJECT_FILES} > /dev/null)

# Automated tags builind
add_custom_target (
  tags
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND ctags -R
  COMMAND echo "-- tags file built in ${CMAKE_SOURCE_DIR}")

# Cleaning tmp files AND cleaning
add_custom_target (
  clean-tmp
  COMMAND ${CMAKE_MAKE_PROGRAM}
  COMMAND ${CMAKE_MAKE_PROGRAM} clean
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND find . -type f -name '*~' -delete 2> /dev/null
  COMMAND find . -type f -name '\#*' -delete 2> /dev/null)

# Adding files to clean target
set_property (
  DIRECTORY
  APPEND
  PROPERTY
  ADDITIONAL_MAKE_CLEAN_FILES
  ${CMAKE_SOURCE_DIR}/tags
  # Cleaning extra directories
  ${CMAKE_SOURCE_DIR}/lib
  ${CMAKE_SOURCE_DIR}/bin)

# Re-seting the options to default value
unset (DEBUG)
