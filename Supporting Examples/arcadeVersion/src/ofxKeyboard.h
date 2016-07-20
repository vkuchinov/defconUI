#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

class ofxKeyboard {
    
public:
    
    ofxKeyboard();
    void inits(ofVec3f position_);
    void update();
    void draw(int mX_, int mY_, bool state_);
    void drawInactive();
    void checkPassword();
    void keyPressed(int mX_, int mY_);
    void mouseMoved(int x, int y);
    void mousePressed(ofVec2f key_);

    void draw(ofVec2f key_, bool active_);

    bool ACTIVE = false;
    
    ofxTrueTypeFontUC firaRegular;
    ofImage background;

    ofImage highlight;
    
    ofColor green = ofColor(38, 170, 92);
    ofColor yellow = ofColor(255, 206, 5);
    ofColor red = ofColor(204, 52, 71);
    
    //TV-style keyboard
    //backspace symbol U+232B
    //enter symbol U+23CE or U+21A9
    //space symbol U+2423
    
    const string PASSWORD = "ЛУНА";
          string INPUT = "";
    
    vector<int> INPUT2;

    struct virtualKey{
    
        int id;
        string key;
        ofVec2f position;
        int x0, y0, x1, y1;
        
    };
    
    int defaultKey;

    //last joydstick position
    int lastJX = 0;
    int lastJY = 0;
    
    int lastC = 0;

    int rows = 3;
    int cols = 12;


    //1, 5
    ofVec2f active;
  

    //tabular map
    //1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 (1)
    //1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    //1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1

    //by id
    int tabMap [3][12] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 32},
			  {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, -1},
			  {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, -1, 33}};

    ofSoundPlayer  voiceMessage;
    string urls [2] = { "mp3s/incorrect.mp3", "mp3s/victory.mp3" };
    
    const int KEYBOARD_SIZE = 34;
    
                            //first row
    virtualKey map  [34] = {{0, "Й", ofVec2f(520, 732), 0, 0, 560, 772},
                            {1, "Ц", ofVec2f(600, 732), 561, 0, 640, 772},
                            {2, "У", ofVec2f(680, 732), 641, 0, 720, 772},
                            {3, "К", ofVec2f(760, 732), 721, 0, 800, 772},
                            {4, "Е", ofVec2f(840, 732), 801, 0, 880, 772},
                            {5, "Н", ofVec2f(920, 732), 881, 0, 960, 772},
                            {6, "Г", ofVec2f(1000, 732), 961, 0, 1040, 772},
                            {7, "Ш", ofVec2f(1080, 732), 1041, 0, 1120, 772},
                            {8, "Щ", ofVec2f(1160, 732), 1121, 0, 1200, 772},
                            {9, "З", ofVec2f(1240, 732), 1201, 0, 1280, 772},
                            {10, "Х", ofVec2f(1320, 732), 1281, 0, 1360, 772},
                            {32, "⌫", ofVec2f(1400, 732), 1361, 0, 1920, 772},
                            //second row
                            {11, "Ф", ofVec2f(560, 810), 0, 773, 600, 850},
                            {12, "Ы", ofVec2f(640, 810), 601, 773, 680, 850},
                            {13, "В", ofVec2f(720, 810), 681, 773, 760, 850},
                            {14, "А", ofVec2f(800, 810), 761, 773, 840, 850},
                            {15, "П", ofVec2f(880, 810), 841, 773, 920, 850},
                            {16, "Р", ofVec2f(960, 810), 921, 773, 1000, 850},
                            {17, "О", ofVec2f(1040, 810), 1001, 773, 1080, 850},
                            {18, "Л", ofVec2f(1120, 810), 1081, 773, 1160, 850},
                            {19, "Д", ofVec2f(1200, 810), 1161, 773, 1240, 850},
                            {20, "Ж", ofVec2f(1280, 810), 1241, 773, 1320, 850},
                            {21, "Э", ofVec2f(1360, 810), 1321, 773, 1920, 850},
                            //third row
                            {22, "Я", ofVec2f(520, 888), 0, 851, 560, 1080},
                            {23, "Ч", ofVec2f(600, 888), 561, 851, 640, 1080},
                            {24, "С", ofVec2f(680, 888), 641, 851, 720, 1080},
                            {25, "М", ofVec2f(760, 888), 721, 851, 800, 1080},
                            {26, "И", ofVec2f(840, 888), 801, 851, 880, 1080},
                            {27, "Т", ofVec2f(920, 888), 881, 851, 960, 1080},
                            {28, "Ь", ofVec2f(1000, 888), 961, 851, 1040, 1080},
                            {29, "Б", ofVec2f(1080, 888), 1041, 851, 1120, 1080},
                            {30, "Ю", ofVec2f(1160, 888), 1121, 851, 1200, 1080},
                            {31, "Ё", ofVec2f(1240, 888), 1201, 851, 1280, 1080},
                            {33, "▼", ofVec2f(1402, 888), 1361, 851, 1920, 1080}
        
                            };

};
