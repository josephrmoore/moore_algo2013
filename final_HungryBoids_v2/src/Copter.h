//
//  Copter.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//


#include "ofMain.h"
#include "Bait.h"
#include "Timer.h"

class Copter : public ofxBox2dRect {
public:
    Copter();
    void update();
    void draw();
    void drop();
    void load(float timer);
    void think();
    float speed, stability, damage;
    int  baits;
    ofVec2f pos, vel, acc;
    Bait bait;
    ofImage skin;
    float level_time;
    Timer t;
    vector<float> drop_points;
    int section;
    float period;
};