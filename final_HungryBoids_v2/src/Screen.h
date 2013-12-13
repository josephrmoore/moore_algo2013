//
//  Screen.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//


#include "ofMain.h"

class Screen {
public:
    Screen();
    
    vector<ofImage> images;
    vector<ofSoundPlayer> sounds;
    
    void update();
    void draw();
    void addImage(ofImage image);
    void addSound(ofSoundPlayer sound);
};