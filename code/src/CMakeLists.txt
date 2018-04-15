# src/CMakeLists.txt

add_subdirectory (shape)
add_subdirectory (widget)

add_library (editor Main.cpp ${MOC_OUTFILES})
target_link_libraries (editor shape widget)

add_executable (shape_editor Main.cpp)
target_link_libraries (shape_editor editor Qt4::QtGui Qt4::QtCore)
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
