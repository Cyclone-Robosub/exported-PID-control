#include <gtest/gtest.h>
#include "PID_Controller.h"


// fixture not currently being used. Destroy?
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
    extU.controller_mode = 1;
    extU.DFC_error[0] = 2;
    extU.DFC_error[1] = 3;

    for (int i = 0; i < 6; i++) {
        extU.waypoint[i] = 0;
        extU.states[i] = 0;
    }

    controller.setExternalInputs(&extU);
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
        extU.states[i] = 0.0;
        extU.waypoint[i] = 0.0;
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
        extU.states[i] = 0.0;
        extU.waypoint[i] = 1.0;
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

TEST_F(ControllerTest, InitalOutputsForDiaganolUnitErrors){
    std::vector<std::vector<double>> pid_values = 
    {
        {18.568,2.749,30.798,17.247},
        {18.568,2.749,30.798,17.247},
        {18.568,2.749,30.798,17.247},
        {4.773,2.325,2.504,54.54},
        {6.912,3.236,3.625,54.54},
        {6.782,2.479,2.957,114.828}
    };
    PID_Controller controller;
    controller.initialize();
    PID_Controller::ExtU_PID_Controller_T extU;
    for (int i = 0; i < 6; i++) {
        extU.states[i] = 0.0;
        extU.waypoint[i] = 1.0;
    }
    extU.controller_mode = 0.0;
    extU.DFC_error[0] = 0.0;
    extU.DFC_error[1] = 0.0;

    for (int i = 0; i < 4; i++) {
        extU.PIDN_X[i] = pid_values[0][i];
        extU.PIDN_Y[i] = pid_values[1][i];
        extU.PIDN_Z[i] = pid_values[2][i];
        extU.PIDN_roll[i] = pid_values[3][i];
        extU.PIDN_pitch[i] = pid_values[4][i];
        extU.PIDN_yaw[i] = pid_values[5][i];
    }

    int expected_outputs[8] = 
    {
        1792, 1254, 1598, 1212, 1792, 1212, 1791, 1314
    };
    controller.setExternalInputs(&extU);
    controller.step();
    PID_Controller::ExtY_PID_Controller_T extY;
    extY = controller.getExternalOutputs();
    for (int i = 0; i < 8; i++) {
        EXPECT_DOUBLE_EQ(expected_outputs[i], extY.PWM[i]) << 
        "Output " << i << " should be " << expected_outputs[i] << " but is " << extY.PWM[i];
    }
}

    

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
