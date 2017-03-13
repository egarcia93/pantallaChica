#include "Evento.h"
Evento::Evento(){
}

void Evento::setup(float _x, float _y,ofImage _img){
    x = _x;
    y = _y;
    img= _img;
}

void Evento::update(){

}

void Evento::draw(){
img.draw(x,y);
}
