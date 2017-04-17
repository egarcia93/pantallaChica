#include "ofApp.h"

void ofApp::setup()
{

    ofSetFrameRate(24);


    if (!response.open(url))
    {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON";
    }
    oldResponse=response;

    unsigned int numImages = MIN(10, response.size());

    for(unsigned int i = 0; i < numImages; i++)
     {
         std::string imagen = response[i]["imageVision"].asString();
         std::string txt1 = response[i]["categories"][0].asString();
         std::string txt2 = response[i]["title"].asString();
         std::string txt3 = response[i]["uniqueBeginDate"].asString();
         string txt4 = response[i]["uniqueEndDate"].asString();
         string fecha=cambiarFechaHora(txt3,txt4);

         int pos=fecha.find("&");
         string dia=fecha.substr(0,pos);
         string hora=fecha.substr(pos+1,19);

         ofImage img;
         if(!img.load(imagen)){
           img.load("aux.jpg");
         }


         Evento tempEvento;
         tempEvento.setup(initX,initY,img,txt1,txt2,dia,hora);
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


    //if(tiempo3>3600000&&flag==1){
    if(tiempo3>300000&&flag==1){
      act=false;
      flag=0;
      flag2=false;

      }

}


void ofApp::draw(){

    ofBackground(255);
    tiempo=ofGetElapsedTimeMillis()-inicia;
    tiempo2=ofGetElapsedTimeMillis()-inicia2;

    if(!act&&!flag2){

        inicia4=ofGetElapsedTimeMillis();
        flag2=true;

    }

    if(act){
    miEvento[contador].draw();
  }else{


    miEvento[contador].actualizando();
    tiempo4=ofGetElapsedTimeMillis()-inicia4;

      if(tiempo4>1000){
        actualiza();
  }
  }


    if(tiempo>4500){
      contador++;
      inicia=ofGetElapsedTimeMillis();
      flag=1;

    }

    if(contador>=miEvento.size()){
      contador=0;
    }

  if(act){
    if(tiempo2>4500){
      if(contador==0){
        miEvento[miEvento.size()-1].dissolve();
      }else{
        miEvento[contador-1].dissolve();
      }
    }
  }else{

      miEvento[contador].actualizando();

  }

    if(tiempo2>6500){
      inicia2=inicia;
    }
  }





string ofApp::cambiarFechaHora(string fechaInicial,string fechaFinal)
{

  using namespace boost::posix_time;
  using namespace boost::gregorian;
  typedef boost::date_time::c_local_adjustor<ptime> local_adj;


  int anoI= stoi(fechaInicial.substr(0,4));
  int anoF= stoi(fechaFinal.substr(0,4));

  string mesI=fechaInicial.substr(5,2);
  int mesNumI=stoi(mesI);
  string mesF=fechaFinal.substr(5,2);
  int mesNumF=stoi(mesF);

  int diaI = stoi(fechaInicial.substr(8,2));
  int diaF = stoi(fechaFinal.substr(8,2));


  string hhI=fechaInicial.substr(11,2);
  string hhF=fechaFinal.substr(11,2);
  string mmI=fechaInicial.substr(13,3);
  string mmF=fechaFinal.substr(13,3);
  int hora1=stoi(hhI);
  int hora2=stoi(hhF);


  ptime tI(date(anoI,mesNumI,diaI), hours(hora1));
  ptime tF(date(anoF,mesNumF,diaF), hours(hora2));


  ptime t1 = local_adj::utc_to_local(tI);
  ptime t2 = local_adj::utc_to_local(tF);

  string format_I=to_iso_extended_string(t1);
  string format_F=to_iso_extended_string(t2);



  int ano_I= stoi(format_I.substr(0,4));
  int ano_F= stoi(format_F.substr(0,4));

  string mes_I=format_I.substr(5,2);
  int mesNum_I=stoi(mes_I);
  string mesNombre_I=meses[mesNum_I-1];
  string mes_F=format_F.substr(5,2);
  int mesNum_F=stoi(mes_F);
  string mesNombre_F=meses[mesNum_F-1];

  int dia_I = stoi(format_I.substr(8,2));
  int dia_F = stoi(format_F.substr(8,2));


  string hh_I=format_I.substr(11,2);
  string hh_F=format_F.substr(11,2);
  int hora_1=stoi(hh_I);
  int hora_2=stoi(hh_F);


  if(hora_1>=12&&hora_2>=12){
    hora_1=hora_1-12;
    hora_2=hora_2-12;

    if(hora_1==0){
      hora_1=12;

    }

    if(hora_2==0){
      hora_2=12;
    }

    if(hora_1<=9){
    horaInicio ="0"+to_string(hora_1)+mmI;
    }else{
    horaInicio =to_string(hora_1)+mmI;
    }

    if(hora_2<=9){
    horaFinal="0"+to_string(hora_2)+mmF;
    }else{
    horaFinal=to_string(hora_2)+mmF;
    }
    horaEvento=horaInicio+" "+"PM"+" "+"a"+" "+horaFinal+" "+"PM";




  }else if(hora_1>=12&&hora_2<12){
    hora_1=hora_1-12;



    if(hora_1==0){
      hora_1=12;
    }

    if(hora_2==0){
      hora_2=12;

    }


    if(hora_1<=9){
      horaInicio ="0"+to_string(hora_1)+mmI;
    }else{
      horaInicio =to_string(hora_1)+mmI;
    }

    if(hora_2<=9){
      horaFinal="0"+to_string(hora_2)+mmF;
      }else{
      horaInicio =to_string(hora_2)+mmF;
      }

    horaEvento=horaInicio+" "+"PM"+" "+"a"+" "+horaFinal+" "+"AM";


  }else if(hora_1<12&&hora_2>=12){

    hora_2=hora_2-12;

    if(hora_1==0){
      hora_1=12;
        }

    if(hora_2==0){
      hora_2=12;
    }

    if(hora_1<=9){
      horaInicio ="0"+to_string(hora_1)+mmI;
    }else{
       horaInicio =to_string(hora_1)+mmI;
    }

    if(hora_2<=9){
      horaFinal="0"+to_string(hora_2)+mmF;
    }else{
      horaFinal=to_string(hora_2)+mmF;
    }
   horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"PM";



 }else{

    if(hora_1<=9){
      horaInicio ="0"+to_string(hora_1)+mmI;
    }else{
      horaInicio =to_string(hora_1)+mmI;
    }

    if(hora_2<=9){
      horaFinal="0"+to_string(hora_2)+mmF;
    }else{
      horaFinal=to_string(hora_2)+mmF;
    }
    horaEvento=horaInicio+" "+"AM"+" "+"a"+" "+horaFinal+" "+"AM";

  }

  if(dia_I==dia_F){
    fechaEvento=mesNombre_I+" "+" "+to_string(dia_I);

  }else{

     fechaEvento=mesNombre_I+" "+" "+to_string(dia_I)+" "+"a"+" "+mesNombre_F+" "+to_string(dia_F);

  }

string fecha=(fechaEvento+"&"+horaEvento);
return fecha;

}

void ofApp::actualiza(){

  std::cout << "actualizando" << '\n';
  act=true;
  contador=0;
  flag=0;

  if (!response.open(url))
  {
      ofLogNotice("ofApp::setup") << "Failed to parse JSON";
      //response=oldResponse;
  } else{


  oldResponse=response;
  unsigned int numImages = MIN(10, response.size());

  for(unsigned int i = 0; i < numImages; i++)
  {

    std::string imagen = response[i]["imageVision"].asString();
    std::string txt1 = response[i]["categories"][0].asString();
    std::string txt2 = response[i]["title"].asString();
    std::string txt3 = response[i]["uniqueBeginDate"].asString();
    string txt4 = response[i]["uniqueEndDate"].asString();

    string fecha=cambiarFechaHora(txt3,txt4);
    int pos=fecha.find("&");
    string dia=fecha.substr(0,pos);
    string hora=fecha.substr(pos+1,19);
    ofImage img;

    if(!img.load(imagen)){
      img.load("aux.jpg");
    }

    Evento tempEvento;
    tempEvento.setup(initX,initY,img,txt1,txt2,dia,hora);
    miEvento2.push_back(tempEvento);
    miEvento=miEvento2;
        }

    miEvento2.clear();

    inicia3=ofGetElapsedTimeMillis();


  }
}

void ofApp::keyPressed(int key){
if(key=='r'){

  act=false;
  flag2=false;

}

}
