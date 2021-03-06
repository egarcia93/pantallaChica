#ifndef _EVENTO
#define _EVENTO
#include "ofMain.h"
#include "ofxParagraph.h"
class Evento {

    public:

    void setup(float _x, float _y,ofImage _img,string tipo,string titulo,string fecha,string hora);
    void update();
    void draw();
    void dissolve();
    void actualizando();

    float x;
    float y;
    float imgX=0;
    float imgY=0;

    int width=384;
    int height=288;
    int alfa=0;
    int tiempo=0;
    int inicia;
    int rectW=350;
    int rectH=220;


    ofImage img;
    ofImage logo;
    ofTrueTypeFont	verdana14;
    ofTrueTypeFont	gothic10;
    ofTrueTypeFont gothic15;
    ofTrueTypeFont gothicFF;

    string tipo;
    string titulo;
    string fecha;
    string hora;

    ofxParagraph ptipo = ofxParagraph();
    ofxParagraph ptitulo = ofxParagraph();
    ofxParagraph pfecha = ofxParagraph();
    ofxParagraph phora = ofxParagraph();

    Evento();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
}; // don't forget the semicolon!
#endif
