# CMakeLists.txt

cmake_minimum_required (VERSION 2.6)
project (shape_editor)

enable_language (CXX)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -lboost_serialization")
set (CMAKE_CXX_STANDARD 11)

# Custom directory var
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Ressources dir
set (RESSOURCES_LOCATION \"${CMAKE_CURRENT_SOURCE_DIR}/ressources/\")
configure_file (${CMAKE_SOURCE_DIR}/include/config.hpp.cmake
  ${CMAKE_SOURCE_DIR}/include/config.hpp)

# SRC dirs
set (SRCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (SHAPE_SRC_DIR ${SRCS_DIR}/shape)
set (WIDGET_SRC_DIR ${SRCS_DIR}/widget)
set (TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set (DOC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../doc)

# Include dirs
set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (SHAPE_INC_DIR ${INCLUDE_DIR}/shape)
set (WIDGET_INC_DIR ${INCLUDE_DIR}/widget)

include_directories (include/ ${WIDGET_INC_DIR} ${SHAPE_INC_DIR})

# Qt Libs
set (CMAKE_AUTOMOC ON)
find_package(Qt4 REQUIRED QtCore QtGui)
include (${QT_USE_FILE})

# Debug option flags
option (DEBUG "DEBUG" OFF)
option (TESTS "TESTS" OFF)

# Tests enabled
if (TESTS STREQUAL "ON")
  enable_testing ()
  set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g -lboost_serialization")
  message ("-- Option DTESTS=ON")
  message ("-- CXX Flags '${CMAKE_CXX_FLAGS}' enabled")
  add_subdirectory (tests)
endif () # Tests option

# No option enabled
if (DEBUG STREQUAL "OFF" AND TESTS STREQUAL "OFF")
  set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -O2  -lboost_serialization")
  message ("-- No option enabled")
  message ("-- CXX flag ${CMAKE_CXX_FLAGS} enabled")
endif ()

# Debug enabled
if (DEBUG STREQUAL "ON")
  set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g -lboost_serialization")
  message ("-- Option DDEBUG=ON")
  message ("-- CXX flags '${CMAKE_CXX_FLAGS}' enabled")
endif () # Debug option

add_subdirectory (src)


# Getting all project src and header files.
file (GLOB_RECURSE PROJECT_FILES
  ${SRCS_DIR}/*.cpp
  ${SHAPE_SRC_DIR}/*.cpp
  ${SHAPE_INC_DIR}/*.hpp
  ${TESTS_DIR}/*.cpp
  ${TESTS_DIR}/*.hpp)

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
  COMMAND ctags -R -e
  COMMAND echo "-- tags file built in ${CMAKE_SOURCE_DIR}")

# Automated doc generation
add_custom_target (
  doc
  WORKING_DIRECTORY ${DOC_DIR}
  COMMAND doxygen doxygen.config
  COMMAND xdg-open doc/html/index.html)

# Adding files to clean target
set_property (
  DIRECTORY
  APPEND
  PROPERTY
  ADDITIONAL_MAKE_CLEAN_FILES
  ${CMAKE_SOURCE_DIR}/TAGS
  # Cleaning extra directories
  ${DOC_DIR}/doc)


# Re-seting the options todefault value
unset (TESTS CACHE)
unset (DEBUG CACHE)

