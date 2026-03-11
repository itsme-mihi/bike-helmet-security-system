# Bike Helmet Security System

This project ensures that a bike can only be used when the rider is wearing a helmet and has fastened the helmet strap.

## Features
- Face detection using OpenCV to check if helmet is worn
- Reed switch sensor to detect helmet strap fastening
- Arduino-controlled relay to unlock the bike lock
- Buzzer alert when safety conditions are not met

## Technologies Used
- Python
- OpenCV
- Arduino IDE
- Serial Communication

## System Workflow
1. The webcam captures real-time video of the rider.
2. Python uses OpenCV to detect faces.
3. If a face is detected → helmet not worn.
4. If no face is detected → helmet assumed worn.
5. Arduino checks if the helmet strap is fastened using a reed switch.
6. If both conditions are satisfied:  - Relay unlocks the bike lock
7. Otherwise: - Buzzer alerts the rider

## How to Run

1. Install required Python libraries : pip install opencv-python pyserial
2. Connect Arduino to your system and upload the Arduino code.
3. Update the correct serial port in the Python file.
4. Run the Python program : python helmet_detection.py
