#pragma once

#include "ofMain.h"
#include "ofApp.h"

class ofxNoisePlot {
    
public:
    
    ofxNoisePlot();
    void inits(ofVec3f position_, int width_, int height_, float mouseX_);
    void update(float mouseX_);
    void draw();

    ofFbo* sprite;
    
    ofVec3f position;
    int width, height;
    
    float mouseX;
    
    vector<float> values;
    
     ofColor green = ofColor(139, 176, 10, 192);
    
};
