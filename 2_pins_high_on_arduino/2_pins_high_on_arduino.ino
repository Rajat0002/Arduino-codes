void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
}
