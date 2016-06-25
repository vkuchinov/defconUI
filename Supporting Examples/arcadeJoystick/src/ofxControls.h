#pragma once

#include "ofMain.h"
#include "ofxGPIO.h"

class ofxControls {
    
public:
    
    void inits();
    void update();

    int debouncingLimit = 12;

    int xy = 0; //0:center, -1: west, 1:east, -2: south, 2: north

    ofVec2f activeKey = ofVec2f(6, 1);

    GPIO gpio5;	//west
    string state5;
    bool active5 = false;
    int pause5 = -1;

    GPIO gpio6;	//east
    string state6;
    bool active6 = false;
    int pause6 = -1;

    GPIO gpio13;	//push-button
    string state13;
    bool active13 = false;
    int pause13 = -1;

    GPIO gpio19;	//north
    string state19;
    bool active19 = false;
    int pause19 = -1;

    GPIO gpio26;	//south
    string state26;
    bool active126 = false;
    int pause26 = -1;
    
};
