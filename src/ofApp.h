#pragma once


#include "ofMain.h"
#include "ofxJSON.h"
#include "Evento.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();
    void update();

    ofxJSONElement response;
    std::vector<ofImage> images;
    int contador=0;
    int tiempo=0;
    int inicia=0;
    int alfa=255;
    int x=-100;
    int y=10;
    int x2=-100;
    int y2=10;
    vector <Evento> miEvento;

};
