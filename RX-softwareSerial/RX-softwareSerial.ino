#include <SoftwareSerial.h>

SoftwareSerial espSerial(10, 11);
String readString, servo1, servo2, servo3, servo4;

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  Serial.println("Begin"); // so I can keep track of what is loaded
}

void loop() {

  while (espSerial.available()) {
    delay(10);
    if (espSerial.available() > 0) {
      char c = espSerial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    }
  }

  if (readString.length() > 0) {
    Serial.print(readString); //see what was received

    // expect a string like 07002100 containing the two servo positions
    String incomming = readString.substring(0, 1);
    if (incomming == "A") {
      servo1 = readString.substring(1, 4);
      Serial.println(" A Done");
    }
    if (incomming == "B") {
      servo2 = readString.substring(1, 4);
      Serial.println(" B Done");
    }
    if (incomming == "C") {
      servo3 = readString.substring(1, 4);
      Serial.println(" C Done");
    }
    if (incomming == "D") {
      servo4 = readString.substring(1, 4);
      Serial.println(" D Done");
    }

    int n1; //declare as number
    int n2;
    int n3;
    int n4;

    char carray1[6]; //magic needed to convert string to a number
    servo1.toCharArray(carray1, sizeof(carray1));
    n1 = atoi(carray1);

    char carray2[6];
    servo2.toCharArray(carray2, sizeof(carray2));
    n2 = atoi(carray2);

    char carray3[6];
    servo3.toCharArray(carray3, sizeof(carray3));
    n3 = atoi(carray3);

    char carray4[6];
    servo4.toCharArray(carray4, sizeof(carray4));
    n4 = atoi(carray4);

    Serial.print("interger = ");
    Serial.print(n1);
    Serial.print(" & ");
    Serial.print(n2);
    Serial.print(" & ");
    Serial.print(n3);
    Serial.print(" & ");
    Serial.println(n4);
    readString = "";
  }
  delay(500);
}
