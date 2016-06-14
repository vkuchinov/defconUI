#pragma once

#include "ofMain.h"

class ofxSprite {
    
public:
    
    ofxSprite();
    void inits(int id_, float x_, float y_, float xt_, float yt_);
    void update(int frameCount_);
    void draw();
    void drawCurve(ofVec2f a_, ofVec2f b_);
    
    int ID = 0; //by default US nuclear silo
    bool MORTAL = false;
    bool LOOP = false;
    bool DEAD = false;
    ofVec2f target;
    
    string URLs [4] = {"assets/mineUS.png", "assets/subUS.png", "assets/mineUSSR.png", "assets/subUSSR.png"};
    
    //keyframes
    int keyframes [4][3] = {{0, 21, 27}, {0, 12, 22}, {0, 21, 27}, {0, 12, 22}};
    
    //width, height, frames
    ofVec3f params [4] = {ofVec3f(23, 24, 23), ofVec3f(20, 24, 22), ofVec3f(23, 24, 23), ofVec3f(20, 24, 22)};
    
    ofImage sprite;
    
    int count = 0;
    int frame = 0;
    
    int skip = 3;
    
    ofVec2f position;
    
    int lifetime;
    
};