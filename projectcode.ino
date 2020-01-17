int buttonpin=3; 
int valf;
int val;
int tempPin = A1;
int sensorPin = A0;
int lightCal;
int lightVal;
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

void setup()
{  
  pinMode(buttonpin,INPUT);
  lightCal = analogRead(sensorPin);
  Serial.print(lightCal,DEC);
  pinMode(trigPin, OUTPUT);
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(echoPin, INPUT);
 Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000;
float cel = mv/10;
float farh = (cel*9)/5 + 32;
if(digitalRead(2) == HIGH){
Serial.println("Sensor is touched");
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
delay(500);
}
if(digitalRead(2) == LOW){

digitalWrite(13,LOW);
digitalWrite(12,LOW);
delay(500);
}
Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance<30){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  delay(500);
}
else{
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
}
lightVal = analogRead(sensorPin);
  Serial.println(lightVal, DEC); 
 delay(1000);
 if (lightVal < lightCal - 50)
  {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(12,HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(12,LOW);
  }

  
valf=digitalRead(buttonpin); 
if(valf==HIGH) 
{
digitalWrite(13,HIGH); 
digitalWrite(12,HIGH);
}
else
{
digitalWrite(13,LOW);
digitalWrite(12,HIGH); 
}
}
