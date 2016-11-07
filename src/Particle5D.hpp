#pragma once
#include "ofxVec5.hpp"
class Particle5D {
    public:
        ofxVec5f position;
        ofxVec5f velocity;
        ofxVec5f acceleration;
    
    void setup();
        void update(float dt);
    
    
};