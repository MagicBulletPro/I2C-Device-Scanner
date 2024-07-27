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


### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

### Acknowledgements

- [Arduino](https://www.arduino.cc/)
- [Espressif Systems](https://www.espressif.com/)

### Contact

For any inquiries, please contact [magicbulletsoft@gmail.com](mailto:magicbulletsoft@gmail.com).
