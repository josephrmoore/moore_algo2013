#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    totalFireworks = 100;
    currentFirework = 0;
    startAnimation = ofGetElapsedTimeMillis();
    for(int i=0; i<6; i++){
        ofSoundPlayer f;
        f.loadSound("firework" + ofToString(i) + ".mp3");
        explosions.push_back(f);
        ofSoundPlayer r;
        r.loadSound("reax" + ofToString(i) + ".mp3");
        reax.push_back(r);
    }
}

//--------------------------------------------------------------
void testApp::update(){

    for(vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); ){
        it->update();
        if(it->over){
            it = fireworks.erase(it);
        } else {
            it++;
        }
    }
    
    if(currentFirework == totalFireworks){
        totalFireworks = 50;
        currentFirework = 0;
    }
    cout<<currentFirework<<endl;
    switch(currentFirework){
        case 0:
            playFireworks(startAnimation, 0);
            break;
        case 1:
            playFireworks(startAnimation, 5000);
            break;
        case 2:
            playFireworks(startAnimation, 5000);
            break;
        case 3:
            playFireworks(startAnimation, 5000);
            break;
        case 4:
            playFireworks(startAnimation, 3000);
            break;
        case 5:
            playFireworks(startAnimation, 3000);
            break;
        case 6:
            playFireworks(startAnimation, 3000);
            break;
        case 7:
            playFireworks(startAnimation, 3000);
            break;
        case 8:
            playFireworks(startAnimation, 200);
            break;
        case 9:
            playFireworks(startAnimation, 3000);
            break;
        case 10:
            playFireworks(startAnimation, 3000);
            break;
        case 11:
            playFireworks(startAnimation, 3000);
            break;
        case 12:
            playFireworks(startAnimation, 100);
            break;
        case 13:
            playFireworks(startAnimation, 3000);
            break;
        case 14:
            playFireworks(startAnimation, 15000);
            break;
        case 15:
            playFireworks(startAnimation, 1500);
            break;
        case 16:
            playFireworks(startAnimation, 1500);
            break;
        case 17:
            playFireworks(startAnimation, 1500);
            break;
        case 18:
            playFireworks(startAnimation, 1500);
            break;
        case 19:
            playFireworks(startAnimation, 1500);
            break;
        case 20:
            playFireworks(startAnimation, 1500);
            break;
        case 21:
            playFireworks(startAnimation, 1500);
            break;
        case 22:
            playFireworks(startAnimation, 500);
            break;
        case 23:
            playFireworks(startAnimation, 500);
            break;
        case 24:
            playFireworks(startAnimation, 500);
            break;
        case 25:
            playFireworks(startAnimation, 500);
            break;
        default:
            playFireworks(startAnimation, 100);
            break;
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for(vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); it++){
        it->draw(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
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

void testApp::playFireworks(float start, float duration){
    if(ofGetElapsedTimeMillis()-start>=duration){
        float r_rand = ofRandom(reax.size());
        float e_rand = ofRandom(explosions.size());
        Firework f;
        f.setup(reax[r_rand], explosions[e_rand]);
        fireworks.push_back(f);
        currentFirework++;
        startAnimation = ofGetElapsedTimeMillis();
    }
}
