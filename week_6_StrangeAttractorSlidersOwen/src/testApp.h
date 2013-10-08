#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxUI.h"

// Code ***HEAVILY*** borrowed from Owen Herterich's Strange Attractor sketch
// This is just a mod of his work.
// Github repo: https://github.com/oherterich/algo2013-owenherterich

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
        void onGuiEvent(ofxUIEventArgs &e);
        ofxUICanvas *gui;
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void getPos(ofPoint p);
    
    vector<Particle> particles;
    
    vector<ofPoint> points;
    
    int num;
    
    ofImage myImage;
    
    float px, py, a, b, c, d, a0,b0,c0,d0;
		
};
