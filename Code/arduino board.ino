#include <SPI.h>
#include <MFRC522.h>
#include <Ethernet.h> 
#include "SoftwareSerial.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // creating a MFRC522 object
SoftwareSerial ser(2,3); // RX, TX 
void setup() 
{
  Serial.begin(9600); 
  ser.begin(115200);  // initiating the serial communication
 
  SPI.begin();      // initiating the SPI bus
  mfrc522.PCD_Init();   // initiating MFRC522
  Serial.println("PLEASE PUT RFID TAG IN FRONT OF THE SCANNER...");
  Serial.println();

}
void loop() 
{
  // looking for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // selecting one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  // displaying the cards UID
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Name:    ");
  content.toUpperCase();
  if (content.substring(1) == "97 3D DC 2E" ) // UID of card 1
  {
    Serial.println("1-Rodaba Ebadi");
    ser.write(1);
    Serial.println("Student ID: 100708585");
    Serial.println();
    delay(3000);
  }
   if (content.substring(1) ==  "D3 B4 A7 40" ) // UID of card 2
   { Serial.println("2-Nivetha Gnaneswaran");
    ser.write(2);
    Serial.println("Student ID: 100695935");
    Serial.println();
    delay(3000);
  }
   if (content.substring(1) == "D3 7A 92 1D" ) // UID of card 3
  {
    Serial.println("3-Munazza Fahmeen");
    ser.write(3);
    Serial.println("Student ID:100701595");
    Serial.println();
    delay(3000);
  }
    if (content.substring(1) == "63 80 AC 1D" ) // UID of card 4
  {
    Serial.println("4-Mike Han");
    ser.write(4);
    Serial.println("Student ID: 1234567889");
    Serial.println();
    delay(3000);
  }
  }