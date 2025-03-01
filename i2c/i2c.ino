//This code is slave and it send and receive the data
#include <Wire.h>
#define SDA_PIN D2       //Declare SCL Pin on NodeMCU 
#define SCL_PIN D1         //Declare SDA Pin on NodeMCU
#define ADDRESS 5

//char msg[] = "";
String msg = "";

void add_char(char msg[], String addition){
  for(int i = 0; i<sizeof(addition); i++){
    int l = sizeof(msg);
    msg[l+1] = addition[i];
  }
}

void setup() {
 Wire.begin(SCL_PIN, SDA_PIN,ADDRESS); //start I2C communication on address 8
 Wire.onReceive(receiveEvent);   //register receive event
 Wire.onRequest(requestEvent);   //register request event
 Serial.begin(9600);             //start serial for debug

 //add_char(msg, "Hallo Pico");
 //add_char(msg, "$");
 //add_char(msg, "1,2,3");

 //String msg = String(msg);
 //Serial.print(msg);
 char sonderzeichen = 36;

 msg.concat("Hallo Poco");
 msg.concat(String(sonderzeichen));
 msg.concat("1,2,3");
 Serial.print(msg);
}

void loop() {
 //Serial.print("\n" + msg);
 //delay(1000);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      //receive byte as a character
    Serial.print(c);           // print the character 
  }
 Serial.println();             // to newline
}

// function that executes whenever data is requested from master
void requestEvent() {
 Wire.write(msg.c_str());  //send string on request
}