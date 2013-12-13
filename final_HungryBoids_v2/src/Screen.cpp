//
//  Screen.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#include "Screen.h"

Screen::Screen(){
    
}

void Screen::update(){
    
}

void Screen::draw(){
    for(int i=0; i<images.size(); i++){
        images[i].draw(0,0,images[i].getWidth(),images[i].getHeight());
    }
}

void Screen::addImage(ofImage image){
    images.push_back(image);
}

void Screen::addSound(ofSoundPlayer sound){
    sounds.push_back(sound);
}