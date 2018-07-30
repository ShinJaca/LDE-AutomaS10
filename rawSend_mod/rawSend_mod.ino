/* rawSend.ino Example sketch for IRLib2
 *  Illustrates how to send a code Using raw timings which were captured
 *  from the "rawRecv.ino" sample sketch.  Load that sketch and
 *  capture the values. They will print in the serial monitor. Then you
 *  cut and paste that output into the appropriate section below.
 */
#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender

// Biblioteca de Ar-condicionado
#include "acFuncs.h";

IRsendRaw mySender;
char ent;

void setup() {
  Serial.begin(9600);
  delay(2000);
  while (!Serial); //delay for Leonardo
  Serial.println(F("[ OK ] Ready"));
}

void loop() {

  while(Serial.available()){
    ent = (char)Serial.read();
    switch(ent){
      case 'l':
      acLiga(mySender);
      break;
      case 'd':
      acDesliga(mySender);
      break;
      case '1':
      acTempMax(mySender);
      break;
      case '2':
      acTempMid(mySender);
      break;
      case '3':
      acTempMin(mySender);
      break;
      default:
      Serial.println("[ERRO] Comando nao reconhecido");
    }
  }
  delay(100);
}
