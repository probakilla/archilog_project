# src/CMakeLists.txt

file (GLOB SHAPE_SRCS shape/*.cpp)
file (GLOB WIDGET_SRCS widget/*.cpp)

add_library (editor ${MOC_OUTFILES} ${SHAPE_SRCS} ${WIDGET_SRCS})

add_executable (shape_editor Main.cpp)
target_link_libraries (shape_editor editor Qt4::QtGui Qt4::QtCore)
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
