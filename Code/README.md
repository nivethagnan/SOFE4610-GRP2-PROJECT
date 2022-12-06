# Code
This folder contains all the files of the code necessary to run our IoT project. For our project we needed two programs, one for the Arduino board and one for the Node MCU board. You need to upload both of these codes to Arduino and NodeMCU. 

For the arduino board we needed to download the MFRC522 Library. The MFRC522 library is used for the RFID scanner. The SDA and RST pins on the RFID scanner are connected with pin 10 and pin 9 of the Arduino. The software serial line was where we made the connection to the NodeMCU so the packets could be sent, therefore being able to send the data to adafruit. Inside the setup function, we initialize the Serial communication at 9600 and software serial at 115200 baud rate. We have also opened communication with MFRC522. Inside the void loop function, we will check if a new card is present, and if a new card is present, then it will check the UID of the card. For a valid card, it will print the UID of the card with the students name and the value assigned to that student. Otherwise it will print ‘unauthorized card.’ Similarly, ser.write function has numbers 1 through how many numbers the prof would like to assign to the students, in our case we have 1-4 since we have four tags in total. These numbers are the card serial number which will be uploaded in the Adafruit dashboard. You can assign these numbers to the respective student names to keep easy track for attendance. These names will be displayed on the serial monitor while scanning, along with their serial number and UID. 

For the nodemcu we needed to downloaded the MQTT library. We first added in all the necessary libraries. After this we entered the Wifi credentials and password with the Adafruit IO username and AIO key that was obtained earlier. Using the setup function, we will begin the serial communication at a 11500 baud rate. Then we will connect our Wi-Fi client to the Adafruit IO server. Inside the void loop function, the ESP board will read the data from the serial and then publish it to the Adafruit IO server. Once the code is compiled and uploaded onto both boards within our serial monitor you will see the respective data once the cards are scanned. 

## Contents
* [NodeMCU Code](https://github.com/nivethagnan/SOFE4610-GRP2-PROJECT/blob/main/Code/NodeMCU%20ESP-12E.ino)
* [Arduino Code](https://github.com/nivethagnan/SOFE4610-GRP2-PROJECT/blob/main/Code/arduino%20board.ino)



