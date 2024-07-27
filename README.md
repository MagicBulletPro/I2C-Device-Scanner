# I2C Device Scanner

A simple project to scan and identify I2C devices on the I2C bus using an ESP32 development board. This project uses the Wire library to communicate with I2C devices and prints their addresses to the Serial Monitor.

## Requirements

- ESP32 development board
- I2C devices
- Visual Studio Code with PlatformIO extension

## Installation

1. Clone this repository:
    ```sh
    git clone https://github.com/MagicBulletPro/I2C-Device-Scanner.git
    ```
2. Open the cloned folder in Visual Studio Code.
3. Ensure you have the PlatformIO extension installed in Visual Studio Code.

## Usage

1. Connect your I2C devices to the ESP32.
2. Open the `src/main.cpp` file in Visual Studio Code.
3. Connect your ESP32 board to your computer.
4. Build and upload the project using PlatformIO:
    - Click the check mark (✓) icon on the bottom bar to build the project.
    - Click the right arrow (→) icon on the bottom bar to upload the project to the ESP32.
5. Open the Serial Monitor in PlatformIO (set the baud rate to 115200) to view the output.
    - Click the plug icon on the bottom bar to open the Serial Monitor.
  
## Code Overview

```cpp
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
```


### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

### Acknowledgements

- [Arduino](https://www.arduino.cc/)
- [Espressif Systems](https://www.espressif.com/)

### Contact

For any inquiries, please contact [magicbulletsoft@gmail.com](mailto:magicbulletsoft@gmail.com).
