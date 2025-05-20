cmake_minimum_required(VERSION 3.12)
project(PID_Controller)

# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT controller_codegenTest)

# Enable testing for the entire project
enable_testing()

# Define source directory path
get_filename_component(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR} ABSOLUTE)

# Add the source directory (uses existing CMakeLists.txt there)
add_subdirectory(src)

# Add the test directory
add_subdirectory(test)

# Messages for the build process
message(STATUS "Project setup complete")
message(STATUS "Run 'make' to build the project")
message(STATUS "Run 'ctest' to execute the tests")
