PID_testing_""_"" = Data created in MATLAB

There are two types of these tests: One solution to the PID controller when we pass in one state error, PID_testing_"" and when we iterate within a feedback look for a small amount of time PID_testing_""_ts

File name Explainer:
_ts = time series version created through PID Feedback loop
_all = state error in each degree of freedom, x,y,z,roll,pitch,yaw
_none = no state error in each degree of freedom, 0,0,0,0,0,0
_roll = state error in ONLY the roll axis, 0,0,0,1,0,0
_pitch = 0,0,0,0,1,0
_yaw = 0,0,0,0,0,1
_X = 1,0,0,0,0,0
_Y = 0,1,0,0,0,0
_Z = 0,0,1,0,0,0
