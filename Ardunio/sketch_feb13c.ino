void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(9,HIGH);
  delay(200);
  digitalWrite(12,LOW);
  digitalWrite(8,LOW);
  digitalWrite(13,LOW);
  digitalWrite(7,LOW);
  digitalWrite(4,LOW);
  digitalWrite(2,LOW);
  digitalWrite(10,LOW);
  digitalWrite(5,LOW);
  digitalWrite(9,LOW);
  delay(200);

}
