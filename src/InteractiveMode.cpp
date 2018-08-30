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
    cout << "インスタンス生成" << endl;
}

InteractiveMode::InteractiveMode(vector<struct Elem> elem) {
    cout << "できた" << endl;
    font.load("sazanami.ttf", 20);
    this->dataSets = elem;
    this->mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    int limit = 0; // limiteが10000を超えたらwhileを抜ける
    while (this->position.size() != this->dataSets.size() && limit < 1000000) {
        ofVec2f pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
        // 全要素に対して一定以上の距離を保って入ればpush_back
        bool canPush = true;
        for (int i = 0; i < this->position.size(); i++) {
            if (pos.distance(this->position[i]) <= 100) {
                canPush = false;
            }
        }
        if (canPush) {
            this->position.push_back(pos);
            this->mesh.addVertex(ofVec3f(pos.x, pos.y, 0));
        }
        limit++;
    }
    for (int i = this->position.size(); i < this->dataSets.size(); i++) {
        this->position.push_back(ofVec2f(ofRandomWidth(), ofRandomHeight()));
        this->mesh.addVertex(ofVec3f(this->position[i].x, this->position[i].y, 0));
    }
    for (int i = 0; i < this->dataSets.size(); i++) {
        alpha.push_back(255);
        state.push_back(false);
    }
}

void InteractiveMode::update() {
    for (int i = 0; i < this->dataSets.size(); i++) {
        if (this->state[i]) {
            this->alpha[i]--;
            if (this->alpha[i] < 0) {
                this->alpha[i] = 0;
            }
        }
    }
}

void InteractiveMode::draw() {
    for (int i = 0; i < this->dataSets.size(); i++) {
        ofSetColor(255, this->alpha[i]);
        this->font.drawString(this->dataSets[i].entranceStationName, this->position[i].x, this->position[i].y);
        ofSetColor(255, ofMap(this->alpha[i], 0, 255, 255, 0));
        this->font.drawString(ofToString(this->dataSets[i].money), this->position[i].x, this->position[i].y);
    }
    this->mesh.draw();
}

void InteractiveMode::isClicked(int x, int y) {
    int i;
    for (i = 0; i < this->dataSets.size(); i++) {
        if (this->position[i].distance(ofVec2f(x, y)) <= 50)
            break;
    }
    cout << this->dataSets[i].entranceStationName << " is Clicked" << endl;
    this->state[i] = true;
}
