//Dev: acharismas

//Define Pins
//Motor A
int enableA = 7;
int MotorA1 = 6;
int MotorA2 = 5;
 
//Motor B
int enableB = 8;
int MotorB1 = 9;
int MotorB2 = 10;

//WiFi module
int leftright = 3;
int val = 0;  
int savedstate = 0;

//Setup
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin (9600);
  //configure pin modes
  pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  
  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT); 
  pinMode (leftright,INPUT); 
 
}

void loop() {
  //enabling motor 

  val = digitalRead(leftright); 
if (val != savedstate) {  
  if (val == HIGH) 
  {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);

  
  Serial.println ("Motion Left");
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, HIGH);
  
  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);

   
  //3s forward
  delay (1800);
  

  Serial.println ("Stoping motors");
  //stop
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, LOW);
    
   delay (2000); 
  }
  else if (val == LOW)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW); 
    digitalWrite (enableA, HIGH);
    digitalWrite (enableB, HIGH);
    
    Serial.println ("Motion Right");
    //reverse
    
    digitalWrite (MotorA1,HIGH);
    digitalWrite (MotorA2,LOW);  
    
    digitalWrite (MotorB1,HIGH);
    digitalWrite (MotorB2,LOW);
   
    //5s backwards
    delay (1800);
     


    Serial.println ("Stoping motors");
    //stop
    digitalWrite (enableA, LOW);
    digitalWrite (enableB, LOW);
    
    delay (2000);
  }
  savedstate = val;
  }
}
                      
