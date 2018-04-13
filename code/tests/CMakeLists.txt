# tests/CMakeLists.txt

file (GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

message ("-- ${CMAKE_CURRENT_SOURCE_DIR} -- ${TEST_SRCS}")

# Building a test for each test src.
foreach (TEST_FILE ${TEST_SRCS})
  string (REPLACE ".cpp" "" TEST_NAME ${TEST_FILE})
  add_executable (${TEST_NAME} ${TEST_FILE})
  target_link_libraries (${TEST_NAME} editor cppunit)
  add_test (${TEST_NAME} ${TEST_NAME} ${TEST_NAME})
endforeach (TEST_FILE ${TEST_SRCS})
