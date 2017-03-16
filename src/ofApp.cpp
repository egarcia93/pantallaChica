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
         std::string imagen = response[i]["imageVision"].asString();
         std::string txt1 = response[i]["categories"][1].asString();
         std::string txt2 = response[i]["title"].asString();
         std::string txt3 = response[i]["uniqueBeginDate"].asString();
         string txt4 = response[i]["uniqueEndDate"].asString();
        // std::string fecha=cambiarFecha(txt3);
         //std::string hora=cambiarHora(txt3,txt4);
         string fecha=cambiarFechaHora(txt3,txt4);
         int pos=fecha.find("&");

         string dia=fecha.substr(0,pos);
         string hora=fecha.substr(pos+1,19);

         // std::string txt3="Fecha";
         // std::string txt4="hora";

         ofImage img;
         // ofHttpResponse resp = ofLoadURL(url);
         //img.loadImage(resp.data);
         // images.push_back(img);
         img.loadImage(imagen);
         //images.push_back(img);
         Evento tempEvento;
         tempEvento.setup(initX,initY,imagen,txt1,txt2,dia,hora);
         miEvento.push_back(tempEvento);
     }


     inicia=ofGetElapsedTimeMillis();
     inicia2=ofGetElapsedTimeMillis();
     inicia3=ofGetElapsedTimeMillis();


}

void ofApp::update()
{
  for (int i=0;i<miEvento.size();i++){
    miEvento[i].update();
    }

    tiempo3=ofGetElapsedTimeMillis()-inicia3;

    if(tiempo3>3600000&&flag==1){
        flag=0;
        std::string url = "http://puertadev.centroculturadigital.mx/api/activities2/now2";

        if (response.open(url))
         {


         }

         unsigned int numImages = MIN(10, response.size());
         for(unsigned int i = 0; i < numImages; i++)
          {
              std::string imagen = response[i]["imageVision"].asString();
              std::string txt1 = response[i]["categories"][1].asString();
              std::string txt2 = response[i]["title"].asString();
              std::string txt3 = response[i]["uniqueBeginDate"].asString();
              string txt4 = response[i]["uniqueEndDate"].asString();
              string fecha=cambiarFechaHora(txt3,txt4);
              int pos=fecha.find("&");

              string dia=fecha.substr(0,pos+1);
              string hora=fecha.substr(pos+1,5);


              //std::string txt3="Fecha";
              //std::string txt4="copiado";

              ofImage img;
              img.loadImage(imagen);
              Evento tempEvento;
              tempEvento.setup(initX,initY,imagen,txt1,txt2,fecha,hora);
              miEvento2.push_back(tempEvento);
              miEvento=miEvento2;
            }
            inicia3=ofGetElapsedTimeMillis();
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
      flag=1;

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
/*
string ofApp::cambiarFecha(string fecha){
  std::string str=fecha;
  std::string dia = str.substr(8,2);

  if(dia.substr(0,1)=="0"){
    dia=dia.substr(1,1);
  }

  std::string mes=str.substr(5,2);
  int mesNum=stoi(mes);
  string mesNombre=meses[mesNum-1];
  string fechaEvento=mesNombre+" "+" "+dia;
  return fechaEvento;

}

string ofApp::cambiarHora(string fechaInicio,string fechaFinal){

    std::string str1=fechaInicio;
    std::string horaI=str1.substr(11,5);
    std::string str2=fechaFinal;
    std::string horaF=str2.substr(11,5);
    string hhI=horaI.substr(0,2);
    string hhF=horaF.substr(0,2);
    string mmI=horaI.substr(2,3);
    string mmF=horaF.substr(2,3);
    int hora1=(stoi(hhI))-6;
    int hora2=(stoi(hhF))-6;

    if(hora1>12&&hora2>12){
      hora1=hora1-12;
      hora2=hora2-12;

      if(hora1<9){
      horaInicio ="0"+to_string(hora1)+mmI;
      }else{
      horaInicio =to_string(hora1)+mmI;
      }

      if(hora2<9){
      horaFinal="0"+to_string(hora2)+mmF;
      }else{
      horaFinal=to_string(hora2)+mmF;
      }
      horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"AM";
        return horaEvento;



    }else if(hora1>12){

      hora1=hora1-12;

      if(hora1<9){
        horaInicio ="0"+to_string(hora1)+mmI;
      }else{
        horaInicio =to_string(hora1)+mmI;
      }

      if(hora2<9){
        horaFinal="0"+to_string(hora2)+mmF;
        }else{
        horaInicio =to_string(hora2)+mmF;
        }

      horaEvento=horaInicio+" "+"PM"+" "+"a"+" "+horaFinal+" "+"AM";
        return horaEvento;

      }else if(hora2>12){

      hora2=hora2-12;
      if(hora1<9){
        horaInicio ="0"+to_string(hora1)+mmI;
      }else{
         horaInicio =to_string(hora1)+mmI;
      }

      if(hora2<9){
        horaFinal="0"+to_string(hora2)+mmF;
      }else{
        horaFinal=to_string(hora2)+mmF;
      }
     horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"PM";
       return horaEvento;


   }else{

      if(hora1<9){
        horaInicio ="0"+to_string(hora1)+mmI;
      }else{
        horaInicio =to_string(hora1)+mmI;
      }

      if(hora2<9){
        horaFinal="0"+to_string(hora2)+mmF;
      }else{
        horaFinal=to_string(hora2)+mmF;
      }
      horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"AM";
      return horaEvento;
    }

}*/
string ofApp::cambiarFechaHora(string fechaInicial,string fechaFinal){

  std::string horaI=fechaInicial.substr(11,5);
  std::string horaF=fechaFinal.substr(11,5);

  string hhI=horaI.substr(0,2);
  string hhF=horaF.substr(0,2);
  string mmI=horaI.substr(2,3);
  string mmF=horaF.substr(2,3);
  int hora1=(stoi(hhI))-6;
  int hora2=(stoi(hhF))-6;



  std::string diaTmp = fechaInicial.substr(8,2);



  if(diaTmp.substr(0,1)=="0"){
    diaTmp=diaTmp.substr(1,1);
  }

  int diaNum=stoi(diaTmp);

  std::string mes=fechaInicial.substr(5,2);
  int mesNum=stoi(mes);
  string mesNombre=meses[mesNum-1];

  if (hora1<=0){
    diaNum-1;
    hora1=12+hora1;

  }
  if (hora2<=0){
    hora2=12+hora2;

  }
  if(hora1>12&&hora2>12){
    hora1=hora1-12;
    hora2=hora2-12;

    if(hora1<9){
    horaInicio ="0"+to_string(hora1)+mmI;
    }else{
    horaInicio =to_string(hora1)+mmI;
    }

    if(hora2<9){
    horaFinal="0"+to_string(hora2)+mmF;
    }else{
    horaFinal=to_string(hora2)+mmF;
    }
    horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"AM";




  }else if(hora1>12){

    hora1=hora1-12;

    if(hora1<9){
      horaInicio ="0"+to_string(hora1)+mmI;
    }else{
      horaInicio =to_string(hora1)+mmI;
    }

    if(hora2<9){
      horaFinal="0"+to_string(hora2)+mmF;
      }else{
      horaInicio =to_string(hora2)+mmF;
      }

    horaEvento=horaInicio+" "+"PM"+" "+"a"+" "+horaFinal+" "+"AM";


    }else if(hora2>12){

    hora2=hora2-12;
    if(hora1<9){
      horaInicio ="0"+to_string(hora1)+mmI;
    }else{
       horaInicio =to_string(hora1)+mmI;
    }

    if(hora2<9){
      horaFinal="0"+to_string(hora2)+mmF;
    }else{
      horaFinal=to_string(hora2)+mmF;
    }
   horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"PM";



 }else{

    if(hora1<9){
      horaInicio ="0"+to_string(hora1)+mmI;
    }else{
      horaInicio =to_string(hora1)+mmI;
    }

    if(hora2<9){
      horaFinal="0"+to_string(hora2)+mmF;
    }else{
      horaFinal=to_string(hora2)+mmF;
    }
    horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"AM";

  }
string fechaEvento=mesNombre+" "+" "+to_string(diaNum);

string fecha=(fechaEvento+"&"+horaEvento);

return fecha;


}
