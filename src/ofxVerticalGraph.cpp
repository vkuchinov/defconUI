#include "ofxVerticalGraph.h"


void ofxVerticalGraph::inits(ofVec3f position_, int width_, int height_) {
    
    
    position = position_;
    width = width_;
    height = height_;
    
    for(int v = 0; v < COLUMNS; v++){
        
        values.push_back(ofNoise(ofGetElapsedTimeMillis(), v));
    }

    sprite = new ofFbo();
    sprite->allocate(width, height, GL_RGB );
    
}


void ofxVerticalGraph::update(int frames_) {
    
    if(frames_ % 2 == 0){
        values.erase(values.begin());
        values.push_back(ofNoise(ofGetElapsedTimeMillis(), 0));
    }

}

void ofxVerticalGraph::draw() {
    
    ofSetColor(green, 255);

    for(int c = 0; c < COLUMNS; c++){

        float columnHeight = ofMap(values[c], 0.0, 1.0, -4.0, -68.0);
        ofDrawRectangle(position.x + c * 12.55, position.y + height, 9, columnHeight);
        ofDrawRectangle(position.x + c * 12.55, position.y + height + columnHeight - 3, 9, -6.0);

    }


    
}
