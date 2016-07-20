#pragma once

#include "ofMain.h"
#include "ofxSprite.h"

class ofxMap {
    
public:
    
    void inits();
    void update(int time_, int secondsLeft_);
    void addElement(int time_);
    ofVec4f getRightCoordinates(int id_);
    bool checkDistance(float x_, float y_, float xT_, float yT_);
    void draw();
    
    ofImage mask;
    
    vector<ofxSprite> elements;

    ofVec2f somewhereInRussia;
    
};
