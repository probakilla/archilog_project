#src / CMakeLists.txt

file (GLOB SHAPE_SRCS shape/*.cpp)
file (GLOB CMD_SRCS command/*.cpp)
file (GLOB WIDGET_SRCS widget/*.cpp)

add_library (editor ${MOC_OUTFILES} ${SHAPE_SRCS} ${CMD_SRCS} ${WIDGET_SRCS})

# To use the macro Q_OBJECT
set (
  INCLUDE_WIDGET_FILES
  ${WIDGET_INC_DIR}/QtDisplay.hpp
  ${WIDGET_INC_DIR}/QtRectangle.hpp)
qt4_wrap_cpp(INCLUDE_WIDGET_FILES_MOC ${INCLUDE_WIDGET_FILES})

#Boost
find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )
add_executable (shape_editor Main.cpp ${INCLUDE_WIDGET_FILES_MOC} )
target_link_libraries (shape_editor editor Qt4::QtGui Qt4::QtCore ${Boost_LIBRARIES} )
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
