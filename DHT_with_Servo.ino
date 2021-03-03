#include <SoftwareSerial.h>
#include <SimpleDHT.h>
#include <Servo.h>
#include <DHT.h>

Servo myservo;

SimpleDHT22 dht22;


int bluetoothTx = 10;
int bluetoothRx = 11;
int pinDHT22 = 2;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {

  if (bluetooth.available() > 0 )
    {
      int toSend = bluetooth.read();
      Serial.println(toSend);
      myservo.write(toSend);
    }
      byte temperature = 0;
      byte humidity = 0;
      
 if (dht22.read(pinDHT22, &temperature, &humidity, NULL))
  {
    return;
  }
      Serial.print((int)temperature);
      Serial.print("C ");
      Serial.print("/");
      Serial.print((int)humidity);
      Serial.print("% ");
      delay(5000);
}
