# src/CMakeLists.txt

add_subdirectory (model)

add_library (editor main.cpp)
target_link_libraries (editor model)

add_executable (shape_editor main.cpp)
target_link_libraries (shape_editor editor)
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
