#include <SoftwareSerial.h>
#define K_READ 0
SoftwareSerial mySerial(8, 9); // RX, TX
byte Request_From_Hercules[6]= {0};              //  0x11 orjinali 0x18 ile değiştirdim. 
char Respond_From_ECU[8]= {0x48, 0x6b,0x10,0x41,0x0c,0x11,0x1c,0x3d};

byte Request_TRUE_CHECK[6]={0x68, 0x6a, 0xf1, 0x01, 0x0c, 0xd0};
void setup() {
  // put your setup code here, to run once:
  delay(2000);
 mySerial.begin(4800);
  mySerial.println("Hello, world?");
  pinMode(K_READ, INPUT);
  digitalWrite(K_READ,HIGH);
    Serial.begin(10400);
    delay (200);

}
void serial_rx_off() {
  UCSR0B &= ~(_BV(RXEN0));  //disable UART RX
}
void serial_rx_on() {
  Serial.begin(10400);
}

void serial_tx_off() {

   UCSR0B &= ~(_BV(TXEN0));  //disable UART TX
   delay(20);                 //allow time for buffers to flush
}
void loop() {
  serial_rx_off();
  // put your main code here, to run repeatedly:
  int a= 0; 
  while(a<3) {
   if( digitalRead(K_READ)== LOW){
   a++; 
   delay (500); }
  
    }
  
 mySerial.println("init ok");
  
 // Serial.begin(10400);
delay (250); 
char b=0x55;
Serial.print(b);
b=0x08;
delay(25);
Serial.print(b);
delay(25);
Serial.print(b);
delay(15);
serial_rx_on();
delay(10);
while(!Serial.available()){}
delay(33);
serial_rx_off();
b=0xCC;
Serial.print(b);
delay(25);
serial_rx_on();
while(Serial.available()){Serial.read();}
int CharPointer = 0;
while(CharPointer<6){

   if (Serial.available())
    {
      
      
     byte readData = Serial.read();
     delay(1);
      mySerial.print("DATA ");
      mySerial.println(readData,HEX);
      Request_From_Hercules[CharPointer]= readData;
      CharPointer++; 
      //mySerial.println("");
     }
      
    }
//    for(CharPointer=0; CharPointer<6; CharPointer++)
//   mySerial.print( Request_From_Hercules[CharPointer],HEX);
delay(23);
      // Check The comming data
bool checkHerculesData =true; 
for(CharPointer=0; CharPointer<6; CharPointer++)
{
   if (Request_From_Hercules[CharPointer] == Request_TRUE_CHECK[CharPointer])
   checkHerculesData =true; 
   else 
   checkHerculesData =false; 
   
} 
  
if (checkHerculesData)
{
   mySerial.println("Request SUCCES");
   CharPointer=0; 
   while(CharPointer<8)
   {
      Serial.print(Respond_From_ECU[CharPointer]);
      CharPointer++;
      delay(5);
   }
      mySerial.println("RPM Send ");
      
}

while(Serial.available()){Serial.read();}
 CharPointer = 0;
while(CharPointer<6){

   if (Serial.available())
    {
      
      
     byte readData = Serial.read();
     delay(1);
      mySerial.print("DATA ");
      mySerial.println(readData,HEX);
      Request_From_Hercules[CharPointer]= readData;
      CharPointer++; 
      //mySerial.println("");
     }
      
    }
//    for(CharPointer=0; CharPointer<6; CharPointer++)
//   mySerial.print( Request_From_Hercules[CharPointer],HEX);
delay(23);
      // Check The comming data
 checkHerculesData =true; 
for(CharPointer=0; CharPointer<6; CharPointer++)
{
   if (Request_From_Hercules[CharPointer] == Request_TRUE_CHECK[CharPointer])
   checkHerculesData =true; 
   else 
   checkHerculesData =false; 
   
} 
  
if (checkHerculesData)
{
   mySerial.println("Request SUCCES");
   CharPointer=0; 
   Respond_From_ECU[5]=0x18;
   while(CharPointer<8)
   {
      Serial.print(Respond_From_ECU[CharPointer]);
      CharPointer++;
      delay(5);
   }
      mySerial.println("RPM Send ");
      
}
mySerial.println("Simulator done!");
while(1){}
}
