#include "Evento.h"
Evento::Evento(){
}

void Evento::setup(float _x, float _y,ofImage _img,string _str){
    x = _x;
    y = _y;
    img= _img;
    str=_str;
    ofTrueTypeFont::setGlobalDpi(72);

  	verdana14.load("verdana.ttf", 14, true, true);
  	verdana14.setLineHeight(18.0f);
  	verdana14.setLetterSpacing(1.037);
}

void Evento::update(){

}

void Evento::draw(){
  ofSetColor(255,255,255);
  img.draw(x,y);
  glPushMatrix();
  ofSetColor(255);
  ofRect(20,20,300,100);;
  ofSetColor(245, 58, 135);
	verdana14.drawString(str, 155, 92);
}
