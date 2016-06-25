#pragma once

#include "ofMain.h"


class ofxKeyboard {
    
public:
    
    ofxKeyboard();
    void inits();
    void update();
    void draw(ofVec2f key_, bool active_);
   
    int rows = 3;
    int cols = 11;

    
};
