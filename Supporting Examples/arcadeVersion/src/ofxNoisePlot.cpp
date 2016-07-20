
#include "ofApp.h"
#include "ofxNoisePlot.h"

ofxNoisePlot::ofxNoisePlot() {
    
}

void ofxNoisePlot::inits(ofVec3f position_, int width_, int height_, float mouseX_) {
    
    position = position_;
    width = width_;
    height = height_;
    
    mouseX = mouseX_;
    
    for(int v = 0; v < width; v++){
        values.push_back(ofNoise(ofGetElapsedTimeMillis() * mouseX, v));
    }
    
    sprite = new ofFbo();
    sprite->allocate(width, height, GL_RGBA );
}


void ofxNoisePlot::update(float mouseX_) {
    
    mouseX = mouseX_;
    values.erase(values.begin());
    values.push_back(ofNoise(ofGetElapsedTimeMillis() * mouseX, 0));

    //sprite->begin();
    //ofEnableAlphaBlending();
    //ofClear(255, 255, 255, 0);

    //sprite->end();
    //ofDisableAlphaBlending();

    updated = true;
    
}

void ofxNoisePlot::draw() {


    if(updated) { 


    //sprite->clear();

    sprite->begin();
    ofClear(255, 0);

    ofSetColor(green, 255);   
    for(int v = 0; v < values.size(); v++){

    ofDrawRectangle(v, height/2, 1,  values[v] * 16.0);
    ofDrawRectangle(v, height/2, 1, -values[v] * 16.0);

    }

    sprite->end();
    updated = false;
    }
    ofSetColor(green, 255);

   //ofDrawRectangle(200, 174, width, height);

   
   sprite->draw(position.x, position.y - height/2);

}
