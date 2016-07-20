#include "ofxVerticalGraph.h"


void ofxVerticalGraph::inits(ofVec3f position_, int width_, int height_) {
    
    
    position = position_;
    width = width_;
    height = height_;
    
    for(int v = 0; v < COLUMNS; v++){
        
        values.push_back(ofNoise(ofGetElapsedTimeMillis(), v));
    }

    sprite = new ofFbo();
    sprite->allocate(width, height, GL_RGBA );
    
}


void ofxVerticalGraph::update(int frames_) {
    
    if(frames_ % 2 == 0){
        values.erase(values.begin());
        values.push_back(ofNoise(ofGetElapsedTimeMillis(), 0));
    }

    updated = true;

}

void ofxVerticalGraph::draw() {
    

    if(updated) { 

    sprite->begin();
    ofClear(255, 0);

    ofSetColor(green, 255);   

    for(int c = 0; c < COLUMNS; c++){

        float columnHeight = ofMap(values[c], 0.0, 1.0, -4.0, -68.0);
        ofDrawRectangle(c * 12.55, height, 9, columnHeight);
        ofDrawRectangle(c * 12.55, height + columnHeight - 3, 9, -6.0);

    }

    sprite->end();
    updated = false;
    }

    ofSetColor(green, 255);

    sprite->draw(position.x, position.y);
    
}
