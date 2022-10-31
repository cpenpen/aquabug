//* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
//*
//* by Dejan Nedelkovski,
//* www.HowToMechatronics.com
//*
//*
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
char strDistance[10]; 
void GetHeight()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication


  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // float to string
  dtostrf(distance,7,2,strDistance); 
  strLogline += ' ';
  strLogline += strDistance;
  strLogline += ';';
}
