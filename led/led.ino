int soundsensor=A0;
int led=13;
int threshhold=200;
void setup() {
  // put your setup code here, to run once:
  pinMode(soundsensor,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorvalue=digitalRead(soundsensor);
  if(soundsensor>=threshhold){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
  }

}
