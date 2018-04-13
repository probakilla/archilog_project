# src/CMakeLists.txt

add_subdirectory (shape)
add_subdirectory (view)

add_library (editor Main.cpp ${MOC_OUTFILES})
target_link_libraries (editor shape view)

add_executable (shape_editor Main.cpp)
target_link_libraries (shape_editor editor Qt4::QtGui Qt4::QtCore)
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
