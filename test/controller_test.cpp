#include <gtest/gtest.h>
#include "../controller_codegenTest.h"

class ControllerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

// Test to verify that the controller can be initialized
TEST_F(ControllerTest, CanBeInitialized) {
    // Create an instance of the controller
    controller_codegenTest controller;
    
    // Initialize the controller
    controller.initialize();
    
    // Verify that the controller was initialized successfully
    // Since initialize() doesn't return a value, we're just checking that it doesn't crash
    SUCCEED();
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
