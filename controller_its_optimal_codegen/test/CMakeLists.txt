cmake_minimum_required(VERSION 3.12)
project(controller_codegenTest_test)

# Include GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Get source directory path
get_filename_component(PARENT_DIR .. ABSOLUTE)

# Include parent directory for controller headers
include_directories(${PARENT_DIR})

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

include_directories(
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert
)

# Add preprocessor definitions needed for the controller
add_definitions(
    -DMODEL=controller_codegenTest
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
    -DMT=0
)

# Create test executable
add_executable(controller_test
    controller_test.cpp
    ${PARENT_DIR}/controller_codegenTest.cpp
    ${PARENT_DIR}/controller_codegenTest_data.cpp
)

# Link against gtest and pthread
target_link_libraries(controller_test ${GTEST_LIBRARIES} pthread)

# Specify language features required
target_compile_features(controller_test PUBLIC cxx_std_11) 