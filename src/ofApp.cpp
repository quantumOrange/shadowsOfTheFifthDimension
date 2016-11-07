#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
    shader.load("shadows5d");
    particle.setup();
    //shader.begin();
       // shader.setUniform1f("lifetime", 8);
    //shader.end();
}

//--------------------------------------------------------------
float endTime = 8;
bool realtime = false;
bool stop = false;
float t =0;
void ofApp::update(){
    
    //timer
    if(realtime) {
        time = ofGetElapsedTimef();
        dt = ofGetLastFrameTime();
    }
    else{
        float framePerSec = 30.0;
        time = ofGetFrameNum()/framePerSec;
        dt = 1.0/framePerSec;
    }
    
    
    particle.update(dt);
    
    if(!stop){
        t+= 0.01*dt;
    }
    
    if(time>endTime){
        std::exit(0);
    }
    
    if(realtime) return;
    int n = ofGetFrameNum();
    if(n > 0) {
        auto str = "frames/" + ofToString(n,4,'0') + ".png";
        ofSaveScreen(str);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofxVec5f p = particle.position;
    
    shader.begin();
        shader.setUniform1f("time", time);
        shader.setUniform4f("origin_a", p.x,p.y,p.z,p.w);
        shader.setUniform1f("origin_v", p.v);
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    shader.end();
    
    
    if(realtime) {
        string msg = "\n\nfps: " + ofToString(ofGetFrameRate(), 2) + "\nTime: " + ofToString(ofGetElapsedTimef(),2);
        ofDrawBitmapStringHighlight(msg, 10, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'p'){
        stop = !stop;
    }
    if(key =='a'){
        t += 0.001;
    }
    if(key =='z'){
        t -= 0.001;
    }
    cout << t << endl;
    
    if(key =='s'){
        auto str = "images/" + ofToString(ofGetFrameNum(),4,'0') + ".png";
        ofSaveScreen(str);
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
