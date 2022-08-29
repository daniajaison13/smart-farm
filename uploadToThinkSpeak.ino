#include<ESP8266WiFi.h>

#include<WiFiClient.h>

#include <ThingSpeak.h>

int sensor_pin = A0;

int output_value ;

const char* ssid="reema";

const char* password="123reema";

unsigned long myChannelNumber = 566087;

const char * myWriteAPIKey = "B2EXUMGOFJRXVX2D";

int moisture;

WiFiClient client;

void setup() {

Serial.begin(115200);

Serial.println();

Serial.print("connecting to ");

Serial.println(ssid);

WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {

delay(500);

Serial.print(".");

}

Serial.println("");

Serial.println("WiFi connected");

Serial.println("IP address: ");

Serial.println(WiFi.localIP());

ThingSpeak.begin(client);

pinMode(16,OUTPUT);

}

void loop() {

output_value= analogRead(sensor_pin);

output_value = map(output_value,1023,0,0,100);

if(output_value < 50)

{

digitalWrite(16,HIGH);

delay(100);

}

else{

digitalWrite(16,LOW);

delay(100);

}

ThingSpeak.writeField(myChannelNumber, 1, output_value, myWriteAPIKey); //Write data to channel

delay(15000); ///delay required for thingspeak data to upload.

}
