#pragma once

#include "ofMain.h"
#include "Dot.h"
#include "Pro.h"
#include "Ant.h"

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
        ofSoundPlayer sound;
        bool sound_started;
        vector <Dot> dots;
        Pro pro;
        Ant ant;
        int people;
};
