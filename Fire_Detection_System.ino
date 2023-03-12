int ledpin=13; 
int Flame_sensor_pin=9;
int Buzpin=7;
int motorPin=4;
int flamesensvalue=0;
int count=0; 
void setup() 
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(Flame_sensor_pin,INPUT);
  pinMode(Buzpin,OUTPUT);
  pinMode(motorPin,OUTPUT);
}

void led_buz_blink()
{
  digitalWrite(ledpin,HIGH);
  digitalWrite(Buzpin,HIGH);
  delay(400);
  digitalWrite(ledpin,LOW);
  digitalWrite(Buzpin,LOW);  
  delay(200);
  digitalWrite(ledpin,HIGH);
  digitalWrite(Buzpin,HIGH);
  delay(400);
  digitalWrite(ledpin,LOW);
  digitalWrite(Buzpin,LOW);
  delay(200);
}
void loop() 
{
  flamesensvalue=digitalRead(Flame_sensor_pin); 
  if (flamesensvalue==LOW) 
  {
    led_buz_blink();
    digitalWrite(motorPin,HIGH);
    led_buz_blink();
    count++;
  }
  else if(count>0 && flamesensvalue==HIGH)
  {
    digitalWrite(Buzpin,LOW);
    digitalWrite(ledpin,HIGH);  
    digitalWrite(motorPin,HIGH);
    delay(10000);
    digitalWrite(motorPin,LOW);
    digitalWrite(Buzpin,HIGH);
    delay(500);
    digitalWrite(Buzpin,LOW);
    count=0;
  }
  else
  {
    digitalWrite(ledpin,LOW);
    digitalWrite(Buzpin,LOW);
    digitalWrite(motorPin,LOW);
  }
}