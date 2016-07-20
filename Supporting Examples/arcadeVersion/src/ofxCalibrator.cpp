#include "ofxCalibrator.h"

ofxCalibrator::ofxCalibrator() {

    scale.load("assets/calibrationScale.png");
    
}

void ofxCalibrator::inits(ofVec3f position_, int min_, int max_) {
    
    
        MIN = min_; MAX = max_;
        position = position_;
    
}

void ofxCalibrator::inits(string id_, int min_, int max_) {
    
    MIN = min_; MAX = max_;
    index = id_;
    
}


void ofxCalibrator::update(float value_) {
    

    if(index == "X"){ value = ofMap(value_, 0, 12, 0, 1920); } else { value = ofMap(value_, 0, 2, 0, 1080); }
    
}

void ofxCalibrator::draw() {
 
      //ofSetColor(255, 255, 255, 255);
  
      int pos = 0;
    
      if(index == "X"){
        
        int HALF = (int)abs(ofGetWidth()/2.0 - value);
        if(abs(value - ofGetWidth()/2.0) < 0.6) { pos = 8; }
        else if(value < ofGetWidth()/2.0){ pos = (int)ofMap(HALF, 0, ofGetWidth()/2.0, 0, 7); }
        else { pos = (int)ofMap(HALF, 0, ofGetWidth()/2.0, 9, 16); }
        
        scale.drawSubsection(64, 0, 32, 1080, pos * 32, 0);
          
      }else{
          
        int HALF = (int)abs(ofGetHeight()/2.0 - value);
        if(abs(value - ofGetHeight()/2.0) < 0.6) { pos = 8; }
        else if(value < ofGetHeight()/2.0) { pos = ofMap(HALF, 0, ofGetHeight()/2.0, 0, 7); }
        else { pos = ofMap(HALF, 0, ofGetHeight()/2.0, 9, 16); }
          
        scale.drawSubsection(1824, 0, 32, 1080, pos * 32, 0);
          
      }
    
}
