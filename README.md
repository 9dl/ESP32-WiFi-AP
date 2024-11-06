# Hack the Planet - ESP32 Wi-Fi AP

This project creates an ESP32 access point that serves a simple webpage with the message "Hack the Planet". It also controls an LED based on whether a client is connected to the access point.

## Features

- ESP32 sets up a Wi-Fi access point (`HackThePlanet`).
- Serves a custom webpage with a title "Hack the Planet".
- Displays an LED on pin 2 when a client is connected to the AP.

## Components

- ESP32 (NodeMCU WROOM-32)

## Requirements

- ESP32 board support in the Arduino IDE.

## Code Explanation

- **Wi-Fi AP Setup**: The ESP32 starts a soft AP with the SSID `HackThePlanet` and an empty password.
- **DNS Server**: A DNS server is running on port 53 to redirect all domain requests to the ESP32's IP address.
- **Web Server**: A web server listens on port 80 and serves a simple HTML webpage with the message "Hack the Planet".
- **LED Control**: The LED is lit when a device is connected to the Wi-Fi network.
