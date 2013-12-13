//
//  FlockController.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#include "FlockController.h"

FlockController::FlockController(){
    
}

void FlockController::addParticle( b2World* _box, int numParticles ){
    for( int i=0; i<numParticles; i++ ){
        
        // I was getting bad results, so I looked up uniform sphere distribution and got this: http://mathworld.wolfram.com/SpherePointPicking.html
        float phi = ofRandom( 0, TWO_PI );
		float costheta = ofRandom( -1.0f, 1.0f );
		
		float rho = sqrt( 1.0f - costheta * costheta );
		float x = rho * cos( phi );
		float y = rho * sin( phi );
		float z = costheta;
		
        ofVec2f randVec(x, y);
        
		ofVec2f pos = randVec * ofRandom( 100.0f, 600.0f );
		ofVec2f vel = -randVec;
        
        // Box 2d setup, store in vector
        Boid b( pos, vel );
        b.enableGravity(false);
        b.setPhysics(0.1, 1.0, 1.0);
        b.setup(_box, pos.x-800, pos.y, 4);
        boidList.push_back( b );
    }
}

void FlockController::applyForces( float zoneRadius, float separateThresh, float alignThresh) {
    float zoneRadiusSq = zoneRadius * zoneRadius;
    float scale = 10.0;
    for( vector<Boid>::iterator b1=boidList.begin(); b1!=boidList.end(); ++b1 ){
        
        vector<Boid>::iterator b2 = b1 + 1;
        for( b2; b2!=boidList.end(); ++b2 ){
            
            // setup some vars
            ofVec2f dir = b1->pos - b2->pos;
            float lenSq = dir.lengthSquared();
            
            // We only want a boid to act on another boid if it's with zoneRadiusSq.
            // If they aren't within that distance, they are too far away and don't affect each other.
            if( lenSq < zoneRadiusSq ){
                
                float pct = lenSq / zoneRadiusSq;
                if( pct == 0 ){
                    pct = 0.0000001;
                }
                
                // seperation - The boids are too close to each other.  Apply a separation force;
                if( pct < separateThresh){
                    
                    float adjustedPct = 1.0 - ofMap(pct, 0.0, separateThresh, 0.0, 1.0);
                    ofVec2f force = dir.normalized() * adjustedPct * 0.03;
                    
                    b1->applyForce(force);
                    b2->applyForce(-force);
                    
                    //                    float F = ( separateThresh/pct - 1.0f ) * 0.01;
                    //					ofVec2f force = dir.normalized() * F;
                    //					b1->applyForce( force );
                    //					b2->applyForce( -force );
                }
                
                // alignment - The boids are a medium distance from each other.  Apply an alignment force.
                else if( pct < alignThresh ){
                    float adjustedPct = 1.0 - ofMap(pct, separateThresh, alignThresh, 0.0, 1.0);
                    float F = adjustedPct * 0.005;
                    
                    //					float F					= ( 1.0f - ( cos( str * TWO_PI ) * -0.5f + 0.5f ) ) * 0.005;
                    
                    b1->applyForce( b2->vel.normalized() * F );
                    b2->applyForce( b1->vel.normalized() * F );
                }
                
                // cohesion - The boids are just a little too far from each other.  Apply an attraction force to bring them together.
                else{
                    float attractStrength = 0.01;
                    
                    float adjustedPct = ofMap(pct, alignThresh, 1.0f, 0.0f, 1.0f);
                    ofVec2f force = dir.normalized() * adjustedPct * attractStrength;
                    b1->applyForce( -force);
                    b2->applyForce( force);
                    
                    //                    float threshDelta		= 1.0f - alignThresh;
                    //					float adjustedPercent	= ( pct - alignThresh )/threshDelta;
                    //					float F					= ( 1.0f - ( cos( adjustedPercent * TWO_PI ) * -0.5f + 0.5f ) ) * attractStrength;
                    //
                    //					dir.normalize();
                    //					dir *= F;
                    //
                    //					b1->applyForce( -dir );
                    //					b2->applyForce( dir );
                }
            }
            
        }
        
        b1->pullToCenter( ofVec2f(x,y) );
    }
}

//--------------------------------------------------------------
void FlockController::update(){
    for( int i=0; i<boidList.size(); i++ ){
        boidList[i].update();
    }
    center = flockPos();
}

//--------------------------------------------------------------
void FlockController::draw(){
    for( int i=0; i<boidList.size(); i++ ){
        boidList[i].draw();
    }
}

ofPoint FlockController::flockPos(){
    float minx = ofGetWidth();
    float miny = ofGetHeight();
    float maxx = 0;
    float maxy = 0;
    
    for( int i=0; i<boidList.size(); i++ ){
        if(boidList[i].pos.x>maxx){
            maxx = boidList[i].pos.x;
        }
        if(boidList[i].pos.y>maxy){
            maxy = boidList[i].pos.y;
        }
        if(boidList[i].pos.x<minx){
            minx = boidList[i].pos.x;
        }
        if(boidList[i].pos.y<miny){
            miny = boidList[i].pos.y;
        }
    }
    return ofVec2f((maxx-minx),(maxy-miny));
}


void FlockController::reset(){
    for( int i=0; i<boidList.size(); i++ ){
        
        // I was getting bad results, so I looked up uniform sphere distribution and got this: http://mathworld.wolfram.com/SpherePointPicking.html
        float phi = ofRandom( 0, TWO_PI );
        float costheta = ofRandom( -1.0f, 1.0f );
        
        float rho = sqrt( 1.0f - costheta * costheta );
        float x = rho * cos( phi );
        float y = rho * sin( phi );
        float z = costheta;
        
        ofVec2f randVec(x, y);
        
        boidList[i].pos = randVec * ofRandom( 100.0f, 600.0f );
        boidList[i].vel = -randVec;
    }
    center = ofVec2f(0,0);
}