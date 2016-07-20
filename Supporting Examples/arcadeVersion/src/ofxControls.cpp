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

    if(joystick.getAxisNum() == 0){ lastJoystickValues.x = joystick.getAxisValue(); }
    if(joystick.getAxisNum() == 1){ lastJoystickValues.y = joystick.getAxisValue(); }

    millisA = ofGetElapsedTimeMillis();
    millisB = ofGetElapsedTimeMillis();

    //GPIO
    gpio18.setup("18"); gpio18.export_gpio(); gpio18.setdir_gpio("in");
	gpio23.setup("23"); gpio23.export_gpio(); gpio23.setdir_gpio("in");
	gpio24.setup("24"); gpio24.export_gpio(); gpio24.setdir_gpio("in");

    //arcade joystick
    gpio5.setup("5"); gpio5.export_gpio(); gpio5.setdir_gpio("in");
    gpio6.setup("6"); gpio6.export_gpio(); gpio6.setdir_gpio("in");
    gpio13.setup("13"); gpio13.export_gpio(); gpio13.setdir_gpio("in");
    gpio19.setup("19"); gpio19.export_gpio(); gpio19.setdir_gpio("in");
    gpio26.setup("26"); gpio26.export_gpio(); gpio26.setdir_gpio("in");

}


void ofxControls::update() {

	//joystick

    gpio5.getval_gpio(state5);
    gpio6.getval_gpio(state6);
    gpio13.getval_gpio(state13);
    gpio19.getval_gpio(state19);
    gpio26.getval_gpio(state26);

    xy = 0;

    if(state5 == "0" && pause5 < 0) { xy = -1; pause5 = debouncingLimit; if(activeKey.x > 0) activeKey.x--; }
    if(state6 == "0" && pause6 < 0) { xy = 1; pause6 = debouncingLimit; if(activeKey.x < 11) activeKey.x++; }
    if(state19 == "0" && pause19 < 0) { xy = 2; pause19 = debouncingLimit; if(activeKey.y > 0) activeKey.y--;}
    if(state26 == "0" && pause26 < 0) { xy = -2; pause26 = debouncingLimit; if(activeKey.y < 2) activeKey.y++;}

    if(state13 == "0" && pause13 < 0) { active13 = true; pause13 = debouncingLimit; } else { active13 = false; }

    pause5--; pause6--; pause13--; pause19--; pause26--;

	if(joystick.getButtonNum() == 0 && joystick.getButtonValue() == 1 && pauseJoystick < 0) { joystickButton = true; pauseJoystick = 10; }

	ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
        //app->stopCountdown();

	//GPIO
	gpio18.getval_gpio(state18);
	gpio23.getval_gpio(state23);
	gpio24.getval_gpio(state24);

	if(state18 == "0" && pause18 < 0) { active18 = true; }
	if(state23 == "0") { active23 = true; } else { active23 = false; }
	if(state24 == "0" && pause24 < 0) { active24 = true; pause24 = 10; } else { active24 = false; }

	pauseJoystick--; pause18--; pause24--;


        //corrections
        if(!app->passwordBox() && activeKey.y == 0 && activeKey.x == 11) { activeKey.y = 0; activeKey.x = 10; }
        if(activeKey.y == 1 && activeKey.x == 11) { activeKey.y = 1; activeKey.x = 10; }
        if(activeKey.y == 2 && activeKey.x == 10 ) { if(activeKey.x > lastKey.x) { activeKey.x = 11; } else { activeKey.x = 9; } }

       //if(joystick.getButtonNum() == 0 && joystick.getButtonValue() == 1 && (ofGetElapsedTimeMillis() - millisB) > pauseButton) { button = true; millisB = ofGetElapsedTimeMillis(); } else { button = false; }

       lastKey = activeKey;

}

void ofxControls::debounce(){

    //joystickDebouncing = debounceLimit;

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
