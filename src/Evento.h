#ifndef _EVENTO
#define _EVENTO
#include "ofMain.h"
class Evento {

    public:

    void setup(float _x, float _y,ofImage _img,string tipo,string titulo,string fecha,string hora);
    void update();
    void draw();
    void dissolve();

    float x;
    float y;
    float imgX=0;
    float imgY=0;

    int alfa=0;
    int tiempo=0;
    int inicia;
    int rectW=300;
    int rectH=100;

    ofImage img;
    ofTrueTypeFont	verdana14;

    string tipo;
    string titulo;
    string fecha;
    string hora;

    Evento();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
}; // don't forget the semicolon!
#endif
