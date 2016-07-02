#include "ofApp.h"
#include "ofxRadar.h"


void ofxRadar::inits(ofVec2f position_, int dimensions_) {
    
    position = position_;
    dimensions = dimensions_;
    
    for(int t = 0; t < (int)ofRandom(5, 9); t++){
        
        //Target { int id; float size; int lifetime; ofVec2f position; };
        float a = ofRandom(0.0, 360);
        float r = ofRandom(0.0 , 80.0);
        int l = (int)ofRandom(1024, 5120);

        float x = cos(a) * r;
        float y = sin(a) * r;
        
        Target newTarget = Target{ t, ofRandom(3, 10), 0, l, ofVec2f(x, y) };
        targets.push_back(newTarget);
    }

    highlight.load("assets/radarHighlight.png");
    
    sprite = new ofFbo();
    sprite->allocate(300, 300, GL_RGBA );
    
}

void ofxRadar::update() {

    if(targets.size() < 4) {

        float a = ofRandom(0.0, 360);
        float r = ofRandom(0.0 , 80.0);
        int l = (int)ofRandom(1024, 5120);

        float x = cos(a) * r;
        float y = sin(a) * r;

        Target newTarget = Target{ 0, ofRandom(3, 10), 0, l, ofVec2f(x, y) };
        targets.push_back(newTarget);

    }

    updated = true;

}

void ofxRadar::draw() {

    ofSetColor(255, 255, 255, 255);

    if(updated) { 

    sprite->begin();
    ofClear(255, 0);

    ofSetColor(0, 0, 0, 64);
    ofPushMatrix();
    ofSetCircleResolution(128);
    ofTranslate(150, 150);
    //ofDrawEllipse(0, 0, dimensions, dimensions);
    ofSetColor(16,41, 19, 192);
    //ofDrawEllipse(0, 0, dimensions - 8, dimensions - 8);
    
    ofPushMatrix();
    
    for(int t = 0; t < targets.size(); t++){

        float angle = atan2(targets[t].position.y,  targets[t].position.x) * 180 / PI;
        if(abs(angle - fmod(theta, 360.0)) < 3.0) targets[t].marked = 128;

        ofSetColor(255, 255, 255, ofMap(targets[t].marked, 0, 128, 0, 192));
        ofDrawEllipse(targets[t].position.x, targets[t].position.y, targets[t].size, targets[t].size);
        
        if(targets[t].marked > 0) targets[t].marked -= 2;
        targets[t].lifetime--;
        if(targets[t].lifetime < 0) targets.erase(targets.begin() + t);
        
    }
    
    ofTranslate(0, 0);
    ofRotate(180.0 + theta);

    ofSetColor(255, 255, 255,255);
    //ofDrawRectangle(-94, -94, 188, 188);
    highlight.draw(-94, -94);
    //for(int l = 0; l < 64; l++){
    //ofRotate(-1);
    //ofSetColor(255, 255, 255, ofMap(l, 0, 64, 92, 0));
    //ofSetLineWidth(2.0);
    //ofDrawLine(0, 0, 94, 0);
    //}
    
    ofPopMatrix();
    
    //ofSetLineWidth(1.0);
    //ofSetColor(124, 144, 24, 128);
    //ofDrawLine(94, 0, 30, 0);
    //ofDrawLine(-94, 0, -30, 0);
    //ofDrawLine(0, 94, 0, 30);
    //ofDrawLine(0, -94, 0, -30);
    
    ofNoFill();
    //ofDrawEllipse(0, 0, 94, 94);
    //ofDrawEllipse(0, 0, 180, 180);
    
    ofPopMatrix();
    
    theta += 4.0;

    sprite->end();

    updated = false;

    }

    sprite->draw(position.x - 150, position.y - 150);

    
}
