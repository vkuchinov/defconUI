#include "ofApp.h"
#include "ofxKeyboard.h"

ofxKeyboard::ofxKeyboard() {
    
    
}

void ofxKeyboard::inits() {
    
    
}


void ofxKeyboard::update() {
    
    
}

void ofxKeyboard::draw(ofVec2f key_, bool active_) {
    
    
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){

        if(key_ == ofVec2f(x, y)) { if(active_) { ofSetColor(0, 255, 0);} else { ofSetColor(255, 0, 0); }} else { ofSetColor(128, 128, 128); }

        ofDrawRectangle(ofGetWidth()/2 - 330 + 60*x, ofGetHeight()/2 - 90 + 60*y, 58, 58);
    
        }
    }
 
    
}

