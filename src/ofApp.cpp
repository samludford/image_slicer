#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    me.load("g.jpg");
    mirror_me = me;
    mirror_me.mirror(false, true);
    
    grabber.initGrabber(ofGetWidth(), ofGetHeight());
    
    player.load("acetate.mp4");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // use images based on mode
    
    if(mode == 1) {
        
        // use image -
        
        one = me;
        one_mirrored = mirror_me;
        
    } else if(mode == 2) {
        
        // use webcam input -
        
        one.setFromPixels(grabber.getPixels());
        one_mirrored = one;
        one_mirrored.mirror(false, true);
        
    } else if(mode == 3) {
        
        // use video -
        
        one.setFromPixels(player.getPixels());
        one_mirrored = one;
        one_mirrored.mirror(false, true);
    }
    
    float slice_width = ofGetWidth()/2.0/(slice_count*2.0);
    float im_slice_width = ofMap(slice_width, 0, ofGetWidth(), 0, me.getWidth());
    for(float i=0 ; i < ofGetWidth()/2.0 ; i+=slice_width*2.0) {
        
        // first image
        float im_pos = ofMap(i, 0, ofGetWidth(), 0, one.getWidth());
        one.drawSubsection(i, 0.0, slice_width, ofGetHeight(), im_pos, 0.0, im_slice_width, one.getHeight());

        float mirror_pos = ofGetWidth()-i-slice_width;
        float mirror_im_pos = ofMap(mirror_pos, 0, ofGetWidth(), 0, one_mirrored.getWidth());
        one_mirrored.drawSubsection(mirror_pos, 0.0, slice_width, ofGetHeight(), mirror_im_pos, 0.0, im_slice_width, one_mirrored.getHeight());


        // second (larger) image
        one.drawSubsection(i+slice_width, 0.0, slice_width, ofGetHeight(), im_pos, adjustment/2.0, im_slice_width, one.getHeight()-adjustment);
        one_mirrored.drawSubsection(mirror_pos-slice_width, 0.0, slice_width, ofGetHeight(), mirror_im_pos, adjustment/2.0, im_slice_width, one_mirrored.getHeight()-adjustment);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') {
        ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
    } else if(key == '1') {
        mode = 1;
    } else if(key == '2') {
        mode = 2;
    } else if(key == '3') {
        mode = 3;
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
