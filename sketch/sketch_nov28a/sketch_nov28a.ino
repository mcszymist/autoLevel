const byte numChars = 32;
char receivedChars[numChars];
int stepsize = 100;
boolean newData = false;

int option = -1;
int pin = -1;
void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
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
void loop() {
    recvWithStartEndMarkers();
    if(newData == true){
        parseData();
        control();
        cleanup();
    }
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
    case 1:
      Serial.print("<");
      Serial.print(getSensorX(pin));
      Serial.print(">");
      break;
    case 2:
      Serial.print("<");
      Serial.print(getSensorY(pin));
      Serial.print(">");

      break;
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

int getSensorX(int pin){
  return analogRead("A"+pin);
}
int getSensorY(int pin){
  return analogRead("A"+pin);
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
bool stepMotorDown(int pin+1){
  double stopper = getEncoder(pin)-stepsize;
  while(getEncoder(pin+1)<=stopper){
    digitalWrite(pin,HIGH);
  }
  digitalWrite(pin,LOW);
  return true;
}
bool bIsMotorsOk(){
  return false;
};
