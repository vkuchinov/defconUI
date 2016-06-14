#include "ofApp.h"
#include "ofxSprite.h"


ofxSprite::ofxSprite() {
    
    
}

void ofxSprite::inits(int id_, float x_, float y_, float xt_, float yt_) {
    
    ID = id_;
    
    position = ofVec2f(x_, y_);
    target = ofVec2f(xt_, yt_);
    sprite.load(URLs[ID]);
    
    if(ID == 1 && ID == 3) MORTAL = true;
    
    lifetime = ofRandom(256, 10240);
    
}

void ofxSprite::update(int frameCount_) {
    
    if(lifetime > 0){
    
    if(frameCount_ % skip == 0) count++;
    if(count > keyframes[ID][1] && !LOOP) LOOP = true;
    if(count > keyframes[ID][2]) count = keyframes[ID][1];
    
    if(MORTAL) lifetime--;
    
    }
    
    else{
        
        if(lifetime > -keyframes[ID][1]) { count = keyframes[ID][1] - lifetime;  } else  { DEAD = true; }
    }
    
}


void ofxSprite::draw() {

    //ofSetColor(255, 255, 255, 255);
    
    if(!DEAD){
    //sprite.drawSubsection(position.x, position.y, (int)params[ID].x , (int)params[ID].y, count * (int)params[ID].x, 0, (int)params[ID].x, (int)params[ID].y);
    drawCurve(position, target);
    }

}

void ofxSprite::drawCurve(ofVec2f a_, ofVec2f b_){
    
    ofSetColor(230, 200, 20, 92);
    
    float yy = -200; //ofRandom(0, - 250);
    float xx = 0; //ofRandom(-150, 150);
    
    ofVec2f median = ofVec2f(a_.x + (b_.x - a_.x) / 2 + xx, yy);
    
    ofSetLineWidth(1.2);
    ofPolyline l;
    l.addVertex(a_.x + 10, a_.y - 12);
    l.bezierTo(a_, median, b_);
    l.draw();
    
}
