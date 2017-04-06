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

    /*
    ofTrueTypeFont::setGlobalDpi(72);
    verdana14.load("verdana.ttf", 14, true, true);
  	verdana14.setLineHeight(18.0f);
  	verdana14.setLetterSpacing(1.037);

    gothic10.load("Pill Gothic 300mg Regular.ttf", 10, true, true);
    gothic10.setLineHeight(18.0f);
    gothic10.setLetterSpacing(1.037);

    gothic15.load("Pill_Gothic_600mg_Bold.ttf", 15, true, true);
    gothic15.setLineHeight(18.0f);
    gothic15.setLetterSpacing(1.037);
    */
    ptipo.setText(tipo);
    ptipo.setWidth(200);
    ptipo.setAlignment(ofxParagraph::ALIGN_LEFT);
    ptipo.setIndent(0);
    ptipo.setFont("Pill Gothic 300mg Regular.ttf",10);

    ptitulo.setText(titulo);
    ptitulo.setWidth(300);
    ptitulo.setAlignment(ofxParagraph::ALIGN_LEFT);
    ptitulo.setIndent(0);
    ptitulo.setFont("Pill_Gothic_600mg_Bold.ttf",20);



    inicia=ofGetElapsedTimeMillis();

}

void Evento::update(){

}

void Evento::draw(){

  if(x<10){
  x=x+5;
  alfa=alfa+20;

  }

  ofEnableAlphaBlending();

    ofSetColor(255,255,255,alfa);
    //img.resize(ofGetWidth(),ofGetHeight());
    img.draw(imgX,imgY);
    ofSetColor(255,alfa);
    ofRect(x,y,rectW,rectH);
    ofSetColor(0,alfa);

    ptipo.draw(x+15,70);
    ptitulo.draw(x+15,90);
    /*
    gothic10.drawString(tipo, x+15, 70);
    gothic15.drawString(titulo, x+15, 90);
    verdana14.drawString(fecha, x+15, 110);
    verdana14.drawString(hora, x+15, 130);
*/

  ofDisableAlphaBlending();


  }

void Evento::dissolve()
{

  if(alfa>0){
    alfa=alfa-40;
    x=x-10;
  }

  ofEnableAlphaBlending();

    ofSetColor(255,255,255,alfa);
//img.resize(ofGetWidth(),ofGetHeight());
    img.draw(imgX,imgY);
    ofSetColor(255,alfa);
    ofRect(x,y,rectW,rectH);
    ofSetColor(0,alfa);
    ptipo.draw(x+15,70);
    ptitulo.draw(x+15,90);
  	/*gothic10.drawString(tipo, x+15, 70);
    gothic15.drawString(titulo, x+15, 90);
    verdana14.drawString(fecha, x+15, 110);
    verdana14.drawString(hora, x+15, 130);*/

    ofDisableAlphaBlending();

  }
