#include "ofApp.h"
#include "ofxCountdown.h"

ofxCountdown::ofxCountdown() {
    
    startTime = (ofGetElapsedTimeMillis() - zeroPoint) / 1000;
    
}

void ofxCountdown::inits(ofVec3f position_, float width_, float height_) {
    
    position = position_;
    width = width_;
    height = height_;
    
    //typefaces
    ofTrueTypeFont::setGlobalDpi(typefaceResolution);
    firaRegular.load("typefaces/FiraMonoRegular.ttf", 132, true, true);
    
    currentColor = green;
    
}


void ofxCountdown::setZeroPoint() { zeroPoint = ofGetElapsedTimeMillis(); }

void ofxCountdown::update() {
    
    if(ACTIVE){


    for(int v = 1; v < 12; v++){

        if(getTimeLeftInSeconds() < events[v].time && !events[v].passed && events[v - 1].passed){
            
            events[v].passed = true;
            voiceMessage.load(events[v].url);
            voiceMessage.play();
            
        }
        
    }
    
    if(getTimeLeftInSeconds() < 0) {
     
        
        ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
        stop();
        app->youAreDefeated();
        
    }

    }
    
}

void ofxCountdown::stop() {
   
    ACTIVE = false;
}


void ofxCountdown::draw(int red_) {

    //ofSetColor(255, 255, 255, 255);
   
    
    int time = COUNTDOWN - (ofGetElapsedTimeMillis() - zeroPoint)/1000;
    
    if(time > 0){
    
    
        if(time > 600) {
            
            currentColor.r = ofLerp((float)green.r, (float)yellow.r, ofMap(time, COUNTDOWN, 600, 0.0, 1.0));
            currentColor.g = ofLerp((float)green.g, (float)yellow.g, ofMap(time, COUNTDOWN, 600, 0.0, 1.0));
            currentColor.b = ofLerp((float)green.b, (float)yellow.b, ofMap(time, COUNTDOWN, 600, 0.0, 1.0));
            currentColor.r += red_;

        }
        else{
            
            currentColor.r = ofLerp((float)yellow.r, (float)red.r, ofMap(time, 600, 0, 0.0, 1.0));
            currentColor.g = ofLerp((float)yellow.g, (float)red.g, ofMap(time, 600, 0, 0.0, 1.0));
            currentColor.b = ofLerp((float)yellow.b, (float)red.b, ofMap(time, 600, 0, 0.0, 1.0));
	    currentColor.r += red_;

        }
    
    ofSetColor(currentColor);
    
    firaRegular.drawString(getTimer(), position.x + 50, position.y + 100);
    
    }
    else{
        
        ofSetColor(red);
        firaRegular.drawString("00:00:00", position.x + 50, position.y + 100);
        
    }
}


int ofxCountdown::getMinutes() {
    
    return (int)((COUNTDOWN - (ofGetElapsedTimeMillis() - zeroPoint) / 1000 - startTime) / 60);
    
}

int ofxCountdown::getSeconds() {
    
    return (int)((COUNTDOWN - (ofGetElapsedTimeMillis() - zeroPoint) / 1000 - startTime) % 60);
    
}

int ofxCountdown::getMillis() {
    
    return (int)(ofRandom(99));
    
}

int ofxCountdown::getTimeLeftInSeconds(){
    
    return getMinutes() * 60 + getSeconds();
}

string ofxCountdown::getTimer() {
    
    string mins = ofToString(getMinutes());
    if(mins.length() == 1) mins = "0" + mins;
    
    string secs = ofToString(getSeconds());
    if(secs.length() == 1) secs = "0" + secs;
    
    string mills = ofToString(getMillis());
    if(mills.length() == 1) mills = "0" + mills;
    
    return mins + ":" + secs + ":" + mills;
    
}
