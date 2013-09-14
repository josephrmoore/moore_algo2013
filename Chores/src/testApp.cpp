#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    people = 10;
    ofSetVerticalSync(true);
    sound.loadSound("chores.mp3");
    // protagonist
    pro = Pro();
    // antagonist
    ant = Ant();
    // rain of dots
    for(int i=0; i<people; i++){
        Dot dot = Dot();
        dot.pos.x = i*(ofGetWidth()/people)+52;
        dots.push_back(dot);
    }
    ofBackground(125);
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){
    if(ofGetElapsedTimeMillis() > 2000 && sound_started == false){
        sound.play();
        sound_started = true;
    }
    
    pro.update();
    ant.update();
    
    for(int i=0; i<dots.size(); i++){
        dots[i].update();
        if(ofGetElapsedTimeMillis() < 1300){
            dots[i].line(2.0);
        } else if(ofGetElapsedTimeMillis() > 1300 && ofGetElapsedTimeMillis() <= 2100){
            dots[i].fall(0.98);
        } else if(ofGetElapsedTimeMillis() > 2100){
            dots[i].fall(0.0795);
        } else {
            dots[i].xenoToPoint(dots[i].pos.x, ofGetHeight()-(dots[i].radius.y/2), 0.5, 0.5);
        }
    }
    
    if(ofGetElapsedTimeMillis() > 4000 && ofGetElapsedTimeMillis() <= 8000){
        pro.roll(2.0);
    } else if (ofGetElapsedTimeMillis() > 9000 && ofGetElapsedTimeMillis() <= 9250){
        pro.dart(100.0, 20);
    } else if (ofGetElapsedTimeMillis() > 9250 && ofGetElapsedTimeMillis() <= 9500){
        pro.dart(800.0, 20);
    } else if (ofGetElapsedTimeMillis() > 9500 && ofGetElapsedTimeMillis() <= 9625){
        pro.dart(300.0, 40);
    } else if (ofGetElapsedTimeMillis() > 9625 && ofGetElapsedTimeMillis() <= 9750){
        pro.dart(500.0, 40);
    } else if (ofGetElapsedTimeMillis() > 9750 && ofGetElapsedTimeMillis() <= 10000){
        pro.jump(dots[0].pos.y, 400.0, 90.0, 7.0);
    } else if (ofGetElapsedTimeMillis() > 10000 && ofGetElapsedTimeMillis() <= 10250){
        pro.jump(dots[0].pos.y, 400.0, 90.0, 7.0);
    } else if (ofGetElapsedTimeMillis() > 10250 && ofGetElapsedTimeMillis() <= 10500){
        pro.vel.y = 0;
        pro.pos.y = ofGetHeight()-50;
    } else if (ofGetElapsedTimeMillis() > 11825 && ofGetElapsedTimeMillis() <= 12825){
        pro.dart(100.0, 40);
    } else if (ofGetElapsedTimeMillis() > 12825 && ofGetElapsedTimeMillis() <= 13500){
        pro.dart(200.0, 40);
    } else if (ofGetElapsedTimeMillis() > 20300 && ofGetElapsedTimeMillis() <= 22000){
        pro.dart(300.0, 40);
    } else if (ofGetElapsedTimeMillis() > 22000){
        pro.roll(2.0);
        ant.roll(2.0);
        ant.shrink(0.3);
    }

    
    
    

    if(ofGetElapsedTimeMillis() > 8000 && ofGetElapsedTimeMillis() < 9000){
        ant.approach(ant.swarm_anchor, ofPoint(800, 200), 40);
    } else if (ofGetElapsedTimeMillis() > 11000 && ofGetElapsedTimeMillis() <= 11500){
        ant.approach(ant.swarm_anchor, ofPoint(200, 200), 40);
    } else if (ofGetElapsedTimeMillis() > 11500 && ofGetElapsedTimeMillis() <= 11750){
        ant.approach(ant.swarm_anchor, ofPoint(500, 200), 60);
    } else if (ofGetElapsedTimeMillis() > 11750 && ofGetElapsedTimeMillis() <= 11875){
        ant.approach(ant.swarm_anchor, ofPoint(300, 200), 60);
    } else if (ofGetElapsedTimeMillis() > 12000 && ofGetElapsedTimeMillis() <= 13500){
        ant.approach(ant.swarm_anchor, ofPoint(800, 200), 40);
    } else if (ofGetElapsedTimeMillis() > 16000 && ofGetElapsedTimeMillis() <= 19000){
        ant.approach(ant.swarm_anchor, ofPoint(300.0, 700.0), 15);
    }
//    ant.shrink(1.0);
//    pro.dart(100.0, 20);
//    pro.jump(dots[0].pos.y, 10.0, 20);
//    pro.roll(-2.0);
//    pro.rotate(9.0); // (not working)
    
//    ant.approach(ant.swarm_anchor, ofPoint(100, 600));
//    ant.pos = ant.loop(300.0);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<dots.size(); i++){
        dots[i].draw(dots[i].radius, dots[i].pos);
        ofSetLineWidth(10);
        ofSetColor(255);
        ofLine(dots[i].pos.x, 0, dots[i].pos.x, dots[i].line_y);
    }
    if (ofGetElapsedTimeMillis() > 15150 && ofGetElapsedTimeMillis() <= 17000){
        pro.draw(pro.flatten(10.0), ofPoint(pro.pos.x, pro.pos.y+20));
    } else {
        pro.draw(pro.breathe(600.0, 1.2), pro.pos);
    }
//    ant.draw(ant.breathe(10.0, 20.0, true), ant.loop(300.0));
    
    if(ofGetElapsedTimeMillis() < 9000){
        ant.draw(ant.breathe(10.0, 20.0, true), ant.swarm(ant.swarm_anchor));
    } else if (ofGetElapsedTimeMillis() > 11000 && ofGetElapsedTimeMillis() <= 13000){
        ant.draw(ant.breathe(10.0, 20.0, true), ant.swarm(ant.swarm_anchor));
    } else if (ofGetElapsedTimeMillis() > 13800 && ofGetElapsedTimeMillis() <= 14690){
        ant.draw(ant.breathe(10.0, 20.0, true), ant.loop(100.0));
    } else if (ofGetElapsedTimeMillis() > 16000 && ofGetElapsedTimeMillis() <= 19000){
        ant.draw(ant.breathe(10.0, 20.0, true), ant.swarm(ant.swarm_anchor));
    } else {
        ant.draw(ant.breathe(10.0, 20.0, true), ant.swarm_anchor);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
