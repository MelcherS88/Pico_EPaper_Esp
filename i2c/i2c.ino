#include <Wire.h>

#define SDA_PIN D1         //Declare SCL Pin on NodeMCU 
#define SCL_PIN D2         //Declare SDA Pin on NodeMCU

const int16_t I2C_SLAVE = 0x08;

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN, I2C_SLAVE);  // join i2c bus with address #8
  Wire.onReceive(receiveEvent);             // register event
  Serial.begin(115200);
  Serial.print("init");                     // start serial for output
}

void loop() {
  Serial.print("wait\n");
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
}