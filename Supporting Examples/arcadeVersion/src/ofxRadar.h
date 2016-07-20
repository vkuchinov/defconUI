#pragma once

#include "ofMain.h"

class ofxRadar {
    
public:
    
    void inits(ofVec2f positions_, int dimensions);
    void update();
    void draw();

    ofFbo* sprite;

    ofVec2f position;
    int dimensions;
    
    float theta = 0.0;
    
    struct  Target { int id; float size; int marked; int lifetime; ofVec2f position; };
    vector<Target> targets;

    ofImage highlight;

    ofColor green = ofColor(38, 170, 92);

    bool updated = true;

};
