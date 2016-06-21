#include "ofApp.h"
#include "ofxControls.h"

/*
 
JOYSTICK:
 
X: -32767 > 32767
Y: -32767 > 32767
 
on screen limits:
 
x: 440 > 1480  px
y: 654 > 960 px
 
 
GPIO:
 
GPIO18: init button (for administrator)
GPIO23: reserved for key
GPIO24: enter button
 
*/

void ofxControls::inits() {
    
	//joystick
	joystick.setup("/dev/input/js0");
	x = (int)(440 + (1480 - 440 ) / 2); y = (int)(654 + (960 - 654) / 2);
	minX = 440; maxX =1480; minY = 654; maxY = 960;
	ofLog()<<"original joystick X is";
	ofLog()<<x;

    //joystick debugging
    //ofLog()<<"original joystick Y is";
    //ofLog()<<y;

    //GPIO
    gpio18.setup("18"); gpio18.export_gpio(); gpio18.setdir_gpio("in");
	gpio23.setup("23"); gpio23.export_gpio(); gpio23.setdir_gpio("in");
	gpio24.setup("24"); gpio24.export_gpio(); gpio24.setdir_gpio("in");

}


void ofxControls::update() {

	//joystick

    if(joystickDebouncing < 0){

	if(joystick.getAxisNum() == 0){ x += joystick.getAxisValue()*0.001;
	if(x < minX) x = minX;
	if(x > maxX) x = maxX;
	jX = ofMap(joystick.getAxisValue(), -32767, 32767, 0, ofGetWidth());
	}
	if(joystick.getAxisNum() == 1){ y += joystick.getAxisValue()*0.001;  
	if(y < minY) y = minY;
	if(y > maxY) y = maxY;
	jY = ofMap(joystick.getAxisValue(), -32767, 32767, 0, ofGetHeight());
	}

    }

	if(joystick.getButtonNum() == 0 && joystick.getButtonValue() == 1 && pauseJoystick < 0) { joystickButton = true; pauseJoystick = 10; }

	//ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
    //app->stopCountdown();

	//GPIO
	gpio18.getval_gpio(state18);
	gpio23.getval_gpio(state23);
	gpio24.getval_gpio(state24);

	if(state18 == "0" && pause18 < 0) { active18 = true; }
	if(state23 == "0") { active23 = true; } else { active23 = false; }
	if(state24 == "0" && pause24 < 0) { active24 = true; pause24 = 10; } else { active24 = false; }

	pauseJoystick--; pause18--; pause24--;

    joystickDebouncing--;

}

void ofxControls::debounce(){

    joystickDebouncing = debounceLimit;

}

ofVec2f ofxControls::getJoystickPosition(){

	return ofVec2f(x, y);
}

bool ofxControls::getJoystickButtonState(){

	if(pauseJoystick > 0) { return true; }
	return false;

}

bool ofxControls::getAdminButtonState(){

	if(pause18 > 0) { return true; } 
	return false;

}

bool ofxControls::getKeyState(){

	if(pause23 > 0) { return true; }
	return false;

}

bool ofxControls::getEnterButtonState(){

	return active24;

}

void ofxControls::setEnterButtonToInactive(){

	pause24 = 0;
        active24 = false;
}
