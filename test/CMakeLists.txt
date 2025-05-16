find_package(GTest REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${GTEST_INCLUDE_DIRS}
)

add_executable(controller_test controller_test.cpp
    ${CMAKE_SOURCE_DIR}/controller_codegenTest.cpp
    ${CMAKE_SOURCE_DIR}/controller_codegenTest_data.cpp
)

target_link_libraries(controller_test
    ${GTEST_LIBRARIES}
    pthread
)

add_test(NAME controller_test COMMAND controller_test) 
