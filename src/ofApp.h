#pragma once


#include "ofMain.h"
#include "ofxJSON.h"
#include "Evento.h"
#include <iostream>
#include <string>



class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();
    void update();
    string cambiarFecha(string fecha);
    string cambiarHora(string fechaInicio,string fechaFinal);


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
    int initY=50;
    int flag=1;

    string meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre",
    "Octubre","Noviembre","Diciembre"};
    string horaInicio;
    string horaFinal;
    string horaEvento;

    vector <Evento> miEvento;
    vector <Evento> miEvento2;

};
