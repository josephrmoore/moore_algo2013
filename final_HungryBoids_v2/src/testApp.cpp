#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // Box 2D stuff
    box.init();
	box.setGravity(0, 5);
	box.setFPS(30.0);
    ofRectangle bounds(-ofGetWidth()/2,-ofGetHeight()/2, ofGetWidth()*2, ofGetHeight()*1.5);
    box.createBounds(bounds);
    box.enableGrabbing();
    box.registerGrabbing();
    // Boilerplate OF stuff
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);
    // State & Level variables
    state_screen = 0;
    state_win = false;
    levels_total = 7;
    levels_current = 0;
    // Title screen
    title_back.limit = 2000;
    title_word1.limit = 200;
    title_word2.limit = 50;
    word1 = ofColor(255);
    word2 = ofColor(255);
    back = ofColor(255);
    title_bk.loadImage("boids_titlescreen_bk.png");
    title_hungry.loadImage("boids_titlescreen_hungry.png");
    title_boids.loadImage("boids_titlescreen_boids.png");
    title_start.loadImage("boids_titlescreen_start.png");
    // Sounds
    all.loadSound("boids_notrill.wav");
    all.setLoop(true); //Sound will loop
    all.setMultiPlay(true);
    trill.loadSound("boids_trill.wav");
    trill.setLoop(true); //Sound will loop
    trill.setMultiPlay(true);
    noise.loadSound("boids_noise.wav");
    noise.setLoop(true); //Sound will loop
    noise.setMultiPlay(true);
    noise.play();
    // Baits
    title_bait.setPhysics(9.0, 0.01, 0.001);
    title_bait.setup(box.getWorld(), 0, 0, 10);
    title_bait.drop(ofVec2f(200,0));
    copter.bait.setPhysics(9.0, 0.01, 0.001);
    copter.bait.setup(box.getWorld(), 0, 0, 10);
    // Flockers
    title_flocker.addParticle( box.getWorld(), 100 );
    flocker.addParticle( box.getWorld(), 100 );
}

//--------------------------------------------------------------
void testApp::update(){
    if(state_screen==0){
        // title
        box.update();
        title_bait.update();
        title_flocker.applyForces(80, 0.4, 0.75);
        title_flocker.update();
        title_back.update();
        if(title_back.activate == true){
            back = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            back.setBrightness(255);
            title_back.reset();
        }
        title_word1.update();
        if(title_word1.activate == true){
            word1 = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            word1.setBrightness(255);
            title_word1.reset();
        }
        title_word2.update();
        if(title_word2.activate == true){
            word2 = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            word2.setBrightness(255);
            title_word2.reset();
        }
    } else if (state_screen==1){
        // lose
        
    } else if (state_screen==2){
        // win
        
    } else if (state_screen==4){
        // ending
        
    } else {
        // level
        box.update();
        flocker.applyForces(80, 0.4, 0.75);
        flocker.update();
        title_back.update();
        if(title_back.activate == true){
            back = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            back.setBrightness(255);
            title_back.reset();
        }
        copter.update();
        copter.bait.update();
        flocker.x = copter.bait.pos.x;
        flocker.y = copter.bait.pos.y;
        ofVec2f dist;
        dist = flocker.center-ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
        center_perc = dist.length();
        trill.setVolume(ofClamp(ofMap(center_perc, 500, 100, 0, 1.0), 0, 1.0));
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if(state_screen==0){
        // title
        title();
    } else if (state_screen==1){
        // lose
        lose();
    } else if (state_screen==2){
        // win
        win();
    } else if (state_screen==4){
        // ending
        ending();
    } else {
        // level
        level(levels_current);
    }
//    cout<<state_screen<<" "<<levels_current<<endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(state_screen==0){
        // title
        if(key == ' '){
            state_screen = 3;
            levels_current = 1;
            noise.stop();
            all.play();
            trill.play();
            copter.load(30000);
        }
    } else if (state_screen==1){
        // lose
        if(key == ' '){
            all.stop();
            all.setPosition(0);
            all.play();
            trill.stop();
            trill.setPosition(0);
            trill.play();
            levels_current = 1;
            state_screen = 3;
        }
        if(key == 'q' || key == 'Q'){
            all.stop();
            trill.stop();
            noise.setPosition(0);
            noise.play();
            levels_current = 0;
            state_screen = 0;
        }
    } else if (state_screen==2){
        // win
        if(key == ' '){
            if(levels_current<levels_total){
                state_screen = 3;
                levels_current+=1;
            } else {
                state_screen = 4;
            }
        }
    } else if (state_screen==4){
        // ending
        if(key == ' '){
            all.stop();
            trill.stop();
            noise.setPosition(0);
            noise.play();
            levels_current = 0;
            state_screen = 0;
        }
    } else {
        // level
        if(key == '1'){
            state_screen = 1;
        }
        if(key == '2'){
            state_screen = 2;
        }
        if(key == '4'){
            state_screen = 4;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(state_screen==0){
        // title
        
    } else if (state_screen==1){
        // lose
        
    } else if (state_screen==2){
        // win
        
    } else if (state_screen==4){
        // ending
        
    } else {
        // level
        
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    if(state_screen==0){
        // title
        
    } else if (state_screen==1){
        // lose
        
    } else if (state_screen==2){
        // win
        
    } else if (state_screen==4){
        // ending
        
    } else {
        // level
        
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if(state_screen==0){
        // title
        
    } else if (state_screen==1){
        // lose
        
    } else if (state_screen==2){
        // win
        
    } else if (state_screen==4){
        // ending
        
    } else {
        // level
        
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(state_screen==0){
        // title
        
    } else if (state_screen==1){
        // lose
        
    } else if (state_screen==2){
        // win
        
    } else if (state_screen==4){
        // ending
        
    } else {
        // level
        
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if(state_screen==0){
        // title
        
    } else if (state_screen==1){
        // lose
        
    } else if (state_screen==2){
        // win
        
    } else if (state_screen==4){
        // ending
        
    } else {
        // level
        
    }
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


//--------------------------------------------------------------
void testApp::title(){
    ofBackground(back);
    ofSetColor(255);
    int rows = ofGetHeight()/64;
    int step = 255/rows;
    for(int i=0; i<rows; i++){
        ofPushStyle();
        ofSetColor(i*step, 100);
        ofRect(0,i*64,ofGetWidth(),64);
        ofPopStyle();
    }
    ofPushStyle();
    title_bk.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    title_start.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    ofPopStyle();
    ofPushStyle();
    ofSetColor(word1);
    title_hungry.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    ofPopStyle();
    ofPushStyle();
    ofSetColor(word2);
    title_boids.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    ofPopStyle();
    // boids
    ofPushMatrix();{
        title_flocker.draw();
    }ofPopMatrix();
    title_bait.draw();
    //    copter.bait.draw();
    //    flocker.draw();
}

//--------------------------------------------------------------
void testApp::win(){
    
}

//--------------------------------------------------------------
void testApp::lose(){
    
}

//--------------------------------------------------------------
void testApp::ending(){
    
}

//--------------------------------------------------------------
void testApp::level(int level){
    ofBackground(back);
    ofSetColor(255);
    int rows = ofGetHeight()/64;
    int step = 255/rows;
    for(int i=0; i<rows; i++){
        ofPushStyle();
        ofSetColor(i*step, 100);
        ofRect(0,i*64,ofGetWidth(),64);
        ofPopStyle();
    }
    ofPushMatrix();{
        flocker.draw();
    }ofPopMatrix();
    copter.draw();
    copter.bait.draw();
}
