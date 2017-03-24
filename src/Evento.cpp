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


    ofTrueTypeFont::setGlobalDpi(72);
    verdana14.load("verdana.ttf", 14, true, true);
  	verdana14.setLineHeight(18.0f);
  	verdana14.setLetterSpacing(1.037);

    gothic10.load("Pill Gothic 300mg Regular.ttf", 10, true, true);
    gothic10.setLineHeight(18.0f);
    gothic10.setLetterSpacing(1.037);

    inicia=ofGetElapsedTimeMillis();

}

void Evento::update(){

}

void Evento::draw(){

  if(x<20){
  x=x+3;
  alfa=alfa+10;

  }

  ofEnableAlphaBlending();

    ofSetColor(255,255,255,alfa);
    img.draw(imgX,imgY);
    ofSetColor(255,alfa);
    ofRect(x,y,rectW,rectH);
    ofSetColor(0,alfa);
  	gothic10.drawString(tipo, x+35, 70);
    verdana14.drawString(titulo, x+35, 90);
    verdana14.drawString(fecha, x+35, 110);
    verdana14.drawString(hora, x+35, 130);

  ofDisableAlphaBlending();


  }

void Evento::dissolve()
{

  if(alfa>0){
    alfa=alfa-10;
    x=x-3;
  }

  ofEnableAlphaBlending();

    ofSetColor(255,255,255,alfa);
    img.draw(imgX,imgY);
    ofSetColor(255,alfa);
    ofRect(x,y,rectW,rectH);
    ofSetColor(0,alfa);
  	gothic10.drawString(tipo, x+35, 70);
    verdana14.drawString(titulo, x+35, 90);
    verdana14.drawString(fecha, x+35, 110);
    verdana14.drawString(hora, x+35, 130);
    ofDisableAlphaBlending();

  }
