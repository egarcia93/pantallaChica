#include "Evento.h"
Evento::Evento(){
}

void Evento::setup(float _x, float _y,ofImage _img,string _tipo,string _titulo,string _fecha,string _hora){
    x = _x;
    y = _y;
    img= _img;
    tipo=_tipo;
    titulo=_titulo;
    fecha=_fecha;
    hora=_hora;

    logo.load("logo.jpg");

    ptipo.setText(tipo);
    ptipo.setWidth(width*0.70);
    ptipo.setAlignment(ofxParagraph::ALIGN_LEFT);
    ptipo.setIndent(0);
    ptipo.setFont("Pill Gothic 300mg Regular.ttf",10);

    ptitulo.setText(titulo);
    ptitulo.setWidth(width*0.70);
    ptitulo.setAlignment(ofxParagraph::ALIGN_LEFT);
    ptitulo.setIndent(0);
    ptitulo.setLeading(5);
    ptitulo.setFont("Pill_Gothic_600mg_Bold.ttf",15);

    pfecha.setText(fecha);
    pfecha.setWidth(width*0.70);
    pfecha.setAlignment(ofxParagraph::ALIGN_LEFT);
    pfecha.setIndent(0);
    pfecha.setFont("FF_Basic_Gothic.ttf",12);

    phora.setText(hora);
    phora.setWidth(width*0.70);
    phora.setAlignment(ofxParagraph::ALIGN_LEFT);
    phora.setIndent(0);
    phora.setFont("FF_Basic_Gothic.ttf",12);

    inicia=ofGetElapsedTimeMillis();

}

void Evento::update(){


}

void Evento::draw(){

  if(x<10){
  x=x+20;
  alfa=alfa+20;

  }

  ofEnableAlphaBlending();


    ofSetColor(255,255,255,alfa);
    img.resize(width,height);
    img.draw(imgX,imgY);
    ofSetColor(255,alfa);
    ofRect(x,y,(0.75*width),rectH);
    ofSetColor(0,alfa);


        ptipo.draw(x+10,50);
        ptitulo.draw(x+10,90);
        pfecha.draw(x+10,200);
        phora.draw(x+10,225);


  ofDisableAlphaBlending();
}


void Evento::dissolve()
{

  if(alfa>0){
    alfa=alfa-20;
    if(x>-width){
    x=x-20;
    }
  }

  ofEnableAlphaBlending();

    ofSetColor(255,255,255,alfa);
    img.resize(width,height);
    img.draw(imgX,imgY);
    ofSetColor(255,alfa);
    ofRect(x,y,(0.75*width),rectH);
    ofSetColor(0,alfa);


    ptipo.draw(x+10,50);
    ptitulo.draw(x+10,90);
    pfecha.draw(x+10,200);
    phora.draw(x+10,225);

  ofDisableAlphaBlending();

  }
  void Evento::actualizando(){

    ofSetColor(255,255,255);
    logo.resize(width,height-20);
    logo.draw(0,20);


  }
