#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // Box 2D stuff
    box.init();
	box.setGravity(0, 5);
	box.setFPS(30.0);
    ofRectangle bounds(-ofGetWidth()/2,-ofGetHeight(), ofGetWidth()*2, ofGetHeight()*2);
    box.createBounds(bounds);
    box.enableGrabbing();
    box.registerGrabbing();
    
    // Boilerplate OF stuff
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(ofRandom(255),ofRandom(255),ofRandom(255));
    
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
    back = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    title_bk.loadImage("boids_titlescreen_bk.png");
    title_hungry.loadImage("boids_titlescreen_hungry.png");
    title_boids.loadImage("boids_titlescreen_boids.png");
    title_start.loadImage("boids_titlescreen_start.png");
    
    //Win & Lose Screens
    win_start.loadImage("boids_win.png");
    lose_start.loadImage("boids_lose.png");
    win_word.loadImage("boids_win_word.png");
    lose_word.loadImage("boids_lose_word.png");
    
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
    
    // Levels
    level1.bricks_num=3;
    level1.createCondition(2);
    levels.push_back(level1);

    level2.bricks_num=5;
    level2.createCondition(2);
    level2.createCondition(2);
    levels.push_back(level2);
    
    level3.bricks_num=5;
    level3.createCondition(3);
    levels.push_back(level3);
    
    level4.bricks_num=7;
    level4.createCondition(3);
    level4.createCondition(2);
    levels.push_back(level4);

    level5.bricks_num=7;
    level5.createCondition(3);
    level5.createCondition(3);
    levels.push_back(level5);
    
    level6.bricks_num=10;
    level6.createCondition(3);
    level6.createCondition(3);
    level6.createCondition(3);
    levels.push_back(level6);
    
    level7.bricks_num=12;
    level7.createCondition(4);
    level7.createCondition(3);
    level7.createCondition(2);
    levels.push_back(level7);
    
    // Example images
    box2.loadImage("2.png");
    box3.loadImage("3.png");
    box4.loadImage("4.png");
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
    } else if (state_screen==2){
        // win
        title_back.update();
        if(title_back.activate == true){
            back = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            back.setBrightness(255);
            title_back.reset();
        }
        title_word2.update();
        if(title_word2.activate == true){
            word2 = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            word2.setBrightness(255);
            title_word2.reset();
        }
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
        if(levels[levels_current-1].checkConditions(bricks)){
            state_screen=2;
        }
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
        state_screen = 3;
        levels_current = 1;
        noise.stop();
        all.play();
        trill.play();
        copter.load(30000);
        levels[levels_current-1].load(levels_current);
        makeShapes(levels[levels_current-1]);
        copter.baits = 3+levels_current-1;
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
                levels[levels_current-1].load(levels_current);
                makeShapes(levels[levels_current-1]);
                copter.baits = 3+levels_current-1;
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
    ofBackground(back);
    ofPushStyle();
    win_start.draw(ofVec2f((ofGetWidth()-win_start.getWidth())/2,500), win_start.getWidth(), win_start.getHeight());
    ofSetColor(word2);
    win_word.draw(ofVec2f((ofGetWidth()-win_word.getWidth())/2,100), win_word.getWidth(), win_word.getHeight());
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::lose(){
    ofBackground(back);
    ofPushStyle();
    lose_start.draw(ofVec2f((ofGetWidth()-lose_start.getWidth())/2,500), lose_start.getWidth(), lose_start.getHeight());
    ofSetColor(word1);
    lose_word.draw(ofVec2f((ofGetWidth()-lose_word.getWidth())/2,100), lose_word.getWidth(), lose_word.getHeight());
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::ending(){
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString("You Wone it all!", 400, 200);
    ofDrawBitmapString("PRESS SPACE TO QUIT", 400, 250);
    ofPopStyle();
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
    for(int i=0; i<levels_current-1; i++){
        for(int j=0; j<levels[i].bricks.size(); j++){
            ofPushStyle();
            ofSetColor(100, 255-i*20);
            ofRect(levels[i].bricks[j], 80, 900);
            ofPopStyle();
        }
    }
    ofPushMatrix();{
        flocker.draw();
    }ofPopMatrix();
    copter.draw();
    copter.bait.draw();
    for(int i=0; i<bricks.size(); i++){
        bricks[i].draw();
    }
    for(int i=0; i<levels[levels_current-1].conditions.size(); i++){
        if(levels[levels_current-1].conditions[i].height==2){
            box2.draw(ofVec2f(900+(i*25),20), 20, 85);
        } else if (levels[levels_current-1].conditions[i].height==3){
            box3.draw(ofVec2f(900+(i*25),20), 20, 85);
        } else if (levels[levels_current-1].conditions[i].height==4){
            box4.draw(ofVec2f(900+(i*25),20), 20, 85);
            
        }
        
    }

}

void testApp::makeShapes(Level l){
    for(int i=0; i<bricks.size(); i++){
        bricks[i].destroy();
    }
    bricks.clear();
    for(int i=0; i<l.bricks_num; i++){
        Brick r;
        r.setPhysics(300.0, 0.03, 1.0);
        r.setup(box.getWorld(), 100+(ofGetWidth()/l.bricks_num)*i, ofGetHeight()/2, 100/2.0, 100/2.0);
        bricks.push_back(r);
    }
}
