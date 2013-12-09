#pragma once

#include "ofMain.h"
#include "Timer.h"
#include "Player.h"
#include "TimePoint.h"
#include "ofxMidi.h"


class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    Timer t;
    Player p1, p2;
    vector<TimePoint> hitList;
    vector<TimePoint>   pointList;      // we called this "points" during class. Renamed for clarity.
    vector<vector<TimePoint> > loops;
    vector<vector<TimePoint> > hits;
    float               startTime;
    float               playbackStartTime;
    bool                bIsRecording;
    ofPoint             getPositionForTime( float time );
    ofPoint             getPos( float time, vector<TimePoint> t);
    int             getKeys( float time, vector<TimePoint> t);
    int loop_counter;
    const int TOTAL_LOOPS = 8;
    vector <TimePoint> temp;
    
    ofxMidiOut midiOut;
	int channel;
	
	unsigned int currentPgm;
	int note, velocity;
	int pan, bend, touch, polytouch;
};
