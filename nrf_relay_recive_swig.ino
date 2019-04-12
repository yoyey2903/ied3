// Load up the libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int i=0, j=0;
// define the pins
#define CE_PIN   9
#define CSN_PIN 10

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN); 
int bilgi[1]; 


int bilgi1[1];


// The tx/rx address
const byte rxAddr[6] = "00002";

void setup(void)
{

  // Start the serial
  Serial.begin(9600);
  while(!Serial);
  Serial.println("NRF24L01P Receiver Starting...");
  
  pinMode(2,OUTPUT);
 digitalWrite(2,HIGH);



  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);

  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);

   
  
  // Start the radio, again set to min & slow as I'm guessing while testing theire really close to each other
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);   // RF24_PA_MIN ,RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate( RF24_250KBPS ); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  
  // Set the reading pipe and start listening
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
  
}

void loop(void){





if(i==1)
{
   

 digitalWrite(2,LOW);
delay(500);
 digitalWrite(2,HIGH);
delay(500);


  
}
 if(j==1)
{
   

 digitalWrite(3,LOW);
delay(500);
 digitalWrite(3,HIGH);
delay(500);


  
}
 if (radio.available()){
     
     radio.read(bilgi, 1);
    //1 
   // Serial.println(bilgi[0]);
     



 
 //2
      if (bilgi[0] == 1)
     {
     i=1;
  
   Serial.println("1");
  }  
if (bilgi[0] == 5)
     {
     i=0;
  
    Serial.println("5");
  } 
 if (bilgi[0] == 2)
     {
     j=1;
   Serial.println("2");
   
  }  
if (bilgi[0] == 6)
     {
     j=0;
   Serial.println("6");
   
  } 
    
  //3LEFT

    if (bilgi[0] == 3)
     {
      
   Serial.println("3");
 
  digitalWrite(4,LOW);
 
  }


  //4RIGHT

    if (bilgi[0] == 4)
     {
       Serial.println("4");
 
  digitalWrite(4,HIGH);
  
  
  
  
  }
  
  

  

  }
 
}


 

