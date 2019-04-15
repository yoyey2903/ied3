// Load in the libraries
#include <nRF24L01.h>
#include <RF24.h>

// include the library code:
#include <LiquidCrystal.h>
int x=0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Set the CE & CSN pins
#define CE_PIN   9
#define CSN_PIN 10
int bilgi[1];

// This is the address used to send/receive
const byte rxAddr[6] = "00002";

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN); 
int sem=0, sem1=0;
void setup(void) {
 
 pinMode(A0,INPUT);
 

  pinMode(A1,INPUT);
  

  pinMode(A2,INPUT);





  
  // Start up the Serial connection
  while (!Serial);
  Serial.begin(9600);
  
  // Start the Radio!
  radio.begin();
  
  // Power setting. Due to likelihood of close proximity of the devices, set as RF24_PA_MIN (RF24_PA_MAX is default)
  radio.setPALevel(RF24_PA_MIN); // RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  
  // Slower data rate for better range
  radio.setDataRate( RF24_250KBPS ); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  
  // Number of retries and set tx/rx address
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);

  // Stop listening, so we can send!
  radio.stopListening();
}

void loop() {
//1
//Serial.println(analogRead(A0));
 if (analogRead(A0) >= 900 && sem==0){
  sem=1;  
   bilgi[0] = 1;
   radio.write(bilgi, 1);
   delay(1000);
   Serial.println("1");
 }
if (analogRead(A0) >= 900 && sem==1){
  sem=0;
  Serial.println("5");
    bilgi[0] = 5;
   radio.write(bilgi, 1); 
   delay(1000);
}
//2
if (analogRead(A1) >= 900 && sem1==0){
  sem1=1;  
  Serial.println("2");
   bilgi[0] = 2;
   radio.write(bilgi, 1);
   delay(1000);
    
     
 }
 if (analogRead(A1) >= 900 && sem1==1){
  sem1=0;  
   bilgi[0] = 6;
   Serial.println("6");
   radio.write(bilgi, 1); 
   delay(1000);
 }

if (analogRead(A2) >= 900){
  x=0;
    Serial.println("3");
   bilgi[0] = 3;
   radio.write(bilgi, 1);
   delay(100);
    bilgi[0] = 3;
   radio.write(bilgi, 1);
   
 }
 if (analogRead(A2) <900 && x==0){
  x=1;
  Serial.println("4");
 bilgi[0] = 4;
   radio.write(bilgi, 1);
   delay(200);
   bilgi[0] = 4;
   radio.write(bilgi, 1);
   delay(200);
   bilgi[0] = 4;
   radio.write(bilgi, 1);
   delay(200);
  
 }
 
 

}
