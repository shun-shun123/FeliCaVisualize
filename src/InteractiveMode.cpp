//
//  InteractiveMode.cpp
//  HackU2018
//
//  Created by 斉藤俊介 on 2018/08/30.
//

#include "InteractiveMode.hpp"

//InteractiveMode::InteractiveMode(vector<struct Elem> elem) {
//    this->dataSets = elem;
//}

InteractiveMode::InteractiveMode() {
    cout << "No argument InteractiveMode is created" << endl;
}

InteractiveMode::InteractiveMode(vector<struct Elem> elem) {
    cout << "InteractiveMode is successfully created" << endl;
    font.load("sazanami.ttf", 20);
    this->dataSets = elem;
    for (int i = 0; i < this->dataSets.size(); i++) {
        int y = ofGetHeight() / this->dataSets.size() * i + 50;
        this->position.push_back(ofVec2f(0, y));
        this->isVisible.push_back(false);
    }
    
}

void InteractiveMode::update() {
    if (index < this->dataSets.size()) {
        if (ofGetFrameNum() % 20 == 0) {
            isVisible[index] = true;
            index++;
        }
    }
}

void InteractiveMode::draw() {
    ofPushStyle();
    ofSetColor(0, 200, 0);
    for (int i = 0; i < this->dataSets.size(); i++) {
        if (!isVisible[i])
            break;
        font.drawString(this->dataSets[i].entranceStationName, 30, position[i].y);
        font.drawString(this->dataSets[i].exitStationName, 280, position[i].y);
        font.drawString(this->dataSets[i].entranceStationId.substr(0, 10), 520, position[i].y);
        font.drawString(ofToString(this->dataSets[i].money) + "円", 700, position[i].y);
    }
    ofPopStyle();
}

void InteractiveMode::isClicked(int x, int y) {

}
