#include "ofApp.h"
#include "ofxControls.h"

void ofxControls::inits() {

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
    if(state6 == "0" && pause6 < 0) { xy = 1; pause6 = debouncingLimit; if(activeKey.x < 10) activeKey.x++; }
    if(state19 == "0" && pause19 < 0) { xy = 2; pause19 = debouncingLimit; if(activeKey.y > 0) activeKey.y--;}
    if(state26 == "0" && pause26 < 0) { xy = -2; pause26 = debouncingLimit; if(activeKey.y < 2) activeKey.y++;}

    if(state13 == "0" && pause13 < 0) { active13 = true; pause13 = debouncingLimit; } else { active13 = false; }

    pause5--; pause6--; pause13--; pause19--; pause26--;
      
}
