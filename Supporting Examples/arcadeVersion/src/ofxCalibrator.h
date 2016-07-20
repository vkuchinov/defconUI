#pragma once

#include "ofMain.h"

class ofxCalibrator {
    
public:
    
    ofxCalibrator();
    void inits(ofVec3f position_, int min_, int max_);
    void inits(string id_, int min_, int max_);
    void update(float value_);
    void draw();
    
    ofImage scale;
    ofVec3f position;
    
    string index;
    
    int MIN, MAX;
    
    ofColor green = ofColor(38, 170, 92);
    
    float value;
    
};
