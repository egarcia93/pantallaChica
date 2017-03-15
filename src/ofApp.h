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
    int tiempo2=0;
    int tiempo3=0;
    int inicia=0;
    int inicia2=0;
    int inicia3=0;
    int alfa=255;
    int initX=-100;
    int initY=20;
    int flag=1;


    vector <Evento> miEvento;
    vector <Evento> miEvento2;

};
