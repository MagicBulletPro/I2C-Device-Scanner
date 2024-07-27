#include <Arduino.h>
#include <Wire.h> // Include the Wire library for I2C communication

void setup() {
  Wire.begin(); // Initialize the I2C bus as a master
  Serial.begin(115200); // Initialize the serial communication at 115200 baud rate
  Serial.println("\nI2C Device Scanner"); // Print a header message
}
 
void loop() {
  byte error, address; // Variables to hold error status and I2C address
  int nDevices; // Variable to count the number of I2C devices found
  
  Serial.println("Scanning..."); // Print a message indicating the start of the scan
  nDevices = 0; // Reset device count
  
  // Loop through all possible I2C addresses (1 to 126)
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address); // Start I2C transmission to the current address
    error = Wire.endTransmission(); // End the transmission and capture the error code
    
    if (error == 0) { // If no error occurred
      Serial.print("I2C device found at address 0x"); // Print the device found message
      if (address < 16) {
        Serial.print("0"); // Print a leading zero for addresses less than 0x10
      }
      Serial.println(address, HEX); // Print the address in hexadecimal format
      nDevices++; // Increment the device count
    }
    else if (error == 4) { // If an unknown error occurred
      Serial.print("Unknown error at address 0x"); // Print the error message
      if (address < 16) {
        Serial.print("0"); // Print a leading zero for addresses less than 0x10
      }
      Serial.println(address, HEX); // Print the address in hexadecimal format
    }    
  }
  
  if (nDevices == 0) { // If no devices were found
    Serial.println("No I2C devices found\n"); // Print a message indicating no devices found
  }
  else { // If devices were found
    Serial.println("Scanning Completed\n"); // Print a message indicating the scan is done
  }
  
  delay(5000); // Wait 5 seconds before the next scan
}
