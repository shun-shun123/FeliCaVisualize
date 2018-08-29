#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    music.load("music.mp3");
    music.setLoop(true);
    music.setVolume(1.0);
    music.play();
    
    string file = "data.json";
    bool success = json.open(file);
    if (success) {
        cout << "Success to parse JSON" << endl;
    } else {
        cout << "Faild to parse JSON" << endl;
    }
    
    font.load("Batang.ttf", 30);
    
    for (int i = 0; i < json.size(); i++) {
        if (!(find(dirs.begin(), dirs.end(), json[i]["entranceStationName"].asString() + "駅") != dirs.end())) {
            dirs.push_back(json[i]["entranceStationName"].asString() + "駅");
        }
        if (!(find(dirs.begin(), dirs.end(), json[i]["exitStationName"].asString() + "駅") != dirs.end())) {
            dirs.push_back(json[i]["exitStationName"].asString() + "駅");
        }
    }
    for (int i = 0; i < dirs.size(); i++) {
        cout << dirs[i] << endl;
    }
    for (int i = 0; i < dirs.size(); i++) {
        
        struct pictureSet set = {
            dirs[i]
        };
        for (int j = 0; j < NUM_OF_PIC; j++) {
            set.images[j] = ofImage(dirs[i] + "/pic" + ofToString(j) + ".png");
        }
        pictureSets.push_back(set);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    cam.setPosition(ofGetFrameNum(), ofGetHeight() / 2, -500);
    cam.lookAt(ofVec3f(ofGetFrameNum(), ofGetHeight() / 2, 0), ofVec3f(0, -1, -1));
    for (int i = 0; i < pictureSets.size(); i++) {
        ofPushMatrix();
        int x = i * 300;
        int y = ofGetHeight() / 2;
        int z = i * 100;
        ofTranslate(x, y, z);
        ofRotateY(180);
        pictureSets[i].images[0].draw(0, 0, 0, 100, 100);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(x, 0, z);
        font.drawString(pictureSets[i].dirName, -30, y - 20);
        ofPopMatrix();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
