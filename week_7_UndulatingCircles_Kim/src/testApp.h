#pragma once

#include "ofMain.h"
#include "Undulator.h"

// Inspired by the work of Albert Kim
// Original code from: git@github.com:thealkimist/kim_algo2013.git

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        Undulator u1, u2, u3, u4, u5;
};
