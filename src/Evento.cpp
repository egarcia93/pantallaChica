#include "Evento.h"
Evento::Evento(){
}

void Evento::setup(float _x, float _y,ofImage _img,string _tipo,string _titulo,string _fecha,string _hora){
    x = _x;
    y = _y;
    imgX = _x;
    imgY = _y;
    img= _img;
    tipo=_tipo;
    titulo=_titulo;
    fecha=_fecha;
    hora=_hora;
    ofTrueTypeFont::setGlobalDpi(72);

  	verdana14.load("verdana.ttf", 14, true, true);
  	verdana14.setLineHeight(18.0f);
  	verdana14.setLetterSpacing(1.037);
      inicia=ofGetElapsedTimeMillis();
}

void Evento::update(){

}

void Evento::draw(){
  tiempo=ofGetElapsedTimeMillis()-inicia;
  if(x<100){
 x=x+4;
 alfa=alfa+10;

  } else if(tiempo>5000){

    alfa=alfa-3;
    x=x-3;
  }

  ofEnableAlphaBlending();

ofSetColor(255,255,255,alfa);
  img.draw(imgX,imgY);

  ofSetColor(255,alfa);
  ofRect(x+30,20,300,100);
  ofSetColor(0,alfa);
	verdana14.drawString(tipo, x+50, 50);
  verdana14.drawString(titulo, x+50, 70);
  verdana14.drawString(fecha, x+50, 90);
  verdana14.drawString(hora, x+50, 110);

    ofDisableAlphaBlending();


  }
