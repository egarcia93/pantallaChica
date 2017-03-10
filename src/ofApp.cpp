#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(24);
    inicia=ofGetElapsedTimeMillis();
    std::string url = "http://puertadev.centroculturadigital.mx/api/activities2/now2";

    if (!response.open(url))
    {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON";
    }

    unsigned int numImages = MIN(10, response.size());
    for(unsigned int i = 0; i < numImages; i++)
     {
         string url = response[i]["imageVision"].asString();
         ofImage img;
         img.loadImage(url);
         images.push_back(img);

     }

}

void ofApp::draw()
{
     ofBackground(255);
     ofEnableAlphaBlending();

        ofSetColor(255,255,255,alfa);
        images[contador].draw(x, y);

        if(x<10){
          x=x+2;

        }else if(tiempo<4500){

          x=10;
        }
        tiempo=ofGetElapsedTimeMillis()-inicia;

        if(tiempo>4500){
            alfa=alfa-10;
            x=x-20;

        }
//prueba
        if(tiempo>5000){
          inicia=ofGetElapsedTimeMillis();
          contador++;
          alfa=255;
          x=-100;
        }

        if(contador==images.size()){
          contador=0;

        }
      ofDisableAlphaBlending();



}