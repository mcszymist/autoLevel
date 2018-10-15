#define BAUD 9600
char receivedOptionChar;
char recievedParaChar;
boolean newData = false;
int stepsize = 100;
void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
}
//all acess should be done with a two char system
void loop() {
 if(recvChar()==1){
    control(convertChar(receivedOptionChar));
 };
 cleanup();

}
void cleanup(){
  receivedOptionChar = "";
  recievedParaChar = "";
  newData = false;
}
int recvChar() {
 if (Serial.available() > 0) {
  receivedOptionChar = Serial.read();
  if(receivedOptionChar != '\n')
    receivedParaChar = Serial.read();
    newData = true;
    return 1;
  }
  return 0;
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

void showNewData() {
 if (newData == true) {
  Serial.print("This just in ... ");
  Serial.println(convertChar(receivedOptionChar));
  newData = false;
 }
}
// option selection
// 1. getSensorXAngle takes two pulls
// 2. getSensorYAngle takes two pulls
// 3. stepMotorUp     takes two pulls
// 4. stepMotorDown   takes two pulls
// 5. bIsMotorsOk     takes two pulls
int control(int option){
  switch(option){
    case 1:
      Serial.println(getSensorX(recievedParaChar));
      break;
    case 2:
      Serial.println(getSensorY(recievedParaChar));
      break;
    case 3:
      Serial.println(stepMotorUp(recievedParaChar));
      break;
    case 4:
      Serial.println(stepMotorDown(recievedParaChar));
      break;
    case 5:
      Serial.println(bIsMotorsOk());
      break;
    default:
      return 1;
  }
  return 0;
}

double getSensorX(int pin){
  return analogRead(pin);
}
double getSensorY(int pin){
  return analogRead(pin);
}
double getEncoder(int pin){
  
}
//dum doesnt look at current to see if motor is stalled. Also doesnt take height into count yet.
bool stepMotorUp(int pin){
double stopper = getEncoder(pin)+stepsize;
  while(getEncoder(pin)>=stopper){
    digitalWrite(pin,HIGH);
  }
  digitalWrite(pin,LOW);
  return true;
}
bool stepMotorDown(int pin){
  double stopper = getEncoder(pin)-stepsize;
  while(getEncoder(pin)<=stopper){
    digitalWrite(pin,HIGH);
  }
  digitalWrite(pin,LOW);
  return true;
}
bool bIsMotorsOk(){
  return false;
};
