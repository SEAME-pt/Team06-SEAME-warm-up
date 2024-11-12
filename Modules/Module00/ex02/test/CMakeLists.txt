# Specify the GoogleTest version and repository
include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  PREFIX "${CMAKE_BINARY_DIR}/googletest"
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/googletest-install
)

# Add the executable for the test
add_executable(test_ex02
    ${CMAKE_CURRENT_SOURCE_DIR}/test_ex02.cpp  # Correct path to test_ex02.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/ex02.cpp  # Correct path to ex02.cpp
)

# Include GoogleTest headers
target_include_directories(test_ex02 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    ${CMAKE_BINARY_DIR}/googletest-install/include
)

# Link GoogleTest libraries
target_link_libraries(test_ex02
    ${CMAKE_BINARY_DIR}/googletest-install/lib/libgtest.a
    ${CMAKE_BINARY_DIR}/googletest-install/lib/libgtest_main.a
)

# Add dependencies to ensure Googletest is built before tests
add_dependencies(test_ex02 googletest)

# Register the test with CTest
add_test(NAME test_ex02 COMMAND test_ex02)
