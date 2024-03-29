void setup() {

#define Bled 1
#define Gled 2
#define Yled 3 
#define Rled 4
#define buzzer 5 
#define trigPin 6 
#define echoPin 8
#define RGBb 7 
#define photocell 11

Serial.begin(9600); 
pinMode(Bled,OUTPUT);
pinMode(Gled,OUTPUT);
pinMode(Yled,OUTPUT);
pinMode(Rled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(RGBb,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
//RGB LIGHT SENSOR
int value=analogRead(photocell);//Read the value from the light sensor to determin conditions.
Serial.println(value); // print value from light sensor to show in Serial Monitor.

if(value <480 ){ //readings 
digitalWrite(RGBb, HIGH);

}
else{ 
  digitalWrite(RGBb,LOW);
  
}


  

//===Distance Sensor===
long duration, distance, inches;


digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);


//Reads the echo Signal
duration=pulseIn(echoPin,HIGH);//Read duration for roundtrip distance.
distance=(duration / 2) * 0.0135 ;//Convert duration to one way distance to one way distacne in units of inches

if(distance < 100 ){//filter noise to show reading only less than 200
Serial.println(distance);//print distance.

if (distance <= 6){//Alert Conditions

  digitalWrite(Rled ,HIGH); //Alerting conditions
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,LOW);
  digitalWrite(Bled,LOW);
  tone(buzzer,1000,500); 

 }
 else if(distance <24 and distance>10){//Alert object moving closer.
 
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,HIGH);
  digitalWrite(Gled,LOW);
  digitalWrite(Bled,LOW);  

  tone(buzzer,50,100);//emit tone at 300 hz of 400milliseconds.
 }  
 }
   
if(distance< 40 and distance>20){ //Warning object too close
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,HIGH);//safe
  digitalWrite(Bled,LOW);
  
  
tone(buzzer,50,100);//emits tone at 300hz of 400 milliseconds. 
   }
   
  if(distance<68 and distance> 36){
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,LOW);
  digitalWrite(Bled,HIGH);

}//end of else

delay(1000);
}
//RGB LIGHT Sensor
  
  }
