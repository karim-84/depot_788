
#include "DHTLib_GPA788.h"   
const uint8_t DHT11_PIN{7};
dhtlib_gpa788 myDHT;

unsigned count{0};
void setup() {
  Serial.begin(115200);
  Serial.println(F("Test de DHTlib"));  
}
void loop() {
DHTLIB_ErrorCode chk {myDHT.read11(DHT11_PIN)};
if (chk== DHTLIB_ErrorCode::DHTLIB_OK){
  Serial.print(F("Échantillon: "));Serial.println(++count);
  Serial.print(F("Temperature =  "));Serial.println(myDHT.getTemperature());
  Serial.print(F("Hymidité =  "));Serial.println(myDHT.getHumidity());

}else{
  Serial.print(F("Erreur=  ")); Serial.println(static_cast<int>(chk));
}
delay(1000);
unsigned long time_now = millis();
while(millis()< time_now + 2000);

}