#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(24);

    std::string url = "http://puertadev.centroculturadigital.mx/api/activities2/now2";


    if (!response.open(url))
    {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON";
    }

    unsigned int numImages = MIN(10, response.size());
    for(unsigned int i = 0; i < numImages; i++)
     {
         string url = response[i]["imageVision"].asString();
         string txt1 = response[i]["categories"][1].asString();
         string txt2 = response[i]["title"].asString();
         /*string txt3 = response[i]["uniqueBeginDate"].asString();
         string txt4 = response[i]["uniqueEndDate"].asString();*/
         string txt3="Fecha";
         string txt4="hora";

         ofImage img;
         ofHttpResponse resp = ofLoadURL(url);
         img.loadImage(resp.data);
        // images.push_back(img);
          //img.loadImage(url);
         //images.push_back(img);
         Evento tempEvento;
         tempEvento.setup(initX,initY,img,txt1,txt2,txt3,txt4);	// setup its initial state
         miEvento.push_back(tempEvento);
     }


    inicia=ofGetElapsedTimeMillis();
      inicia2=ofGetElapsedTimeMillis();




}
void ofApp::update()
{
  for (int i=0;i<miEvento.size();i++){
      miEvento[i].update();
    }

    }



void ofApp::draw(){
    ofBackground(255);
      miEvento[contador].draw();
  tiempo=ofGetElapsedTimeMillis()-inicia;
    tiempo2=ofGetElapsedTimeMillis()-inicia2;


  if(tiempo>4500){

    contador++;
    inicia=ofGetElapsedTimeMillis();

  }
  if(contador>=miEvento.size()){
      contador=0;
    }
  if(tiempo2>4500){
    if(contador==0){
      miEvento[miEvento.size()-1].dissolve();
    }else{
  miEvento[contador-1].dissolve();
    }
  }
  if(tiempo2>6500){

    inicia2=inicia;

  }







}
