#include &lt;LiquidCrystal.h&gt;

#include &lt;DHT.h&gt;

#define DHTPIN 6

// what pin we&#39;re connected to

#define DHTTYPE DHT11 // DHT 11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup()

{

Serial.begin(9600);

pinMode(13, OUTPUT);

for (int DigitalPin = 7; DigitalPin &lt;= 9; DigitalPin++)

{

pinMode(DigitalPin, OUTPUT);

}

}

lcd.begin(16,2); //16 by 2 character display

dht.begin();

}

void loop()

{

delay(1000);

int A = analogRead(A1);

if (A &lt; 200) { // Change 100 to the number depending on the light in your area.

digitalWrite(13, HIGH);

}

else {

digitalWrite(13, LOW);

}

// Reading temperature or humidity takes about 250 milliseconds!

// Sensor readings may also be up to 2 seconds &#39;old&#39; (its a very slow sensor)

float h = dht.readHumidity();

// Read temperature as Celsius (the default)

float t = dht.readTemperature();

int a = analogRead(6)+30;

Serial.println(analogRead(6));

Serial.println(t);

lcd.clear();

lcd.setCursor(0,0);

lcd.print(&quot;Temp: &quot;);

lcd.print(a);

lcd.print(&quot;K&quot;);

if (t&lt;=22)

{

digitalWrite(7, HIGH);

digitalWrite(8, LOW);

digitalWrite(9, LOW);

}

else if (t&gt;22)

{

digitalWrite(8, HIGH);

digitalWrite(7, LOW);

digitalWrite(9, LOW);

}

else if (t&gt;=35)

{

digitalWrite(9, HIGH);

digitalWrite(7, LOW);

digitalWrite(8, LOW);
}
