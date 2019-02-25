#define LED_PIN1   4
#define LED_PIN2   5
#define LED_PIN3   6
#define LED_PIN4   7

#define LED_PIN5   8
#define LED_PIN6   9
#define LED_PIN7   10
#define LED_PIN8   11
      
int inByte = 0;               
boolean status_bluetooth;
void setup()
{
  Serial.begin(9600); 
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);

  pinMode(LED_PIN5, OUTPUT);
  pinMode(LED_PIN6, OUTPUT);
  pinMode(LED_PIN7, OUTPUT);
  pinMode(LED_PIN8, OUTPUT);
  

  digitalWrite(LED_PIN1, LOW); 
  digitalWrite(LED_PIN2, LOW);  
  digitalWrite(LED_PIN3, LOW); 
  digitalWrite(LED_PIN4, LOW); 
    
  digitalWrite(LED_PIN5, LOW); 
  digitalWrite(LED_PIN6, LOW); 
  digitalWrite(LED_PIN7, LOW);  
  digitalWrite(LED_PIN8, LOW);  
  status_bluetooth = true;
}

void loop()
{
         if (Serial.available() > 0)
         {   
                  	inByte = Serial.read();                     
                  
                  	if(inByte == 'A')
       	     	{        
                        	digitalWrite(LED_PIN1, HIGH);        
    		          Serial.print('A', BYTE);         
      			inByte = 0;     
      	      	}                   
                  	if(inByte == 'a')
                  	{
                        	digitalWrite(LED_PIN1, LOW);       
      		      	Serial.print('a', BYTE);      
     			inByte = 0;     
                 	 }
    
    		if(inByte == 'B')
                  	{
                      	digitalWrite(LED_PIN2, HIGH);     
     			Serial.print('B', BYTE);                   
    			 inByte = 0;     
   		}
    	      	if(inByte == 'b')
                  	{       
                        	digitalWrite(LED_PIN2, LOW);       
      			Serial.print('b', BYTE);                   
      			inByte = 0;     
        	      	}
    
    		if(inByte == 'C')
 		{      
                        	digitalWrite(LED_PIN3, HIGH);        
     			Serial.print('C', BYTE);                    
     			inByte = 0;     
    		}
     		if(inByte == 'c')
                  	{      
                        	digitalWrite(LED_PIN3, LOW);        
      		     	Serial.print('c', BYTE);                    
      			inByte = 0;     
   		}
    
		if(inByte == 'D')
       	      	{        
                        	digitalWrite(LED_PIN4, HIGH);        
    		          Serial.print('D', BYTE);         
      			inByte = 0;     
      	      	}                   
                  	if(inByte == 'd')
                  	{
                        	digitalWrite(LED_PIN4, LOW);       
      		      	Serial.print('d', BYTE);      
     			inByte = 0;     
                  	}
    
    		if(inByte == 'E')
                  	{
                       	 digitalWrite(LED_PIN4, HIGH);     
     			 Serial.print('E', BYTE);                   
    			 inByte = 0;     
   		}
    	         	if(inByte == 'e')
                  	{       
                        	digitalWrite(LED_PIN, LOW);       
      			Serial.print('e', BYTE);                   
      			inByte = 0;     
        	      	}
                  	if(inByte == 'F')
       	      	{        
                        	digitalWrite(LED_PIN6, HIGH);        
    		          Serial.print('F', BYTE);         
      			inByte = 0;     
      	      	}                   
                  	if(inByte == 'f')
                  	{
                        	digitalWrite(LED_PIN6, LOW);       
      		      	Serial.print('f', BYTE);      
     			inByte = 0;     
                  	}
    
    		if(inByte == 'G')
                  	{
                        	digitalWrite(LED_PIN7, HIGH);     
     			Serial.print('G', BYTE);                   
    			inByte = 0;     
   		}
    	          if(inByte == 'g')
                  	{       
                        	digitalWrite(LED_PIN7, LOW);       
      			Serial.print('g', BYTE);                   
      			inByte = 0;     
        	      	}

   		if(inByte == 'H')
                  	{    
                        	digitalWrite(LED_PIN8, HIGH);        
      			Serial.print('H', BYTE);                  
      			inByte = 0;     
  		}
   		if(inByte == 'h')
                  	{    
                        	digitalWrite(LED_PIN8, LOW);        
     			Serial.print('h', BYTE);                   
      			inByte = 0;     
                  	}

    		if(inByte == 'S')
                  	{
                        	Serial.print('S', BYTE);                 
      			status_bluetooth = true;
                  	}             
      	}
}
