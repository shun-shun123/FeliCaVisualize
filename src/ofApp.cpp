#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    loadData("data.json");
    
    vector<struct Elem> dataSets;
    for (int i = 0; i < json.size(); i++) {
        struct Elem elem = {
             json[i][inStaKey].asString(),
            json[i][outStaKey].asString(),
            json[i][moneyKey].asInt(),
        };
        dataSets.push_back(elem);
    }
    interactiveMode = new InteractiveMode(dataSets);
}

//--------------------------------------------------------------
void ofApp::update(){
    interactiveMode->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    interactiveMode->draw();
}

//--------------------------------------------------------------
bool ofApp::loadData(string file) {
    bool success = json.open(file);
    if (success) {
        cout << "Success to parse JSON" << endl;
    } else {
        cout << "Faild to parse JSON" << endl;
    }
    return success;
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
    interactiveMode->isClicked(x, y);
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
