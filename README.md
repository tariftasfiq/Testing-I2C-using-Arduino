# I2C Testing with Arduino

## Overview

This repository provides example projects and setup instructions for testing **I2C communication** using an **Arduino** board. I2C is a two-wire protocol used for communication between devices like sensors, displays, and other peripherals. This guide demonstrates how to set up and test I2C communication with an Arduino board.

## Getting Started

### Prerequisites

- **Arduino IDE**: Ensure you have the latest version of the [Arduino IDE](https://www.arduino.cc/en/software) installed on your computer.
- **I2C Devices**: Common I2C devices such as **LCD displays**, **EEPROMs**, **sensors**, etc.

### Setup and Installation

1. **Connect Your I2C Device**:
   - **SDA** (data) pin of the I2C device connects to **A4** (Arduino Uno) or appropriate SDA pin for other Arduino models.
   - **SCL** (clock) pin of the I2C device connects to **A5** (Arduino Uno) or appropriate SCL pin for other Arduino models.
   - **VCC** (power) and **GND** pins connect to the **5V** and **GND** pins of Arduino, respectively.

2. **Install Necessary Libraries**:
   - For devices like an I2C LCD, you may need to install libraries such as **LiquidCrystal_I2C**. You can install it from the Arduino IDE Library Manager:
     - Go to **Sketch > Include Library > Manage Libraries**
     - Search for `LiquidCrystal_I2C` and click **Install**.

3. **Select the Correct Board**:
   - Go to **Tools > Board** and select your Arduino model (e.g., **Arduino Uno**).
   
4. **Select the Correct Port**:
   - Go to **Tools > Port** and select the correct COM port for your Arduino.

## Example Projects

- **Basic I2C LCD Test**: This example demonstrates how to communicate with an I2C LCD to display text.
- **I2C Scanner**: A simple example to scan for connected I2C devices and display their addresses in the Serial Monitor.
- **I2C Temperature Sensor**: Example to read temperature data from an I2C-based temperature sensor (like the **DHT22** or **BMP180**).
- **I2C EEPROM Write/Read**: Demonstrates writing and reading data to/from an I2C EEPROM module.

## Example Code

### I2C Scanner

This code scans and lists the addresses of all connected I2C devices.

```cpp
#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("I2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;
  
  Serial.println("Scanning...");
  nDevices = 0;
  
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
  }
  
  if (nDevices == 0) {
    Serial.println("No I2C devices found.");
  } else {
    Serial.println("Scan complete.");
  }
  
  delay(5000);
}
# Testing-I2C-using-Arduino
