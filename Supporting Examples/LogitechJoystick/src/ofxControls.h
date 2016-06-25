#pragma once

#include "ofMain.h"
#include "ofxJoystick.h"

class ofxControls {
    
public:
    
    void inits();
    void update();

    long millisA;
    long millisB;

    int xy = 0; //0:center, -1: west, 1:east, -2: south, 2: north

    ofVec2f activeKey = ofVec2f(6, 1);

    ofxJoystick joystick;

    ofVec2f lastJoystickValues;
    ofVec2f joystickValues;

    bool button;
    int pauseButton = 500;
    int pauseAxes = 500;
    
};
