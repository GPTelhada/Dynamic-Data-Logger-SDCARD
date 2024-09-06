# Dynamic-Data-Logger-SDCARD
This project is a simple data logger for microcontrollers (Arduino, ESP32, STM32), which records sensor data to a CSV file on an SD card. The project demonstrates how to initialize the SD card, create unique log files, and write sensor readings to these files with timestamps. Great to add to a project that needs Data Logging.

## Features

- **SD Card Initialization**: Initializes an SD card using the SPI interface and verifies the connection.
- **Dynamic Filename Generation**: Automatically generates the next available filename (`logfile1.csv`, `logfile2.csv`, etc.) to prevent overwriting existing files.
- **Data Logging**: Captures sensor readings and logs them with a timestamp into a CSV file at regular intervals.
- **File Handling**: Includes robust file handling with error checks for creating and writing to files.

## Code Overview

- `setup()`: Initializes the SD card and creates a new CSV file with a header row.
- `loop()`: Continuously reads dummy sensor data, generates a timestamp, and logs the information to the CSV file.
- `getNextAvailableFilename()`: Generates a unique filename to ensure no data is overwritten.
- `writeDataToCSV(String data)`: Appends the sensor data and timestamp to the CSV file.
- `ReadSensor1()` and `ReadSensor2()`: Placeholder functions that simulate sensor readings.
- `getTime()`: Returns the current time in milliseconds since the program started.

## Dependencies

- **Arduino Core for ESP32**: Make sure you have the ESP32 board package installed in your Arduino IDE.
- **SD Library**: Used for interfacing with the SD card. Ensure it is compatible with the ESP32.

## How to Use

1. Connect an SD card module to your ESP32-C3 board.
2. Update the `chipSelect` pin definition in the code if necessary.
3. Upload the code to your ESP32-C3 board.
4. Open the serial monitor at 115200 baud to view initialization messages and sensor data logging status.

## Customizability

- Implement actual sensor readings by replacing the `ReadSensor1()` and `ReadSensor2()` functions with real sensor code.
- Add or remove the amount of sensors being recorded.
- Customize logging intervals.
