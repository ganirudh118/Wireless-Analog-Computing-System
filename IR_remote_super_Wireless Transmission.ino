// this code is to decode signals transmitted from TV remote and various funcnalities assigned to various keys of remote.

#include <IRremote.h>

int RECV_PIN=2;
String expression;
String inter;

IRrecv irrecv(RECV_PIN);

decode_results results;


String b="a70";
String enter;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");

  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  while(enter != "2ce9"){
  if (enter != "2ce9"){
  if(irrecv.decode(&results)){
    String a = String(results.value, HEX);
    if (a=="2ce9"){
      
    }

    if(a.length()<=5 && (b=="a70")) 
    {
      Serial.println(a);
      inter = "";
      if (a != "a70"){
          if (a == "10"){
            inter = "1";
          }
          if (a == "810"){
            inter = "2";
          }
          if (a == "410"){
            inter = "3";
          }
          if (a == "c10"){
            inter = "4";
          }
          if (a == "210"){
            inter = "5";
          }
          if (a == "a10"){
            inter = "6";
          }
          if (a == "610"){
            inter = "7";
          }
          if (a == "e10"){
            inter = "8";
          }
          if (a == "110"){
            inter = "9";
          }
          if (a == "910"){
            inter = "0";
          }
          if (a == "fd0"){
            inter = ".";
          }
          if (a == "7123"){
            inter = "(";
          }
          if (a == "1f58"){
            inter = ")";
          }
          if (a == "1ee9"){
            inter = "-";
          }
          if (a == "4ce9"){
            inter = "*";
          }
          if (a == "5ee9"){
            inter = "+";
          }
          if (a == "ce9"){
            inter = "/";
          }
          if (a == "e90"){
            if (expression.length()> 0){
              expression.remove(expression.length() - 1);
          }
          }
          expression = expression + inter;
          Serial.println(expression);
          enter = a;
      }
      
      
    }
    if(a.length()<=5) 
    {
      b=a;
    }
    irrecv.resume();
    //Serial.println("check");
    
  } 
  
  }
  
}


Serial.println("Expression complete");
Serial.println(expression);
}



void loop(){
  
}