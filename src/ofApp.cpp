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




}
void ofApp::update()
{
  for (int i = 0; i<miEvento.size(); i++) {
      miEvento[i].update();
  }


}
void ofApp::draw(){

  ofBackground(255);
  miEvento[1].draw();

  tiempo=ofGetElapsedTimeMillis()-inicia;





/*
{
     ofBackground(255);
     for (int i = 0 ; i<miEvento.size(); i++) {
    miEvento[i].draw();
}
*/

     /*ofEnableAlphaBlending();

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

*/

}
