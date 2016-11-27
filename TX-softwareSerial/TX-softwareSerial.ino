#include <SoftwareSerial.h>
SoftwareSerial ardSerial(2, 3); // Arduino RX, Arduino TX

void setup() {
  Serial.begin(9600);
  ardSerial.begin(9600);
  delay(1000);

}

void loop() {
  // sent data to esp8266
  int data_a = 9;
  int data_b = 50;
  int data_c = 120;
  int data_d = 255;

  char buffer1 [10];
  char buffer2 [10];
  char buffer3 [10];
  char buffer4 [10];
  ardSerial.write("A");
  itoa (data_a, buffer1, 10);
  ardSerial.write(buffer1);
  delay(250);
  ardSerial.write("B");
  itoa (data_b, buffer2, 10);
  ardSerial.write(buffer2);
  delay(250);
  ardSerial.write("C");
  itoa (data_c, buffer3, 10);
  ardSerial.write(buffer3);
  delay(250);
  ardSerial.write("D");
  itoa (data_d, buffer4, 10);
  ardSerial.write(buffer4);
  delay(250);

}
