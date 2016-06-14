#include "ofApp.h"
#include "ofxSatellite.h"


ofxSatellite::ofxSatellite() {
    
    
}

void ofxSatellite::inits(float phase_) {
    

    phase = phase_;
    mark = ofRandom(0.0, 2 * PI);
    
}


void ofxSatellite::draw() {
    
    //ofSetColor(255, 255, 255, 255);
    
        for(int theta = 121; theta < ofGetWidth() - 120; theta++){
        
        ofSetColor(yellow, 64);

        float y = 420 + sin( 2.0 * PI / ofGetWidth() * theta + phase) * amplitude;
        ofDrawEllipse(theta, y, 3, 3);
        
            int satPosition = (int)ofMap(fmod(mark, 2.0* PI), 0, 2 * PI, 121, ofGetWidth() - 120);
            if(theta == satPosition) { for(int r = 24; r > 3; r--){ ofSetColor(255, ofMap(r, 24, 3, 0.5, 64)); ofDrawEllipse(theta, y, r, r); } }
    }
    

    // full circle / fps / 90 min in seconds
    mark += 2 * PI / 30.0 / 5400.0;
    
}