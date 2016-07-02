#pragma once

#include "ofMain.h"

class ofxVerticalGraph {
    
public:
    
    void inits(ofVec3f position_, int width_, int height_);
    void update(int frames_);
    void draw();
    
    int COLUMNS = 16;

    ofFbo* sprite;
    
    ofVec3f position;
    int width, height;
    
    vector<float> values;
    
    ofColor green = ofColor(38, 170, 92);

    bool updated = true;
    
};
