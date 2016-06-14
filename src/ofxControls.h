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

    //GPIO
    bool getAdminButtonState();
    bool getKeyState();
    bool getEnterButtonState();    
    
    void setEnterButtonToInactive();

    int joystickPause = 0.0;

    ofxJoystick joystick;
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
};