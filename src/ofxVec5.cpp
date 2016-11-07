//
//  ofxVec5.cpp
//  SteriographicProjection
//
//  Created by David Crooks on 11/09/2016.
//
//

#include "ofxVec5.hpp"
#include "ofVec2f.h"
#include "ofVec3f.h"
#include "ofVec4f.h"

ofxVec5f::ofxVec5f(const ofVec3f& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = 0;
    v = 0;
}

ofxVec5f::ofxVec5f(const ofVec2f& vec) {
    x = vec.x;
    y = vec.y;
    z = 0;
    w = 0;
    v = 0;
}

ofxVec5f::ofxVec5f(const ofVec4f& vec) {
    x = vec.x;
    y = vec.y;
    z = 0;
    w = 0;
    v = 0;
}