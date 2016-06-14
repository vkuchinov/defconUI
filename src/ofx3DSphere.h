#pragma once

#include "ofMain.h"

class ofx3DSphere {
    
public:
    
    ofx3DSphere();
    void inits(ofVec3f position_, int dimensions_);
    void update();
    void draw();
    void rotateByX(int i_, int j_, float radians_);
    void rotateByY(int i_, int j_, float radians_);
    void rotateByZ(int i_, int j_, float radians_);
    
    int M = 16;
    int N = 16;
    float radius;
    
    ofFbo* sprite;

    //squared
    int dimensions;
    ofVec3f position;
    
    float theta, phi;
    ofVec3f points[32][32];

};
