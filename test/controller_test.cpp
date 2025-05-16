#include <gtest/gtest.h>
#include "../src/controller_codegenTest.h"

class ControllerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

// Test 1: Initialize the controller
TEST_F(ControllerTest, CanBeInitialized) 
{
    controller_codegenTest controller;
    controller.initialize();
    SUCCEED();
}

// Test 2: Check that input can be set          
TEST_F(ControllerTest, InputCanBeSet) 
{
    controller_codegenTest controller;

    controller.rtU.Input[0] = 0.0;
    controller.rtU.Input[1] = 0.0;
    controller.rtU.Input[2] = 0.0;
    controller.rtU.Input[3] = 0.0;
    controller.rtU.Input[4] = 0.0;
    controller.rtU.Input[5] = 0.0;

    controller.step();
}   

// Test 3: Check that when all errors are zero, all outputs equal 1500
TEST_F(ControllerTest, ZeroErrorProduces1500Outputs) 
{
    controller_codegenTest controller;
    controller.initialize();
    
    for (int i = 0; i < 6; i++) 
    {
        controller.rtU.Input[i] = 0.0;
    }
    
    controller.step();
    
    for (int i = 0; i < 8; i++) 
    {
        EXPECT_DOUBLE_EQ(1500.0, controller.rtY.Out1[i])
            << "Output " << i << " should be 1500 when all errors are zero";
    }
}

// Test 4: Check that if there is err, not all inputs will equal 1500
TEST_F(ControllerTest, ErrorProducesNon1500Outputs)
{
    
    controller_codegenTest controller;
    controller.initialize();
    
    for (int i = 0; i < 6; i++) {
        controller.rtU.Input[i] = 1.0;
    }
    
    controller.step();

    bool non1500 = false;    
    for (int i = 0; i < 8; i++) 
    {
        if (controller.rtY.Out1[i] != 1500.0) { 
            non1500 = true;
        }
    }   
    EXPECT_TRUE(non1500);
}

    

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
