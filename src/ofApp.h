#pragma once

#include "ofMain.h"

#include "ofx3DSphere.h"
#include "ofxCalibrator.h"
#include "ofxControls.h"
#include "ofxCountdown.h"
#include "ofxHorizontalGraph.h"
#include "ofxVerticalGraph.h"
#include "ofxKeyboard.h"
#include "ofxMap.h"
#include "ofxNoisePlot.h"
#include "ofxRadar.h"
#include "ofxSatellite.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        void volumeControl(float volume_);
        bool isSoundtrackPaused();

        void youAreDefeated();
        void youWin();
	void setFalsePassword();

 	bool passwordBox();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        struct Stage { int id; bool active; bool done; };
    
        Stage stages [5] = {{ 0, true, false },
			    { 1, false, false },
                            { 2, false, false },
                            { 3, false, false },
                            { 4, false, false }};
    
        //multikeys
        bool keyIsDown [2306];
    
        //soundtrack
        ofSoundPlayer soundtrack;
        float volume = 0.25;
        bool soundtrackPause = false;
        int trackNum = 1;
    
        //stage A: administrator
        ofImage initScreen;
        ofVideoPlayer       redButtonMovie;
    
        long startingTime;
    
        //stage B: main interface
        ofFbo* interface;

        ofImage background;
        ofImage backgroundRed;

        ofImage overLights;
        ofImage overLightsRed;

        int uiState = 1;
        int falsePassword = 0;

        //defconUI20
        int record;
        ofxTrueTypeFontUC firaRegular;
        //defconUI20

	ofVec2f lightsTurnRed [7] = {{3540, 3535}, {3000, 2995}, {2400, 2395}, {1800, 1795}, {1200, 1195}, {600, 595}, {300, 0}};
	int red = 0;

	int timeTillRestart = 999;
        int restartTimer = 0;
    
        ofxCountdown countdown;
        ofxCalibrator axisX, axisY;
        ofxMap map;
        ofxSatellite sat1, sat2;
        ofx3DSphere sphere3D;
        ofxRadar radar;
    
        //graph plots
        ofxNoisePlot noise;
        ofxHorizontalGraph horizontalGraph;
        ofxVerticalGraph verticalGraph;
    
        ofxKeyboard keyboard;
    
        int frameCount = 0;
        int animCount = 0;
    
        //stage C: defeat
        ofImage defeatMessage;
    
        //stage D: victory
        ofImage winMessage;

	//controls
	ofxControls controls;
    
};
