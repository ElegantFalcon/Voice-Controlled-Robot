#include <SoftwareSerial.h>
String value;
int T = 11;
int R = 10;
SoftwareSerial bluetooth(T, R);
#define echoPin 8
#define trigPin 9 
long duration; 
int distance; 
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  bluetooth.begin(9600);

}

void loop() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance > 15 ) 
  {
 

  if (bluetooth.available())
   {
    value = bluetooth.readString();
   }
    Serial.println(value);
    if(value=="forward" ||value =="Forward")
    {
       //Forward
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);  
    }
    if(value=="backward" || value=="Backward")
    {
       //Backward
              digitalWrite(3,HIGH);
              digitalWrite(4,LOW);
              digitalWrite(5,HIGH);
              digitalWrite(6,LOW);
  
    }
    if(value=="Right" || value=="right")
     {
      //Right
              digitalWrite(3,LOW);
              digitalWrite(4,HIGH);
              digitalWrite(5,LOW);
              digitalWrite(6,LOW);
     }
  if(value=="Left" || value=="left")
         {
                  //LEFT
                 digitalWrite(3,LOW);
                 digitalWrite(4,LOW);
                 digitalWrite(5,LOW);
                 digitalWrite(6,HIGH);
   

          }
  
  if(value=="Stop" ||value=="stop")
  {

     //stop
                 digitalWrite(3,LOW);
                 digitalWrite(4,LOW);
                 digitalWrite(5,LOW);
                 digitalWrite(6,LOW);
    }
  }
  if (distance < 14 ) 
  {
     digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   delay(1000);

   if (bluetooth.available())
   {
    value = bluetooth.readString();
   
   if(value=="backward" || value=="Backward")
    {
       //Backward
              digitalWrite(3,HIGH);
              digitalWrite(4,LOW);
              digitalWrite(5,HIGH);
              digitalWrite(6,LOW);
    }
    }
  }

}


  
                 


                 

                 
    
    
    
