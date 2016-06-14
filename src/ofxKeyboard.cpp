#include "ofApp.h"
#include "ofxKeyboard.h"

ofxKeyboard::ofxKeyboard() {

    active = ofVec2f(0, 5);
    background.load("assets/virtualKeyboard2.png");

    highlight.load("assets/highlightKey.png");

    firaRegular.load("typefaces/FiraMonoRegular.ttf", 16, true, true);
    
}

void ofxKeyboard::inits(ofVec3f position_) {
    
    
}


void ofxKeyboard::update() {
    
    
}

void ofxKeyboard::draw(int mX_, int mY_, bool state_) {

    int incrementX = 0;
    int incrementY = 0;

    ofSetColor(255, 255, 255, 255);
    background.draw(0, 0);
    
    ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());

    string inputParser = "";
    for(int c = 0; c < INPUT2.size(); c++) inputParser += map[INPUT2[c]].key;
    firaRegular.drawString(inputParser, 1069, 660);
    
    if(lastJX != mX_){ if(mX_ > lastJX) { incrementX = 1; } else { incrementX = -1; }}
    if(lastJY != mY_){ if(mY_ > lastJY) { incrementY = 1; } else { incrementY = -1; }}

    //x: Y (0, 1, 2) rows, y; X: (0 ... 11) columns
    if(incrementY < 0 && active.x > 0) active.x += -1;
    if(incrementY > 0 && active.x < 2) active.x += 1;

    if(incrementX < 0 && active.y > 0) active.y += -1;
    if(incrementX > 0 && active.y < 11) active.y += 1;

    int r = (int)active.x;
    int c = (int)active.y;

    //corrections
    if(INPUT2.size() == 0 && r == 0 && c == 11) { c = 10; }
    if(r == 1 && c == 11) { c = 10; }
    if(r == 2 && c == 10 ) { if(incrementX < 0) { c = 9; } else { c = 11; } }

    defaultKey = tabMap[r][c];

    string s = "active " + ofToString(active.x) + " " + ofToString(active.y) + " default " + ofToString(defaultKey);
    //ofLog()<<s;

    for(int k = 0; k < 34; k++){
    
        if(map[k].id == defaultKey) { ofSetColor(255, 255, 255, 255);  highlight.draw(map[k].position.x - 26, map[k].position.y - 27); }
        else { ofSetColor(green); if(app->isSoundtrackPaused() && map[k].id == 33) { ofSetColor(red); } }
        if(INPUT2.size() == 0) { if(map[k].id == 32) ofSetColor(red); }
        firaRegular.drawString(ofToString(map[k].key), map[k].position.x - 8, map[k].position.y + 4);
        
    }

    lastJX = mX_; lastJY = mY_;

}

void ofxKeyboard::drawInactive() {
    
    ofSetColor(255, 255, 255, 255);
    background.draw(0, 0);
    
    ofSetColor(red);

    for(int k = 0; k < 34; k++){
        
        firaRegular.drawString(ofToString(map[k].key), map[k].position.x - 8, map[k].position.y + 4);
        
    }
    
    
}

void ofxKeyboard::checkPassword(){
    
    string TOCHECK = "";
    ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());

    for(int c = 0; c < INPUT2.size(); c++) TOCHECK += map[INPUT2[c]].key;
    if(TOCHECK != PASSWORD) {   voiceMessage.load(urls[0]); voiceMessage.play(); INPUT2.clear(); app->setFalsePassword(); }
    else{
        
    //VICTORY SCENARIO
    voiceMessage.load(urls[1]); voiceMessage.play();

    app->youWin();
        
    }
    
}

void ofxKeyboard::keyPressed(int mX_, int mY_){
    

}

void ofxKeyboard::mouseMoved(int x, int y){
    

    
}

void ofxKeyboard::mousePressed(int mX_, int mY_){


    //joystick debugging
    //string j = "x: " + ofToString(mX_) + ", y: " + ofToString(mY_);
    //ofLog()<<j;
    
    ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());

    //for(int k = 0; k < 34; k++){ if(mX_ > map[k].x0 && mX_ < map[k].x1 && mY_ > map[k].y0 && mY_ < map[k].y1) { defaultKey = k; }}
    int defaultID = 0;

    for(int k = 0; k < 34; k++){ if(defaultKey == map[k].id) { defaultID = k; }}

    if(defaultKey == 32 && INPUT2.size() > 0)  { INPUT2.pop_back(); }
    else if(defaultKey < 32) { INPUT2.push_back(defaultID); }
    else if(defaultKey == 33) { app->volumeControl(-1.0); }
    //else if(map[defaultKey].id == 33) { app->volumeControl(-1.0); }
    //else if(map[defaultKey].id == 34) { app->volumeControl(0.05); }
    
}
