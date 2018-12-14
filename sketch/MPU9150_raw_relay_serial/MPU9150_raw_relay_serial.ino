// I2C device class (I2Cdev) demonstration Arduino sketch for MPU9150
// 1/4/2013 original by Jeff Rowberg <jeff@rowberg.net> at https://github.com/jrowberg/i2cdevlib
//          modified by Aaron Weiss <aaron@sparkfun.com>
//
// Changelog:
//     2011-10-07 - initial release
//     2013-1-4 - added raw magnetometer output

/* ============================================
I2Cdev device library code is placed under the MIT license

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

#define LED_PIN 13
bool blinkState = false;
const byte numChars = 32;
char receivedChars[numChars];
int stepsize = 100;
boolean newData = false;

int option = -1;
int pin = -1;
void reset(){
  digitalWrite(53,HIGH);
  digitalWrite(51,HIGH);
  digitalWrite(49,HIGH);
  digitalWrite(47,HIGH);
  
}
void parseData(){
    char * strtokIndx;
    strtokIndx = strtok(receivedChars, ",");
    option = atoi(strtokIndx);
    strtokIndx = strtok(NULL, ",");
    pin = atoi(strtokIndx);
}
void cleanup(){
  newData = false;
  option = -1;
  pin = -1;
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
 // if (Serial.available() > 0) {
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

int convertChar(char ch){
  if(int(ch)>96){
    return int(ch)-61;
  }
  if(int(ch)>58){
    return int(ch)-55;
  }
  return int(ch)-48;
}

// option selection
// 1. getSensorXAngle takes two pulls
// 2. getSensorYAngle takes two pulls
// 3. stepMotorUp     takes two pulls
// 4. stepMotorDown   takes two pulls
// 5. bIsMotorsOk     takes two pulls
int control(){

  int results = 0;
  switch(option){
    case 0:
      accelgyro.getAcceleration(&ax, &ay, &az);
      Serial.print('<');
      Serial.print(ax);
      Serial.print(',');
      Serial.print(ay);
      Serial.print(',');
      Serial.print(az);
      Serial.print('>');
    case 1:
      Serial.print(getYSensor());
      break;
    case 2:
      Serial.print(getZSensor());
    case 3:
      Serial.print("<");
      Serial.print(stepMotorUp(pin));
      Serial.print(">");
      break;
    case 4:
      Serial.print("<");
      Serial.print(stepMotorDown(pin));
      Serial.print(">");
      break;
    case 5:
      Serial.print("<");
      Serial.print(bIsMotorsOk());
      Serial.print(">");
      break;
    default:
      return 1;
  }
  return 0;
}


//dum doesnt look at current to see if motor is stalled. Also doesnt take height into count yet.
bool stepMotorUp(int pin){
  
  digitalWrite(pin,LOW);
  delay(2000);
  digitalWrite(pin,HIGH);
  return true;
}
bool stepMotorDown(int pin){
  digitalWrite(51,LOW);
  digitalWrite(53,LOW);
  delay(500);
  digitalWrite(pin,LOW);
  delay(2000);
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(51,HIGH);
  digitalWrite(53,HIGH);
  return true;
}
bool bIsMotorsOk(){
  return false;
};
void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(115200);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    // configure Arduino LED for
    pinMode(LED_PIN, OUTPUT);

    //configuring Relay Pins
    Serial.println("Arduino is ready");
    Serial.println("<1>");
    pinMode(51,OUTPUT); // polarity
    pinMode(53,OUTPUT); // polarity
    pinMode(49,OUTPUT); // motor
    pinMode(47,OUTPUT); // motor
    reset();
}

void loop() {
    
    recvWithStartEndMarkers();
    if(newData == true){
        parseData();
        control();
        cleanup();
    }
}
