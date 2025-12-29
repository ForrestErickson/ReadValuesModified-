//ReadValuesModified
#define FIRMWARE_VERSION "v0.0.1"

/***************************************************
 DFPlayer - A Mini MP3 Player For Arduino
 <https://www.dfrobot.com/product-1121.html>
 
 ***************************************************
 This example shows the basic function of library for DFPlayer.
 
 Created 2016-12-07
 Modified 2018-08-15
 By [Angelo qiao](Angelo.qiao@dfrobot.com)
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

//after specifying the device, the user needs to wait for 200ms before sending the specified track.
#define timeToTrack 200 //mS from TD5580A specification,
#define REPEAT_TIME 5000 // mS for main loop

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))  // Using a soft serial port
#include <SoftwareSerial.h>
//SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
SoftwareSerial softSerial(16, 17);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup() {
#if (defined ESP32)
  FPSerial.begin(9600, SERIAL_8N1, 16, 17);
#else
  FPSerial.begin(9600);
#endif

  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(FIRMWARE_VERSION);
  Serial.print("Compiled at: ");
  Serial.println(F(__DATE__ " " __TIME__));  //compile date that is used for a unique identifier

  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(FPSerial, /*isACK = */ true, /*doReset = */ true)) {  //Use serial to communicate with mp3.
    Serial.println(F("!!!!!!!!!!!!"));
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card or USB drive!"));
    Serial.println(F("!!!!!!!!!!!!"));
    // while (true) {
    //   delay(0);  // Code to compatible with ESP8266 watch dog.
    // }
  }
  delay(timeToTrack);
  //myDFPlayer.setTimeOut(500); // Set serial communication time out to 500ms
  myDFPlayer.setTimeOut(3500);  // Set serial communication time out to 3.5 seconds
  
  myDFPlayer.volume(30); // Set to maximum volume.

  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.readFileCounts();
  Serial.print("Files found: ");
  Serial.println(myDFPlayer.readFileCounts());

  myDFPlayer.readCurrentFileNumber();
  Serial.print("Current file number: ");
  Serial.println(myDFPlayer.readCurrentFileNumber());
  
  myDFPlayer.readState();
  Serial.print("Player State: ");
  Serial.println(myDFPlayer.readState());

  myDFPlayer.readVolume();
  Serial.print("Volume set: ");
  Serial.println(myDFPlayer.readVolume());

  Serial.println("Playing file 1");
  myDFPlayer.play(1);


  //    value = myDFPlayer.readState(); //read mp3 state
  //    value = myDFPlayer.readVolume(); //read current volume
  //    value = myDFPlayer.readEQ(); //read EQ setting
  //    value = myDFPlayer.readFileCounts(); //read all file counts in SD card
  //    value = myDFPlayer.readCurrentFileNumber(); //read current play file number
}

void loop() {
  static unsigned long timer = millis();

  if (millis() - timer > REPEAT_TIME) {
    timer = timer + REPEAT_TIME; //Preserves period

//    int value;

    Serial.println();
    Serial.println("Loop test.");
    delay(100);
    if (myDFPlayer.available()) {
      Serial.println("myDFPlayer.available() is available");
      Serial.print("myDFPlayer.readType() is: ");
      Serial.println(myDFPlayer.readType());
      Serial.print("myDFPlayer.read() is: ");
      Serial.println(myDFPlayer.read());
    } else {
      Serial.println("myDFPlayer.available() not available");
    }

    Serial.print("myDFPlayer.readType() is: ");
    Serial.println(myDFPlayer.readType());
    Serial.print("myDFPlayer.read() is: ");
    Serial.println(myDFPlayer.read());

    Serial.print("State: ");
    Serial.println(myDFPlayer.readState());
    Serial.print("Again, State: ");
    Serial.println(myDFPlayer.readState());
    Serial.print("Third time, State: ");
    Serial.println(myDFPlayer.readState());
    Serial.print("Forth time, State: ");
    Serial.println(myDFPlayer.readState());

    Serial.print("readFileCounts(): ");
    Serial.println(myDFPlayer.readFileCounts());
    Serial.print("Again, readFileCounts(): ");
    Serial.println(myDFPlayer.readFileCounts());
    Serial.print("Third time, readFileCounts(): ");
    Serial.println(myDFPlayer.readFileCounts());
    Serial.print("Forth time, readFileCounts(): ");
    Serial.println(myDFPlayer.readFileCounts());

    Serial.print("readCurrentFileNumber(): ");
    Serial.println(myDFPlayer.readCurrentFileNumber());
    Serial.print("Again, readCurrentFileNumber(): ");
    Serial.println(myDFPlayer.readCurrentFileNumber());
    Serial.print("Third time, readCurrentFileNumber(): ");
    Serial.println(myDFPlayer.readCurrentFileNumber());
    Serial.print("Forth time, readCurrentFileNumber(): ");
    Serial.println(myDFPlayer.readCurrentFileNumber());

    //myDFPlayer.loop(1);
    myDFPlayer.next();
  }  // end millstimer
}  // end loop()

void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
