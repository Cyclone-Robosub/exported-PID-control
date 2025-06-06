###########################################################################
# CMakeLists.txt generated for component controller_codegenTest
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(controller_codegenTest)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT controller_codegenTest)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR . ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root

# Include MATLAB directories - check for Linux installation paths first
if(EXISTS "/usr/local/MATLAB/R2024a")
    set(MATLAB_ROOT "/usr/local/MATLAB/R2024a" CACHE PATH "")
elseif(EXISTS "/usr/local/MATLAB/R2023b")
    set(MATLAB_ROOT "/usr/local/MATLAB/R2023b" CACHE PATH "")
elseif(EXISTS "/usr/local/MATLAB/R2023a")
    set(MATLAB_ROOT "/usr/local/MATLAB/R2023a" CACHE PATH "")
else()
    set(MATLAB_ROOT C:/Program\ Files/MATLAB/R2024a CACHE PATH "")
endif()

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "controller_codegenTest".
add_executable(controller_codegenTest  ${START_DIR}/controller_codegenTest.cpp
    ${START_DIR}/controller_codegenTest_data.cpp
    ${START_DIR}/ert_main.cpp)

# Set properties for target "controller_codegenTest".
set_target_properties(controller_codegenTest PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")

# Specify language features required for target "controller_codegenTest".
target_compile_features(controller_codegenTest PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target 
# "controller_codegenTest".
target_compile_definitions(controller_codegenTest PRIVATE -DMODEL=controller_codegenTest
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=0
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0)

# Specify include directories for target "controller_codegenTest".
target_include_directories(controller_codegenTest PRIVATE ${START_DIR}
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert)

# Specify library link dependencies for target "controller_codegenTest". 
# CMake generator expressions are used to create a CMakeLists.txt file 
# that supports multiple platforms with differently named system library 
# dependencies.
target_link_libraries(controller_codegenTest PRIVATE $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:controller_codegenTest>;--flat,"
                "true"
        >)
    add_custom_command(TARGET controller_codegenTest
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS controller_codegenTest.dwarf)
endif()


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET controller_codegenTest POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:controller_codegenTest>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(controller_codegenTest)
endif()
# Enable testing and add test subdirectory
enable_testing()

