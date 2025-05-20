find_package(GTest REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${GTEST_INCLUDE_DIRS}
)

add_library(controller_test_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/controller_codegenTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/controller_codegenTest_data.cpp
)

target_compile_definitions(controller_lib PRIVATE -DMODEL=controller_codegenTest
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

add_executable(controller_test controller_test.cpp)

target_link_libraries(controller_test
    controller_lib
    ${GTEST_LIBRARIES}
    pthread
)

add_test(NAME controller_test COMMAND controller_test) 

