#pragma once

#include "ofMain.h"
#include "ofxGPIO.h"
#include "ofxJoystick.h"

class ofxControls {
    
public:
    
    void inits();
    void update();
    ofVec2f getJoystickPosition();
    int getJoystickAxisX(); //mapped to screen width
    int getJoystickAxisY(); //mapped to screen height
    bool getJoystickButtonState();
    void debounce();

    //GPIO
    bool getAdminButtonState();
    bool getKeyState();
    bool getEnterButtonState();    
    
    long millisA;
    long millisB;

    int xy = 0; //0:center, -1: west, 1:east, -2: south, 2: north

    ofVec2f activeKey = ofVec2f(6, 1);
    ofVec2f lastKey = activeKey;

    ofxJoystick joystick;

    ofVec2f lastJoystickValues;
    ofVec2f joystickValues;

    bool button;
    int pauseButton = 500;
    int pauseAxes = 500;

    void setEnterButtonToInactive();

    int debounceLimit = 4; //joystick movement debouncing, in frames
    int joystickDebouncing = debounceLimit;
    int joystickPause = 0;
    float joystickSensitivity = 0.001;

    //-1: center, 0:north, 1:west, 2: south, 3:east
    int currentDirection = -1;


    bool joystickButton = false;
    int x, y, minX, maxX, minY, maxY, jX, jY;
    int pauseJoystick = 0;
    
    GPIO gpio18;	//init button
    string state18;
    bool active18 = false;
    int pause18 = -1;	
    GPIO gpio23;	//physical key
    string state23;
    bool active23 = false;
    int pause23 = -1;
    GPIO gpio24;	//enter button
    string state24;
    bool active24 = false;
    int pause24 = -1;


    //arcade joystick

    int debouncingLimit = 4;

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
