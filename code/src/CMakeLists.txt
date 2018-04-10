# src/CMakeLists.txt

add_subdirectory (model)
add_subdirectory (view)

add_library (editor main.cpp ${MOC_OUTFILES})
target_link_libraries (editor model view)

add_executable (shape_editor main.cpp)
target_link_libraries (shape_editor editor Qt4::QtGui)
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")

