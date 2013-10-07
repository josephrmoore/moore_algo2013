//
//  Card.h
//  SolitaireEnding
//
//  Created by Joseph Moore on 10/5/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxSvg.h"

class Card{
    
public:
    Card(string suit, string face);
    void update();
    void draw();
    ofxSVG svg;
    float scale, mass, bounce, height, width;
    ofVec2f pos, vel, acc, force;
    string suit, face;
    void addForce(ofVec2f force);
    bool falling, square;
    ofColor color;
};
