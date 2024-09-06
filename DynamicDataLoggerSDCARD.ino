#include <FS.h>
#include <SD.h>
#include <SPI.h>

// SD card setup
const int chipSelect = D3;  // Chip select pin for SD card module
String filename;            // Variable to hold the generated filename
File dataFile;              // File object for handling SD card operations

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  delay(500);            // Wait for a moment to stabilize

  // Initialize the SD card with the defined chip select pin
  if (!SD.begin(chipSelect)) {
      Serial.println("Card initialization failed!");
      while(1);  // Halt the program if the SD card fails to initialize
  }
  Serial.println("Card initialized.");  // Confirmation message

  getNextAvailableFilename();  // Generate the next available filename for logging
  File dataFile = SD.open(filename, FILE_WRITE);  // Open the file for writing
  if (dataFile) {
      // Write the header line to the file
      dataFile.println("Timestamp,SensorValue1,SensorValue2");
      dataFile.close();  // Close the file to save changes
  } else {
      Serial.println("Failed to create file!");  // Error message if file creation fails
  }
}

void loop() {
  // Simulate reading sensor values
  int sensor1 = ReadSensor1();
  int sensor2 = ReadSensor2();
  
  // Create a data string with a timestamp and sensor values
  String data = getTime() + "," + String(sensor1) + "," + String(sensor2);
  
  // Write the data to the CSV file
  writeDataToCSV(data);
  
  // Delay for 500 milliseconds before the next loop iteration
  delay(500);
}

void writeDataToCSV(String data) {
  Serial.print("Writing....");
  // Open the file in append mode to add new data at the end
  File dataFile = SD.open(filename, FILE_APPEND);
  if (dataFile) {
      dataFile.println(data);  // Write the data to the file
      dataFile.flush();        // Ensure that all data is written to the SD card
      dataFile.close();        // Close the file to save changes
      Serial.println("Done");
  } else {
      Serial.println("Failed to open file for writing");  // Error message if file opening fails
  }
}

void getNextAvailableFilename() {
  int fileNumber = 1;                 // Start with file number 1
  String baseFilename = "logfile";    // Base name for the log files
  String fileExtension = ".csv";      // File extension for CSV files

  // Loop until an available filename is found
  while (true) {
    // Construct the filename with the current file number
    filename = "/" + String(baseFilename) + String(fileNumber) + String(fileExtension);
    // Check if the file already exists on the SD card
    if (!SD.exists(filename)) {
      break;  // If the file doesn't exist, exit the loop
    }
    fileNumber++;  // Increment the file number and try again
  }
}

int ReadSensor1() {
  return 0;  // Placeholder function to simulate sensor 1 reading
}

int ReadSensor2() {
  return 1;  // Placeholder function to simulate sensor 2 reading
}

String getTime() {
  // Return the current time in milliseconds since the program started
  return String(millis());
}
