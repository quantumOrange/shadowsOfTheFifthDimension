//
//  Particle5D.cpp
//  SteriographicProjection
//
//  Created by David Crooks on 11/09/2016.
//
//
#include "ofMain.h"
#include "Particle5D.hpp"

void Particle5D::setup(){
    position = ofxVec5f(0.0, 0.0, 0.0, 0.0, 0.0 );
    float l = 0.0005;
    velocity = ofxVec5f(l, l, l, l, l );
    acceleration = ofxVec5f(0.0, 0.0, 0.0, 0.0, 0.0 );
}

void Particle5D::update(float dt) {
    position += velocity;
    
    if (velocity.length() < 0.002){
        acceleration += 0.0000001*ofxVec5f(ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1));
        velocity += acceleration;
    }
    else {
        velocity *= 0.9;
    }
}