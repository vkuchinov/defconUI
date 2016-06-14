#include "ofxMap.h"


void ofxMap::inits(){
    
    mask.load("assets/spots2.png");

    somewhereInRussia = ofVec2f(1220, 460);

    for(int s = 0; s < ofRandom(6, 16); s++){

        addElement(0);
    }

}

void ofxMap::update(int time_, int secondsLeft_){
    
    float chance = ofMap(secondsLeft_, 3550, 0, 1E-11, 1E-3);
    if(ofRandom(1.0) < chance) {
      
        ofLog()<<"trying to add silo";
        addElement(time_);
    }
    
    for(int e = 0; e < elements.size(); e++){
        elements[e].update(time_);
    }
    
}

void ofxMap::addElement(int time_){
    
    ofLog()<<"adding silo, step 2";
    
    int nextID = (int)ofRandom(4);
    if(nextID == 0 || nextID == 2){

    ofVec4f data = getRightCoordinates(nextID);
    ofVec2f position = ofVec2f(data.x, data.y);
    ofVec2f target = ofVec2f(data.z, data.w);
    
    string s = ofToString(position) + " " + ofToString(target);
    ofLog()<<s;

    ofxSprite nextElement;
    nextElement.inits(nextID, position.x, position.y, target.x, target.y);
    if(position.x != 0.0 && position.y != 0.0) { elements.push_back(nextElement); ofLog()<<"adding silo"; }
    }
    
}

ofVec4f ofxMap::getRightCoordinates(int id_){
 
    //R: USSR silos, G: US silos, B: submarines
    ofColor pattern [4] = {ofColor(0, 255, 0, 255), ofColor(0, 0,255, 255), ofColor(255, 0, 0, 255), ofColor(0, 0,255, 255)};
    
    ofVec4f output;
    
    bool valid = false;
    bool targetValid = false;
    
    for(int i = 0; i < 9999; i++){
        
        float x = somewhereInRussia.x; //(int)ofRandom(50, ofGetWidth() - 50);
        float y = somewhereInRussia.y; //(int)ofRandom(50, ofGetHeight() - 50);

        float xT = (int)ofRandom(50, ofGetWidth() - 50);
        float yT = (int)ofRandom(50, ofGetHeight() - 50);

        ofColor def = mask.getColor(x, y);
        ofColor defT = mask.getColor(xT, yT);
        
        int patternTarget = 0;
        if(id_ == 0) patternTarget = 2;
        
        if(pattern[0] == defT && !checkDistance(x, y, xT, yT)) { valid = true; output.x = x; output.y = y;
            
            output.z = xT; output.w = yT;  break; }
        
    }
    
    return output;

}


bool ofxMap::checkDistance(float x_, float y_, float xT_, float yT_){
    
    bool tooClose = false;
    
    for(int e = 0; e < elements.size(); e++){
        
        ofVec2f dist = ofVec2f(xT_, yT_) - elements[e].target;
        if(dist.length() < 28) tooClose = true;
    }
    
    return tooClose;

}

void ofxMap::draw(){

    //mask.draw(0, 0);
    for(int e = 0; e < elements.size(); e++){
       elements[e].draw();
    }

    //somewhere in USSR [Doomsday perimeter]
    //ofSetColor(255, 0, 255, 255);
    //ofDrawEllipse(1240, 460, 8, 8);
}
