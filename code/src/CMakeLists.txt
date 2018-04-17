# src/CMakeLists.txt

add_subdirectory (shape)
add_subdirectory (widget)

add_library (editor Main.cpp ${MOC_OUTFILES})
target_link_libraries (editor shape widget)

#Boost
find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
add_executable (shape_editor Main.cpp)
target_link_libraries (shape_editor editor Qt4::QtGui Qt4::QtCore ${Boost_LIBRARIES} )
set_target_properties (shape_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/bin")
