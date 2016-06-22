#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //ofToggleFullscreen();
    //ofSetWindowTitle("DEFCON UI");
    ofDisableTextureEdgeHack(); //disable global texture "edge hacking"
    ofSetVerticalSync(true);
    ofHideCursor();
    
    //soundtrack
    //string urls = "mp3s/soundtrack/" + ofToString(1 + (int)ofRandom(21)) + ".mp3";
    string urls = "mp3s/soundtrack/" + ofToString(trackNum) + ".mp3";
    soundtrack.load(urls, true);
    soundtrack.setVolume(volume);
    soundtrack.setPaused(true);
    soundtrackPause = false;

    //stage A: administrator
 
    initScreen.load("assets/turnTheKey.jpg");
    redButtonMovie.load("videos/redButtonMovie.mov");
    redButtonMovie.setLoopState(OF_LOOP_NONE);
    redButtonMovie.setPosition(0.0);
    redButtonMovie.setPaused(true);

    //stage B: main interface

    interface = new ofFbo();
    interface->allocate(1920, 1080, GL_RGB );
    //interface->begin();
    //ofClear(0, 255);
    //frontBuffer->getTextureReference().setTextureWrap( GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT );
    //interface->end();

    background.load("assets/theGrid.jpg");
    overLights.load("assets/theGridLights.png");
    backgroundRed.load("assets/theGridRed.jpg");
    overLightsRed.load("assets/theGridLightsRed.png");
    
    countdown.inits(ofVec3f(592, 120), 480, 200);
    
    //axis calibrators
    axisX.inits("X", 0, 1920);
    axisY.inits("Y", 0, 1080);
    
    //map
    map.inits();
    
    //satellites trajectory
    sat1.inits(PI * 0.7);
    sat2.inits(2 * PI * 0.9);
    
    //graphs
    noise.inits(ofVec3f(200, 174), 400, 100, (controls.jX + 1) / (controls.jY + 1));
    horizontalGraph.inits(ofVec3f(1560, 116), 160 , 78);
    verticalGraph.inits(ofVec3f(1320, 116), 160 , 78);
    
    //radar & 3D shpere
    sphere3D.inits(ofVec3f(1620, 808), 200);
    radar.inits(ofVec2f(300, 808), 200);

    keyboard.inits(ofVec3f(1000, 200));
    
    //stage C: defeat
    defeatMessage.load("assets/defeat.png");
    
    //stage D: win
    winMessage.load("assets/win.png");

    controls.inits();

    //defconUI20
    firaRegular.load("typefaces/FiraMonoRegular.ttf", 32, true, true);
    //defconUI20

}

//--------------------------------------------------------------
void ofApp::update(){

    //controls
    controls.update();
    
    //soundtrack

    soundtrack.setVolume(volume);

    /************************************************************************************
     *
     *      STAGE A: ADMINISTRATIVE A
     *
     ************************************************************************************
    */

    if(stages[0].active) { 


    //if(redButtonMovie.isLoaded()) { redButtonMovie.update(); }
    //redButtonMovie.update();

    	if(controls.active18) {

        	ofLog()<<"admin button pressed";
   	     //redButtonMovie.play();
        	controls.active18 = false;

        	stages[0].active = false; stages[0].done = true;
        	stages[1].active = true;

        	soundtrack.setPaused(false);

        	//resetting timer
        	countdown.setZeroPoint();

    	} 

    }

    /************************************************************************************
     *
     *      STAGE A: ADMINISTRATIVE B
     *
     ************************************************************************************
    */

    if(stages[1].active) {

	if(!soundtrack.isPlaying() && !soundtrackPause) {

	    if(trackNum < 21) { trackNum++; } else { trackNum = 1; }
            string urls = "mp3s/soundtrack/" + ofToString(trackNum) + ".mp3";
            soundtrack.load(urls, true);
            if(soundtrack.isLoaded()) { soundtrack.play(); }

        }

    	if(controls.active23){

	ofLog()<<"key is turned on";
	stages[1].active = false;
	stages[1].done = true;
	stages[2].active = true;

    	}

	if(frameCount % 30) { countdown.update(); }
   
    	frameCount++;

    }

    /************************************************************************************
     *
     *      STAGE B: MAIN INTERFACE
     *
     ************************************************************************************
    */
    
    //stage B: main interface
    if(stages[2].active){
    
        if(!soundtrack.isPlaying() && !soundtrackPause) {

            if(trackNum < 21) { trackNum++; } else { trackNum = 1; }
            string urls = "mp3s/soundtrack/" + ofToString(trackNum) + ".mp3";
            soundtrack.load(urls, true);
            if(soundtrack.isLoaded()) { soundtrack.play(); }

        }

    if(countdown.getTimeLeftInSeconds() < 60 && soundtrack.isPlaying()) soundtrack.stop();
    
    //if(redButtonMovie.getIsMovieDone() && !stages[0].done){

    //stages[1].active = false; stages[0].done = true;
    //stages[2].active = true;
    //}

    if(controls.joystickButton) { 

	ofLog()<<"joystick botton pressed";
	controls.joystickButton = false;
	ofVec2f joy = controls.getJoystickPosition();
	keyboard.mousePressed(joy.x, joy.y);

    }
    
    if(controls.active24 && keyboard.INPUT2.size() > 0){

	ofLog()<<"checking password";
	controls.active24 = false;
	keyboard.checkPassword();

    }
   
    //if(comtrols.getEnterButtonState) {
    //	controls.setEnterButtonToInactive();
    //	keyboard.checkPassword();
    //}
     
    //map
    map.update(frameCount, countdown.getTimeLeftInSeconds());

    //joystick & keyboard
   
    if(frameCount % 30) { countdown.update();
    axisX.update(controls.jX);
    axisY.update(controls.jY);
    }

    //graphs
    if(frameCount % 10) { noise.update((controls.jX + 1) / (controls.jY + 1)); }
    if(frameCount % 12) { horizontalGraph.update(countdown.getSeconds()); }
    if(frameCount % 8) { verticalGraph.update(countdown.getMillis()); }
    
    //radar & sphere3D update
    radar.update();
    sphere3D.update();

    if(frameCount % 3 == 0) animCount++;

    frameCount++;

    }

    falsePassword--;

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0, 0, 0);
    //ofEnableAlphaBlending();

    /************************************************************************************
     *
     *      STAGE A: ADMINISTRATIVE A
     *
     ************************************************************************************
    */

    if(stages[0].active == true) { initScreen.draw(0, 0); }
    
     /************************************************************************************
     *
     *      STAGE B: ADMINISTRATIVE B
     *
     ************************************************************************************
    */

     if(stages[1].active == true) { initScreen.draw(0, 0); }

    /************************************************************************************
     *
     *      STAGE B: MAIN INTERFACE
     *
     ************************************************************************************
    */

    //joystick debugging
    //ofDrawRectangle(joy.x, joy.y, 10, 10);

    if(stages[2].active){
        
    interface->begin();

    //ofClear(0, 255);
    ofEnableAlphaBlending();
 
    uiState = 1;

    for(int r = 0; r < 7; r++) {

      if(countdown.getTimeLeftInSeconds() < lightsTurnRed[r].x && countdown.getTimeLeftInSeconds() > lightsTurnRed[r].y)
      {uiState = -1; }

    }

    if(falsePassword > 0) { uiState = -1; };

    if(uiState == 1) { background.draw(0, 0); } else {backgroundRed.draw(0, 0); }

    //map
    map.draw();

    sat1.draw(); sat2.draw();

    int redIncrement = 0;
    if(uiState == -1) { redIncrement = 128; }
    countdown.draw(redIncrement);

    axisX.draw(); axisY.draw();

    noise.draw();
    horizontalGraph.draw();
    verticalGraph.draw();

    //radar & sphere3D
    radar.draw();
    sphere3D.draw();

    ofVec2f joy = controls.getJoystickPosition();

    keyboard.draw(joy.x, joy.y, soundtrack.isPlaying());

    ofSetColor(255, 255, 255, 255);
    ofDrawBitmapString("joystick debouncing:" + ofToString(controls.debounceLimit) + ", sensitivity: " + ofToString(controls.joystickSensitivity), 48, 48);

    //joystick poiner
    //ofDrawRectangle(joy.x, joy.y - 7, 2, 16);
    //ofDrawRectangle(joy.x - 7, joy.y, 16, 2);

    if(uiState == 1) { overLights.draw(0, 0); } else { overLightsRed.draw(0, 0); }

    interface->end();
    ofDisableAlphaBlending();

    interface->draw(0, 0);

    }

    /************************************************************************************
     *
     *      STAGE C: DEFEAT
     *
     ************************************************************************************
    */

    if(stages[3].active){

    ofEnableAlphaBlending();
    background.draw(0, 0);
    
    //map.draw();
        
    sat1.draw(); sat2.draw();
    axisX.draw(); axisY.draw();
    
    //radar & 3D sphere
    //sphere3D.draw();
    //radar.draw();
    
    //graphs
    //noise.draw();
    //horizontalGraph.draw();
    //verticalGraph.draw();
    
    //keyboard
    //keyboard.drawInactive();

    ofSetColor(255, 255, 255, 255);
    
    defeatMessage.draw(0, 0);
        
    overLights.draw(0, 0);

    countdown.stop();

    restartTimer++;
    if(restartTimer > timeTillRestart) { ofExit(); }

    }
    
    /************************************************************************************
     *
     *      STAGE D: VICTORY
     *
     ************************************************************************************
    */

    if(stages[4].active){
        
        ofEnableAlphaBlending();
        background.draw(0, 0);
        
        //map.draw();
        
         sat1.draw(); sat2.draw();
        axisX.draw(); axisY.draw();
        
        //radar & 3D sphere
        //sphere3D.draw();
        //radar.draw();
       
        //graphs
        //noise.draw();
        //horizontalGraph.draw();
        //verticalGraph.draw();
        
        //keyboard
        //keyboard.drawInactive();
        ofSetColor(255, 255, 255, 255);
        
        winMessage.draw(0, 0);

        //defconUI20

        string caption = "YOUR ЯECORD TIME: ";
        string minutes = ofToString((int)record/60);
        if(minutes.length() == 1) minutes = "0" + minutes;
        string seconds = ofToString(record%60);
        if(seconds.length() == 1) seconds = "0" + seconds;
        string percent = ofToString(roundf(record/3.550)/10.0);

        caption += minutes + ":" + seconds + " (" + percent + "%)";

        firaRegular.drawString(caption, 580, 900);

        //defconUI20
        
        overLights.draw(0, 0);

        countdown.stop();

	restartTimer++;
	if(restartTimer > timeTillRestart) { ofExit(); }
        
    }

}

void ofApp::setFalsePassword(){ ofLog()<<"SET TO 60"; falsePassword = 20; }

void ofApp::youAreDefeated(){
    
    stages[1].active = false; stages[2].done = true; stages[3].active = true;
    soundtrack.setPaused(true);
    soundtrackPause = true;
    
}

void ofApp::youWin(){
    
    stages[1].active = false; stages[2].done = true; stages[4].active = true;
    soundtrack.setPaused(true);
    soundtrackPause = true;

    //defconUI20
    record = (3550 - countdown.getTimeLeftInSeconds());
    //defconUI20
    
}

void ofApp::volumeControl(float volume_){

    if(volume > 0.05 && volume < 0.8 && volume_ != -1.0)  { volume += volume_; soundtrack.setVolume(volume); }
    else {

        if(soundtrack.isPlaying()) { soundtrack.setPaused(true); soundtrackPause = true; }
        else  { soundtrack.setPaused(false); soundtrackPause = false; }

    }
}

bool ofApp::isSoundtrackPaused(){ return soundtrackPause; }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    keyIsDown[key] = true;
    
    // 'Q' or 'q' is pressed
    //if (key == char(113) || key == char(81) && !stages[0].done){ 

    //redButtonMovie.play(); 

    //stages[0].active = false; stages[0].done = true; stages[1].active = true;
    //countdown.setZeroPoint();
    //keyboard.ACTIVE = true;

    //}

    // 'A' or 'a' is pressed
    //if (key == char(97) || key == char(65)){ }
    
    // 'Z' or 'z' is pressed with holding LEFT_SHIFT (physical key)
    //if ((keyIsDown['z'] && keyIsDown['x']) || (keyIsDown['Z'] && keyIsDown['x'])) {  }
    
    // 'M' or 'm' is pressed
    //if (key == char(109) || key == char(77)){ if(soundtrack.isPlaying()) soundtrack.stop(); else soundtrack.play(); }
    
    // LEFT
    if (key == OF_KEY_LEFT && controls.debounceLimit > 1 ){  controls.debounceLimit--; }

    // RIGHT
    if (key == OF_KEY_RIGHT && controls.debounceLimit < 128 ){  controls.debounceLimit++; }

    // UP
    if (key == OF_KEY_UP && controls.joystickSensitivity > 0.05 ){ controls.joystickSensitivity += 0.0002; }
    
    // DOWN
    if (key == OF_KEY_DOWN && controls.joystickSensitivity > 0.0001 ){  controls.debounceLimit -= 0.0002;; }

    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    keyIsDown[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
