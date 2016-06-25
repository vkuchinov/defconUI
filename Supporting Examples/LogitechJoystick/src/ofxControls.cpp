#include "ofApp.h"
#include "ofxControls.h"

void ofxControls::inits() {

    joystick.setup("/dev/input/js0");
    if (!joystick.isFound()) { ofLog()<<"joystick is not found"; } else { ofLog()<<"joystick found"; }

    if(joystick.getAxisNum() == 0){ lastJoystickValues.x = joystick.getAxisValue(); }
    if(joystick.getAxisNum() == 1){ lastJoystickValues.y = joystick.getAxisValue(); }

    millisA = ofGetElapsedTimeMillis();
    millisB = ofGetElapsedTimeMillis();
}


void ofxControls::update() {


    if(joystick.getAxisNum() == 0){ joystickValues.x = joystick.getAxisValue(); }
    if(joystick.getAxisNum() == 1){ joystickValues.y = joystick.getAxisValue(); }

    if((ofGetElapsedTimeMillis() - millisA) > pauseAxes){

        if(abs(joystickValues.x) > abs(joystickValues.y)){

            //X
            if(abs(joystickValues.x) > 13784){

                if(joystickValues.x < 0 && activeKey.x > 0) { activeKey.x--; }
                if(joystickValues.x > 0 && activeKey.x < 10) { activeKey.x++; }
            }

        }
        else{

            //Y
            if(abs(joystickValues.y) > 13784){

                if(joystickValues.y < 0 && activeKey.y > 0) { activeKey.y--; }
                if(joystickValues.y > 0 && activeKey.y < 2) { activeKey.y++; }

            }

        }

        lastJoystickValues = joystickValues;
        millisA = ofGetElapsedTimeMillis();

    }


    if(joystick.getButtonNum() == 0 && joystick.getButtonValue() == 1 && (ofGetElapsedTimeMillis() - millisB) > pauseButton) { button = true; millisB = ofGetElapsedTimeMillis(); } else { button = false; }

      
}
