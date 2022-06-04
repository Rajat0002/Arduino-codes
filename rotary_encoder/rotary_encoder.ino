
 #define outputA 6
 #define outputB 7

 int counter = 0; 
 int currentvalue;
 int Lastvalue; 
 int angle; 


 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode(13, OUTPUT);
   
   Serial.begin (9600);
  
   Lastvalue = digitalRead(outputA);   
 } 

 void loop() { 
  
   currentvalue = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (currentvalue != Lastvalue){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != currentvalue) { 
       counter ++;
       angle++;
     } else {
       counter --;
       angle--;
     }
    
     
      angle= (counter * 9) - 9;
     
    
     if (angle > 360)
     {
      counter = 0;
      
     }
      if(angle<=180)
      { Serial.println("here");
        digitalWrite(13, HIGH);   
      }
      else digitalWrite(13,LOW);
     //Serial.println(counter);
     Serial.println(angle);
     Serial.println("  deg");
    
   } 
   Lastvalue = currentvalue; 
   
   
 }
 
