#include "ofxHorizontalGraph.h"


void ofxHorizontalGraph::inits(ofVec3f position_, int width_, int height_) {
    
    position = position_;
    width = width_;
    height = height_;
    
    for(int v = 0; v < COLUMNS; v++){
        
        values.push_back(ofNoise(ofGetElapsedTimeMillis(), v));
    }
    
    minValue = 99999999.9;
    maxValue = -999999999;

    sprite = new ofFbo();
    sprite->allocate(width, height, GL_RGB );
    
}

void ofxHorizontalGraph::update(int frames_) {
    
    if(frames_ % 6 == 0){
        values.erase(values.begin());
        values.push_back(ofNoise(ofGetElapsedTimeMillis(), 0));
    }

}

void ofxHorizontalGraph::draw() {
    
    ofSetColor(green, 255);

    ofDrawRectangle(position.x + width, position.y, -8, height);

    for(int c = 0; c < COLUMNS; c++){

        ofDrawRectangle(position.x + width - 16, position.y + c * 13.55, ofMap(values[c], 0.0, 1.0, - 4.0, -144.0), 10);
        //if(values[c] < minValue) minValue = values[c];
        //if(values[c] > maxValue) maxValue = values[c];

    }

}
