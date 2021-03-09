const int trigPin = A0;
const int echoPin = A1;
const int LED     = 3;
const int IR      = A2;

int i,switch_mode;

float duration, distance,duration_on, distance_on;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED,OUTPUT);
  //IR Config 
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(distance<7)
  {
    switch_mode=1;
    while(switch_mode==1)
    {
      for(i=0;i<255;i++)
      {
        analogWrite(LED,i);
        //delay(50);
      }
      delay(75);
      for(i=255;i>=0;i--)
      {
        analogWrite(LED,i);
        //delay(50);
      }
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration_on = pulseIn(echoPin, HIGH);
      distance_on = (duration_on*.0343)/2;
      Serial.print("Distance On: ");
      Serial.println(distance_on);
      delay(100);
      if(distance_on<5)
      break;
    }
   }
   digitalWrite(LED,LOW);
}
