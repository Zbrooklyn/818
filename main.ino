#include <SD.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define SD_CS_PIN 5

SoftwareSerial sa818(16, 17); // RX, TX
String csv_filename = "frequencies.csv";
String csv_delimiter = ",";
File csv_file;

struct Frequency {
  float frequency;
  String city;
  String state;
  String zip;
  String notes;
  String callsign;
};

void setup() {
  Serial.begin(9600);
  sa818.begin(9600);
  
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed.");
    return;
  }
  
  if (!SD.exists(csv_filename)) {
    Serial.println("CSV file not found.");
    return;
  }
  
  csv_file = SD.open(csv_filename, FILE_READ);
  
  if (!csv_file) {
    Serial.println("Error opening CSV file.");
    return;
  }
  
  Serial.println("CSV file opened successfully.");
  
  while (csv_file.available()) {
    String line = csv_file.readStringUntil('\n');
    line.trim();
    
    if (line.length() == 0) {
      continue;
    }
    
    String values[6];
    int i = 0;
    int index = 0;
    
    while (index != -1) {
      index = line.indexOf(csv_delimiter);
      
      if (index != -1) {
        values[i] = line.substring(0, index);
        line = line.substring(index + 1);
      }
      
      i++;
    }
    
    values[i] = line;
    
    Frequency frequency;
    frequency.frequency = values[0].toFloat();
    frequency.city = values[1];
    frequency.state = values[2];
    frequency.zip = values[3];
    frequency.notes = values[4];
    frequency.callsign = values[5];
    
    Serial.print("Frequency: ");
    Serial.print(frequency.frequency);
    Serial.print(", City: ");
    Serial.print(frequency.city);
    Serial.print(", State: ");
    Serial.print(frequency.state);
    Serial.print(", ZIP: ");
    Serial.print(frequency.zip);
    Serial.print(", Notes: ");
    Serial.print(frequency.notes);
    Serial.print(", Callsign: ");
    Serial.println(frequency.callsign);
  }
  
  csv_file.close();
}

void loop() {
  // Main loop code here, if any
}

// Note that this code assumes the CSV file is stored on a microSD card and is named "frequencies.csv". 
// The delimiter used in the CSV file is ",". The code reads the contents of the CSV file and parses each line 
// to extract the frequency, city, state, zip, notes, and callsign. It then creates a Frequency struct to 
// hold this information and prints it to the serial monitor.
