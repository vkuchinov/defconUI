/*
 
Most meteorological satellites orbit the Earth 15 to 16 times per day. 
 
24 * 60 = 1 440 minutes 15x: 96 min - 16x: 90 min.

Earth-synchronous or geosynchronous satellites are placed into orbit so 
that their period of rotation exactly matches the Earth's rotation.
They take 24 hours to make one rotation.

*/

#pragma once

#include "ofMain.h"

class ofxSatellite {
    
public:
    
    ofxSatellite();
    void inits(float phase_);
    void update();
    void draw();
    
    const int RESOLUTION = 180;
    
    ofColor green = ofColor(38, 170, 92);
    ofColor yellow = ofColor(255, 206, 5);
    ofColor red = ofColor(204, 52, 71);
    
    float amplitude = 320.0;
    float phase = 0.0;
    
    float mark;

};