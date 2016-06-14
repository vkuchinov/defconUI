#pragma once

#include "ofMain.h"

class ofxCountdown {
    
public:
    
    ofxCountdown();
    void inits(ofVec3f position_, float width_, float height_);
    void setZeroPoint();
    void update();
    void stop();
    int getMinutes();
    int getSeconds();
    int getTimeLeftInSeconds();
    int getMillis();
    string getTimer();
    void draw(int red_);
    
    long zeroPoint;
    
    bool ACTIVE  = true;
    //59 min 20 sec
    //voice starts at 59:09

    const int COUNTDOWN = 3550;
    long startTime;
    
    ofVec3f position;
    float width, height;
    
    ofColor currentColor;
    ofColor green = ofColor(38, 170, 92);
    ofColor yellow = ofColor(255, 206, 5);
    ofColor red = ofColor(204, 52, 71);
    
    int typefaceResolution = 72;
    ofTrueTypeFont  firaRegular;

    ofSoundPlayer  voiceMessage;
    
    struct  Milestone { int id; int time; bool passed; string url; };
  
    Milestone events [12] { { 0, 3599, true, "none" },
                           { 1, 3549, false, "mp3s/59min.mp3"},
                           { 2, 3005, false, "mp3s/50min.mp3"},
                           { 3, 2405, false, "mp3s/40min.mp3"},
                           { 4, 1805, false, "mp3s/30min.mp3"},
                           { 5, 1205, false, "mp3s/20min.mp3"},
                           { 6,  605, false, "mp3s/10min.mp3"},
                           { 7,  305, false, "mp3s/5min.mp3"},
                           { 8,  60, false, "mp3s/alert.mp3"},
                           { 9,  30, false, "mp3s/alert.mp3"},
                           { 10, 20, false, "mp3s/alert.mp3"},
                           { 11, 15, false, "mp3s/defeat.mp3"}
                           };
    
   };



