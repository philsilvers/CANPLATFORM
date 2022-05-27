/********************************************************************************************/
/*
CANPLATFRM - Station Platform Arrival Announcments and Scrolling text Display Board 
Developed by Philip Silver  Merg Member 4082 - November 2019
Uses CBUS to select individual station announcements and display departure information.
Designed for toggle events - can be used with CANMIO and any TOTI
Up to 20 differnt announcments and destinations can be used


Hardware Requirments
SSD1306 OLED Display 128 x 32
DS1306 RTC Real Time Clock
DF Robot DF Player mp3
Microchip MCP2515 CAN Controller
Microchip MCP2561 CAN Transceiver
Arduino Nano


All Libraries cn be downlaoded from Github
https://github.com/philsilvers

Pins used for interface chip

           Nano  
INT         D2       
SCK   SCK   D13      
SI    MISO  D11      
SO    MOSI  D12      
CS          D10      
GND         0V       
VCC         5V      

*/
/********************************************************************************************/





/********************************************************************************************/
// Load CBUS and DFPlayer libraries
/********************************************************************************************/

#include <SPI.h> //required by the CBUS library
#include <MergCBUS.h>
#include <Message.h>
#include <EEPROM.h> //required by the CBUS library
#include "DFRobotDFPlayerMini.h"  //for the mp3 player


/********************************************************************************************/
// Load I2C and OLED libraries. 
//The Adafruit GFX.h has been modified to provide a 'Lite Version' to save memory.
//Adafruit GFx.h is included in the Adafruit SSD1306.h
/********************************************************************************************/
#include <Wire.h> // IC2 Library
#include <Adafruit_GFX.h> //Adafruit GFX Libray
#include <Adafruit_SSD1306.h> // SSD1306 Library -  If any errors you may have to open this header file and make sure #define SSD1306_128_32 is uncommented.
#include <RTClib.h> // RTC DS1307 Real Time Clock Module for Departure Clock - https://github.com/adafruit/RTClib


/********************************************************************************************/
//Module definitions
/********************************************************************************************/
#define debounceDelay 50  //for any switches if used

#define TRUE    1
#define FALSE   0
#define ON      1
#define OFF     0

/********************************************************************************************/
//CBUS definitions
/********************************************************************************************/
  #define GREEN_LED 5               //merg green led port
  #define YELLOW_LED 4              //merg yellow led port
  #define PUSH_BUTTON 6             //std merg FLIM / SLIM push button
  //#define PUSH_BUTTON1 7            //debug push button
  #define COLOR_PIN  8              // Set Oled Foreground / Background Colour
  #define NODE_VARS 4      //sets up number of NVs for module to store variables
                           // Only one NV used for default volume

  #define NODE_EVENTS 20     //max number of events in case of teaching short events
  #define EVENTS_VARS 5   //number of variables per event  1 Track On 2 Track Off 3 Volume 4 Display ON 5 Display Off
  #define DEVICE_NUMBERS 1  //number of device numbers. 

/********************************************************************************************/
//Variables
/********************************************************************************************/

int track;         // track being played
int volume;    // current volume level
int displaySwitch;  // Switch Display Information
boolean muteflag = false;  // mutes sound if true
int displaywidth; // Variable for display width


// Add up to 20 different destinations
char stnNames1[] = "Newport    Bristol Parkway    Swindon    Reading    Slough    Paddington   ";
char stnNames2[] = "Pontyclun   Pencoed   Bridgend   Pyle   Port Talbot   Neath   Swansea    ";
int stnlen1; //Variable for station names1 string length
int stnlen2; //Variable for station names1 string length


/********************************************************************************************/
//Create the MERG CBUS object - cbus
/********************************************************************************************/
MergCBUS cbus=MergCBUS(NODE_VARS,NODE_EVENTS,EVENTS_VARS,DEVICE_NUMBERS);


/********************************************************************************************/
//Create the DFPlayer object - DFPlayer1
/********************************************************************************************/
DFRobotDFPlayerMini DFPlayer1;


/********************************************************************************************/
// Create the SSD1306 object - oled
/********************************************************************************************/
Adafruit_SSD1306 oled(4);
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


/********************************************************************************************/
// Create the realtime clock object - stationclock
/********************************************************************************************/

RTC_DS1307 stationclock;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

byte date, hour, minute, second; 
byte bg, fg; // Dispaly background colour, Display foreground colour, messenger



void setup(){

  
  pinMode(COLOR_PIN, INPUT_PULLUP);
  
 
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C and set OLED VCC to 3.3V
  stationclock.begin();


 // stationclock.adjust(DateTime(F(__DATE__), F(__TIME__))); // set to PC time. Uncomment this to initally set stationclock. Then comment out and reload sketch to Nano

  oled.setTextSize(1);
  oled.setTextColor(fg);
  oled.setTextWrap(false);
  displaywidth = oled.width(); // Give displaywidth the value of oled width

   stnlen1 = -6*strlen(stnNames1); // standard font is 8 x 5 pixels. 
   stnlen2 = -6*strlen(stnNames2);
  
   /*****************************************************************************************/
  //Configuration CBUS data for the node
   /*****************************************************************************************/

  cbus.getNodeId()->setNodeName("PLATFRM",7);           //node name shows in FCU when first detected set your own name for each module
  cbus.getNodeId()->setModuleId(210);                   //module number
  cbus.getNodeId()->setManufacturerId(0xA5);            //merg code
  cbus.getNodeId()->setMinCodeVersion(0x61);            //Version 1
  cbus.getNodeId()->setMaxCodeVersion(1);
  cbus.getNodeId()->setProducerNode(false);
  cbus.getNodeId()->setConsumerNode(true);
  cbus.getNodeId()->setConsumeEvents(false);      	    // consume own event COE
  cbus.getNodeId()->setTransportType(1);            	// 1 CAN  2 ETHERNET 3 MiWi
  cbus.getNodeId()->setBetaRelease(1);             		// Beta Release set to zero for release version
  cbus.getNodeId()->setSuportBootLoading(false);        // Allways set false - no bootloading
  cbus.getNodeId()->setCpuManufacturer(2);              // 1 MICROCHIP  2  ATMEL  3 ARM

  cbus.setStdNN(999); 
 
  /********************************************************************************************/
  // Set ports and CAN Transport Layer
  /********************************************************************************************/
  
  cbus.setLeds(GREEN_LED,YELLOW_LED);//set the led ports
  cbus.setPushButton(PUSH_BUTTON);//set the push button ports
  cbus.setUserHandlerFunction(&myUserFunc);//function that implements the node logic
  cbus.initCanBus(10,CAN_125KBPS,MCP_8MHz,10,200);  //initiate the transport layer. pin=10, rate=125Kbps,10 tries,200 millis between each try
  
  //Note the clock speed 8Mhz. If 16Mhz crystal fitted change above to MCP_16Mhz



  //Setup Sound Card
  //get base volume from NVs
   volume=cbus.getNodeVar(1);
   if (volume == 0) volume =15;  //NV not set so give it a default of 15 in a scale of 0-30

    
   Serial.begin (9600);  //Standard port used for the dfplayer
   DFPlayer1.begin(Serial);
   DFPlayer1.reset();
   DFPlayer1.volume(volume);     
}



/********************************************************************************************/
//FUNCTIONS START
/********************************************************************************************/


void processSoundOnEvent(int eventNum, int volume){
  // Perform the action for each On Event based on the event variable 1
        play(eventNum, volume);  //Play sound variable 1 
}


void processSoundOffEvent(int eventNum, int volume){
  // Perform the action for each OFF Event based on the event variable 2 
         play(eventNum, volume);  //Play sound variable 2
}

void processDisplayOnEvent(int eventNum){
  // Perform the action for each On Event based on the event variable 4 
         displaySwitch = eventNum; 
}



void processDisplayOffEvent(int eventNum){
  // Perform the action for each OFF Event based on the event variable 5 
        displaySwitch = eventNum; 
}

void play(int track, int TrackVol) {
  if (TrackVol == 0) TrackVol = volume;
  DFPlayer1.volume(volume); 
  DFPlayer1.play(track);  
}



void myUserFunc(Message *msg,MergCBUS *mcbus){
   byte CBUSOpc = msg->getOpc();


 
   if (mcbus->eventMatch()){  
      
        int ev0=mcbus->getEventVar(msg,1);  //track to play for ON
        int ev1=mcbus->getEventVar(msg,2);  //track to play for OFF
        int ev2=mcbus->getEventVar(msg,3);  //sound level if zero use default
        int ev3=mcbus->getEventVar(msg,4);  //display 0n
        int ev4=mcbus->getEventVar(msg,5);  //display off
        
     if ((mcbus->isAccOn()==true)&&(ev0 != 0)){  //No sound file no play 
          processSoundOnEvent(ev0,ev2);//Pass the ON Event to the event handler 
          } 

        if ((mcbus->isAccOn()==true)&&(ev3 !=0)){
              processDisplayOnEvent(ev3);         
          }





     if ((mcbus->isAccOff()==true)&&(ev1 != 0)){  //No sound file no play
          processSoundOffEvent(ev1,ev2);//Pass the OFF Event to the event handler 
          }   

      if ((mcbus->isAccOff()==true)&&(ev4 !=0)){
            processDisplayOffEvent(ev4);    
            }


          }
     
     
   } 



/*FUNCTION FINISH ***********************************************************************************/




void loop (){


  cbus.cbusRead();  //Check CBUS buffers
  cbus.run();//do all logic
  

  //debug memory
  /* if (digitalRead(PUSH_BUTTON1)==LOW){
    cbus.dumpMemory();  //Used to clear the Arduino Memory
  }
  */


 // determine background- and foreground color based on COLOR_PIN
  if(digitalRead(COLOR_PIN) == LOW) {bg = WHITE; fg = BLACK;}
  else {bg = BLACK; fg = WHITE;}


    // Real Time Clock values from RTC1306
  DateTime now = stationclock.now();
  date =   now.day();
  hour   = now.hour();
  minute = now.minute();
  second = now.second();
  
  oled.clearDisplay();
  


  // rectangle for platform number
  oled.fillRect(8, 0, 17, 21, fg);
  oled.setTextSize(2);
  oled.setTextColor(bg);
  oled.setCursor(12,4);
  oled.print("1"); // overwrite your station platform number
  

 
switch (displaySwitch) {
  case 1:
    oled.setTextSize(1);
    oled.setCursor(38,0);
    oled.setTextColor(fg);
    oled.print("9:30 LONDON"); // Overwrite for your own departure time and destination
    
    oled.setTextSize(1);
    oled.setCursor(41,12);
    oled.setTextColor(fg);
    oled.print("calling at");

    oled.setTextSize(1);
    oled.setCursor(displaywidth,24);
    oled.setTextColor(fg);
    oled.print(stnNames1); //first station names variable defined earlier in sketch
    oled.display();
    
    displaywidth = displaywidth-6; // Set Scroll Speed
    if(displaywidth < stnlen1)displaywidth = oled.width();
   break;

  case 2:
    oled.setTextSize(1);
    oled.setCursor(34,0);
    oled.setTextColor(fg);
    oled.print("11:28 SWANSEA"); // Overwrite for your own departure time and destination
    
    oled.setTextSize(1);
    oled.setCursor(41,12);
    oled.setTextColor(fg);
    oled.print("calling at");
    
    oled.setTextSize(1);
    oled.setCursor(displaywidth,24);
    oled.setTextColor(fg);
    oled.print(stnNames2); //second station names variable defined earlier in sketch
    oled.display();
    
    displaywidth = displaywidth-6; // Set Scroll Speed
    if(displaywidth < stnlen2)displaywidth = oled.width();
   break;

  case 3:
     oled.setTextSize(2);
     oled.setCursor(40,0);
     oled.setTextColor(fg);
     oled.print("MERRY"); // Overwrite your own station name
    
     oled.setTextSize(2);
     oled.setCursor(48,16);
     oled.setTextColor(fg);
     oled.print("XMAS"); // Overwite platform number
     oled.display();
          
    break;

    case 20: // default display  Main Station Name - Platform Number - RTC
    oled.setTextSize(1);
    oled.setCursor(34,0);
    oled.setTextColor(fg);
    oled.print("CARDIFF CENTRAL"); // Overwrite your own station name
    
    oled.setTextSize(1);
    oled.setCursor(41,12);
    oled.setTextColor(fg);
    oled.print("PLATFORM ONE"); // Overwite platform number

    // Real Time Clock
    oled.setCursor(6,24);
    oled.print(daysOfTheWeek[now.dayOfTheWeek()]);
    oled.print(" ");
    oled.print(date);
    oled.print(" ");
    oled.print(hour);
    oled.print(":");
    if (minute <10){ // preceding 0 just to make the display look good
    oled.print("0");} 
    oled.print(minute);
    oled.print(":");
    if (second <10){// preceding 0 just to make the display look good
    oled.print("0");}
    oled.print(second);
    
    break;

    default: // default display  Main Station Name - Platform Number - RTC
    oled.setTextSize(1);
    oled.setCursor(34,0);
    oled.setTextColor(fg);
    oled.print("CARDIFF CENTRAL"); // Overwrite your own station name
    
    oled.setTextSize(1);
    oled.setCursor(41,12);
    oled.setTextColor(fg);
    oled.print("PLATFORM ONE"); // Overwite platform number

    // Real Time Clock
    oled.setCursor(6,24);
    oled.print(daysOfTheWeek[now.dayOfTheWeek()]);
    oled.print(" ");
    oled.print(date);
    oled.print(" ");
    oled.print(hour);
    oled.print(":");
    if (minute <10){ // preceding 0 just to make the display look good
    oled.print("0");} 
    oled.print(minute);
    oled.print(":");
    if (second <10){// preceding 0 just to make the display look good
    oled.print("0");}
    oled.print(second);
    
    break;

}

oled.display();


}












    
