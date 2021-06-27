#include <ESP8266WiFi.h>
#include <ThingESP.h>


ThingESP8266 thing("bobyset", "lampu", "123123123");

#define relay 0

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  thing.SetWiFi("RIP", "20202020");

  thing.initDevice();

}


String HandleResponse(String query)
{

  if (query == "idupin lampu sayang") {
    digitalWrite(relay,LOW);
    return "iya udah aku idupin";
  }

  else if (query == "matiin lampu sayang") {
    digitalWrite(relay, HIGH);
    return "ih nyuruh2 terus, iya udah aku matiin";
  }

  else if (query == "coba liat lampunya")
    return digitalRead(relay ) ? "mati sayang" : "idup kok";

  else if (query == "sayang")
    return "iya, kenapa sayang ?";

  else if (query == "hehe")
    return "ada maunya pasti";
    
  else if (query == "makasih ya")
    return "iya, apasih yang nggak buat kamu";
  else return "kamu ngomong apa ? aku gak ngerti";

}


void loop()
{  
  thing.Handle();

}
