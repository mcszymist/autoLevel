#define BAUD 9600
char receivedChar;
boolean newData = false;

void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
}

void loop() {
 recvOneChar();
 showNewData();
 
}

void recvOneChar() {
 if (Serial.available() > 0) {
  receivedChar = Serial.read();
  if(receivedChar != '\n')
    newData = true;
 }
}

void showNewData() {
 if (newData == true) {
  Serial.print("This just in ... ");
  Serial.println(receivedChar);
  newData = false;
 }
}
// option selection
// 1. getSensorXAngle takes two pulls
// 2. getSensorYAngle takes two pulls
// 3. stepMotor       takes two pulls
// 4. bIsMotorsOk     takes two pulls
int control(int option){
  switch(option){
    case 1:
      recvOneChar();
      Serial.println(getSensorX(receivedChar));
      break;
    case 2:
      recvOneChar();
      Serial.println(getSensorY(receivedChar));
      break;
    case 3:
      recvOneChar();
      Serial.println(stepMotor(receivedChar));
      break;
    case 4:
      recvOneChar();
      Serial.println(bIsMotorsOk());
      break;
  }
}

double getSensorX(int pin){
  return analogRead(pin);
}
double getSensorY(int pin){
  return analogRead(pin);
}

//dum doesnt look at current to see if motor is stalled. Also doesnt take height into count yet.
bool stepMotor(int pin){
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  return true;
}
bool bIsMotorsOk(){
  return true;
};
