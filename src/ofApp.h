#pragma once

#include "ofMain.h"
#include "ofxJson.h"
#include "ofxTrueTypeFontUC.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    static const int NUM_OF_PIC = 6;
    
    bool loadData(string file);
    
    ofxJSONElement json;
    ofxTrueTypeFontUC font;
    const string inStaKey = "entranceStationName";
    const string outStaKey = "exitStationName";
    const string moneyKey = "exitStationID";
    struct Elem {
        string entranceStationName;
        string exitStationName;
        int money;
    };
    vector<struct Elem> dataSets;
};
