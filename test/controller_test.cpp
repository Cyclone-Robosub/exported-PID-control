#include <gtest/gtest.h>
#include "PID_Controller.h"

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
    PID_Controller controller;
    controller.initialize();
    SUCCEED();
}

// Test 2: Check that input can be set          
TEST_F(ControllerTest, InputCanBeSet) 
{
    PID_Controller controller;
    PID_Controller::ExtU_PID_Controller_T extU;
    extU.state_error_e[0] = 0.0;
    extU.state_error_e[1] = 0.0;
    extU.state_error_e[2] = 0.0;
    extU.state_error_e[3] = 0.0;
    extU.state_error_e[4] = 0.0;
    extU.state_error_e[5] = 0.0;
    extU.DCMbe[0] = 0.0;
    extU.DCMbe[1] = 0.0;
    extU.DCMbe[2] = 0.0;
    extU.DCMbe[3] = 0.0;
    extU.DCMbe[4] = 0.0;
    extU.DCMbe[5] = 0.0;
    

      controller.step();
}   

// Test 3: Check that when all errors are zero, all outputs equal 1500
TEST_F(ControllerTest, ZeroErrorProduces1500Outputs) 
{
    PID_Controller controller;
    controller.initialize();
    PID_Controller::ExtU_PID_Controller_T extU;
    PID_Controller::ExtY_PID_Controller_T extY;
    for (int i = 0; i < 6; i++) 
    {
        extU.state_error_e[i] = 0.0;
    }
    controller.setExternalInputs(&extU);
    controller.step();
    extY = controller.getExternalOutputs();

    for (int i = 0; i < 8; i++) 
    {
        EXPECT_DOUBLE_EQ(1500.0, extY.PWM[i])
            << "Output " << i << " should be 1500 when all errors are zero";
    }
}

// Test 4: Check that if there is err, not all inputs will equal 1500
TEST_F(ControllerTest, ErrorProducesNon1500Outputs)
{
    
    PID_Controller controller;
    controller.initialize();
    PID_Controller::ExtU_PID_Controller_T extU;
    for (int i = 0; i < 6; i++) {
        extU.state_error_e[i] = 1.0;
    }
    controller.setExternalInputs(&extU);

    controller.step();

    bool non1500 = false;   


    PID_Controller::ExtY_PID_Controller_T extY;
    extY = controller.getExternalOutputs();
    for (int i = 0; i < 8; i++) 
    {
        if (extY.PWM[i] != 1500.0) { 
            non1500 = true;
        }
    }   
    EXPECT_TRUE(non1500);
}

    

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
