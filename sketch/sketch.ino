#define BAUD 9600
char incomingByte[100];   // for incoming serial data

void setup(){
  Serial.begin(BAUD);
}

void loop(){
  Serial.flush(); 
  if (Serial.available() > 0) {
    // read the incoming byte:
    Serial.readBytesUntil("\n",incomingByte,100);
    if(inc)
    Serial.println(incomingByte);
  }
}
