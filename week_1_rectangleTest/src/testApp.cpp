#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    state = 0;
    color = 0;
    for(int i=0; i<100; i++){
        Rectangle r;
        r.color.r = 255;
        r.color.g = 0;
        r.color.b = 0;
        r.color.setHue(i*2.55);
        r.pos.x = ofRandom(0,ofGetWidth());
        r.pos.y = ofRandom(0,ofGetHeight());
        rects.push_back(r);
    }
    alternate = true;
}

//--------------------------------------------------------------
void testApp::update(){
    if(state == 0){
        // between .01 & .001
        myRect.pos.x += .002;
        // .002 pixels per frame...
        // framerate is roughly 60 fps
        // My screen is 1024 pixels @ 72 dpi
        // That means it is 14.2 inches wide
        // .12 pixels per second
        
        // .0016667 inches per second

        // 7.2 pixels per minute
        // 432 pixels per hour
        // 6 inches per hour
        // .5 feet per hour
        
        // 0.0000946969696 miles per hour
    }
    if(state == 1){
//        myRect.pos.x += .0625;
//        myRect.pos.x += .03125;
//        myRect.pos.x += .0234375;
        myRect.pos.x += .0224609375;
//        myRect.pos.x += .021484375;
//        myRect.pos.x += .01953125;
//        myRect.pos.x += .015625;
//        myRect.pos.x += .0078125;
        // .0224609375 pixels per frame
        // framerate 60 fps, screen resolution 72 dpi
        // 1.34765625 pixels per second

        // .01871744792 inches per second
        
        // 1.123046875 inches per minute
        // 67.3828125 inches per hour
        // 5.615234375 feet per hour
        
        // 0.001063491359 miles per hour
    }
    if(state == 2){
        // I'm going to switch the top left and bottom right points of a rectangle on click... no i'm not.
        
    }
    if(state == 3){
        // position of the mouse determines radius and position within 500 pixels of the rectangle
        // clicking allows you to toggle between RGB and HSB modes
        // In RGB, R is X, G is Y, and B is an average of the first two
        // In HSB, H is X, S is Y and that is all

        // The end effect is that you get a rectangle that is warped and shaped dependent on the position of the rectangle, 
        // which is dependent on the mouse.
        
        
        
        myRect.pos.x = ofMap(mouseX, 0, ofGetWidth(), 0, 500);
        myRect.pos.y = ofMap(mouseY, 0, ofGetWidth(), 0, 500);
        myRect.radius.x = myRect.pos.x;
        myRect.radius.y = myRect.pos.y;
        if(color == 0){
            myRect.color.r = ofMap(myRect.radius.x, 0, 500, 0, 255);
            myRect.color.g = ofMap(myRect.radius.y, 0, 500, 0, 255);
            myRect.color.b = (myRect.color.r+myRect.color.g)/2;
        } else if (color == 1){
            myRect.color.setHue(ofMap(myRect.radius.x, 0, 500, 0, 255));
            myRect.color.setSaturation(ofMap(myRect.radius.y, 0, 500, 0, 255));
        } 
        myRect.color.a = ofMap(myRect.radius.x, 0, 500, 0, 255);
    }
    if(state == 4){
        for(int i=0; i<100; i++){
            rects[i].xenoToPoint(mouseX, mouseY, ((i+1)*.01), ((i+1)*.01));
        }
    }
    if(state == 5){
        for(int i=0; i<100; i++){
            if(i==0){
                rects[i].xenoToPoint(mouseX, mouseY, ((i+1)*.01), ((i+1)*.01));
            } else {
                rects[i].xenoToPoint(rects[(i-1)].pos.x, rects[(i-1)].pos.y, ((i+1)*.01), ((i+1)*.01));
            }
        }
    }
    if(state == 6){
        // in class stuff... not my homework
        
        percent += .01f;
        myRect.xenoToPoint(mouseX, mouseY, 0.3f, 0.3f);
        //    myRect.interpolateByPercent(percent);
        if(percent > 1){
            percent = 0;
        }        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    myRect.draw();
    if(state == 2){
        for(int i=0; i<2; i++){
            rects[i].draw();
        }
    }
    if(state == 4 || state == 5){
        for(int i=0; i<100; i++){
            rects[i].draw();
        }
    }
    ofSetColor(255);
//    ofDrawBitmapString(ofToString(percent), ofPoint(10,10));
//    cout<<ofToString(ofGetFrameRate(), 2)<<endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'a' || key == 'A'){
        // Homework a
        state = 0;
    }
    if(key == 'b' || key == 'B'){
        // Homework b
        state = 1;
    }
    if(key == 'c' || key == 'C'){
        // Homework c
        state = 2;
        // dumb to put this here, i know, but it's easy
        for(int i=0; i<2; i++){
            rects[i].color.r = ofRandom(0, 255);
            rects[i].color.g = ofRandom(0, 255);
            rects[i].color.b = ofRandom(0, 255);
            rects[i].pos.x = ofRandom(0,ofGetWidth());
            rects[i].pos.y = ofRandom(0,ofGetHeight());
        }
    }
    if(key == 'd' || key == 'D'){
        // Homework d
        state = 3;
    }
    if(key == 'e' || key == 'E'){
        // Homework e
        state = 4;
    }
    if(key == 'f' || key == 'F'){
        // Homework f
        state = 5;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
//    percent = (float)y/(float)ofGetWindowHeight();
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(state == 2){
        // funny walking mistake 
//        ofPoint a;
//        a.x = myRect.pos.x+myRect.radius.x;
//        a.y = myRect.pos.y+myRect.radius.y;
//        
//        myRect.pos.x = a.x;
//        myRect.pos.y = a.y;
//        
//        ofPoint temp;
//        temp.x = myRect.pos.x;
//        temp.y = myRect.pos.y;
//        
//        a.x = temp.x;
//        a.y = temp.y;
        
    }
    if(state == 3){
        if(color<1){
            color++;
        } else {
            color = 0;
        }
    }
    if(state == 2){
        if(alternate){
            alternate = false;
            rects[0].pos.x = mouseX;
            rects[0].pos.y = mouseY;
        } else {
            alternate = true;
            rects[1].pos.x = mouseX;
            rects[1].pos.y = mouseY;
        }
    }
    if(state == 4){
        for(int i=0; i<100; i++){
            rects[i].color.r = ofRandom(0, 255);
            rects[i].color.g = ofRandom(0, 255);
            rects[i].color.b = ofRandom(0, 255);
            rects[i].pos.x = ofRandom(0,ofGetWidth());
            rects[i].pos.y = ofRandom(0,ofGetHeight());
        }
    }
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