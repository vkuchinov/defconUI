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
    
    int satPosition = (int)ofMap(fmod(mark, 2.0* PI), 0, 2 * PI, 121, ofGetWidth() - 120);
    float y = 420 + sin( 2.0 * PI / ofGetWidth() * satPosition + phase) * amplitude;
    ofSetColor(255, 255, 255, 255);
    ofDrawEllipse(satPosition, y, 10, 10);

    // full circle / fps / 90 min in seconds
    mark += 2 * PI / 30.0 / 5400.0;
    
}
