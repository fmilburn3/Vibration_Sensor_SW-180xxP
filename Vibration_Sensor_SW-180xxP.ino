/*
 Vibration_Sensor_SW-180xxP
 Turns on the red LED when a vibration sensor is triggered  
 
 Addicore SW-18015P Vibration Sensor Switch (High Sensitivity)
 https://www.addicore.com/SW-18015P-High-Sensitivity-Vibration-Sensor-Switch-p/166.htm
 Addicore SW-18020P Vibration Sensor Switch (Standard Sesitivity)
 https://www.addicore.com/SW-18020P-Standard-Sensitivity-Vibration-Sensor-p/167.htm
 
 I found that both sensors took a fairly good shake or
 bump to set them off.  For my use the higher sensitivity
 was better.   They are inexpensive enough though to get one
 of each, try them both, and see which one is best.
 
 Tested on MSP-EXP430F5529 LaunchPad but should work on most
 LaunchPads.  The vibration sensor is basically an open
 switch that closes when shaken. You can insert the pins into
 a breadboard to test the sensor - be careful with the thin 
 wire. 

 Pin Connections
 ===============
 Vibration Sensor    LaunchPad
 ----------------    ---------
 Either pin          3V3              
 Other pin           Pin 5
 
 Frank Milburn  16 June 2015 
 This example code is in the public domain.
 */

const int vibrationPin = 5;           
const int ledPin =  RED_LED;     

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(vibrationPin, INPUT_PULLDOWN);  
  Serial.begin(9600);
  Serial.println("Starting vibration sensor test...");  
}

void loop()
{
  int vibrationState = digitalRead(vibrationPin);

  Serial.println(vibrationState);

  if (vibrationState == HIGH) 
  {                                       
    digitalWrite(ledPin, HIGH);     // vibration! turn LED on
    delay(1000);                    // and hold it a second
  }
  else 
  {
    digitalWrite(ledPin, LOW);      // no vibration, turn off
  }
}
