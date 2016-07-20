/*
 
TODO LIST:
 
[-] Kabooms! /random explosion over sphere's surface/
 
 
*/

#include "ofx3DSphere.h"

ofx3DSphere::ofx3DSphere() {
    
    
}

void ofx3DSphere::inits(ofVec3f position_, int dimensions_) {
    
    position = position_;
    dimensions = dimensions_;

    theta = ofRandom(-PI, PI);
    phi = ofRandom(-PI, PI);
    
    radius = dimensions * 0.4;
    
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            
            points[i][j].x = sin(PI * i/16.0) * cos( 2 * PI * j/16.0) * 80.0;
            points[i][j].y = sin(PI * i/16.0 ) * sin(2 * PI * j/16.0) * 80.0;
            points[i][j].z = cos(PI * i/16.0) * 80.0;
            
        }
    }
    
    sprite = new ofFbo();
    sprite->allocate(300, 300, GL_RGBA );

}


void ofx3DSphere::update() {

	
	updated = true;
    
    
}

void ofx3DSphere::draw() {

    ofSetColor(125, 115, 5);

    if(updated) { 

    sprite->begin();
    ofClear(255, 0);

    ofSetColor(255, 255, 255, 255);
    
    ofPushMatrix();
    ofTranslate(150, 150);
    
    ofSetColor(0, 0, 0,64);
    //ofDrawEllipse(0, 0, dimensions, dimensions);
    
    ofSetColor(16,41, 19, 192);
    //ofDrawEllipse(0, 0, dimensions - 8, dimensions - 8);
    

    ofSetColor(124, 144, 24, 128);
    //draw sphere
    
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            
            rotateByX(i, j, 0.01);
            rotateByY(i, j, 0.005);
            rotateByZ(i, j, -0.015);
      
            if(i != 15) ofDrawLine(points[i][j].x, points[i][j].y, points[i + 1][j].x, points[i + 1][j].y);
            if(j != 15) ofDrawLine(points[i][j].x, points[i][j].y, points[i][j + 1].x, points[i][j + 1].y);
            else ofDrawLine(points[i][j].x, points[i][j].y, points[i][0].x, points[i][0].y);
            
        }
    }

    ofPopMatrix();

    sprite->end();
    updated = false;

    }

    sprite->draw(position.x - 150, position.y - 150);
  
    
}

void ofx3DSphere::rotateByX(int i_, int j_, float radians_) {
    float  y = points[i_][ j_].y;
    points[i_][ j_].y = (y * cos(radians_)) + (points[i_][ j_].z * sin(radians_) * -1.0);
    points[i_][ j_].z = (y * sin(radians_)) + (points[i_][ j_].z * cos(radians_));
}

void ofx3DSphere::rotateByY(int i_, int j_, float radians_) {
    float x = points[i_][ j_].x;
    points[i_][ j_].x = (x * cos(radians_)) + (points[i_][ j_].z * sin(radians_) * -1.0);
    points[i_][ j_].z = (x * sin(radians_)) + (points[i_][ j_].z * cos(radians_));
}

void ofx3DSphere::rotateByZ(int i_, int j_, float radians_) {
    float  x =  points[i_][ j_].x;
    points[i_][ j_].x = (x * cos(radians_)) + (points[i_][ j_].y * sin(radians_) * -1.0);
    points[i_][ j_].y = (x * sin(radians_)) + (points[i_][ j_].y * cos(radians_));
}
