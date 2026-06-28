# Color-Companion
<img width="1169" height="659" alt="IMG_6375" src="https://github.com/user-attachments/assets/856d9c0c-acfb-4b24-847f-3a9835e593bb" />

Ever seen a color and thought, I want that color! The Color Companion is a handheld device with a color sensor and display, which can give you the exact RGB and HEX values of anything for you!

Its built using a esp32 devboard, a ssd1306 oled display, and a TCS34725 color sensor. The code uses Adafruits libraries for communication between the display and sensor over i2c. 

# Demo Video

https://github.com/user-attachments/assets/e2945326-af05-4202-8325-9a9cc32651e1

# Wiring

ESP32 ground --> sensor ground + display ground + button  

ESP32 5v --> sensor vin + display vcc (Make sure your components are 5v tolerant!)   

ESP32 GPIO 23 --> button  

ESP32 GPIO 22 --> sensor scl + display scl  

ESP32 GPIO 21 --> sensor sda + display sda  

ESP32 GPIO 19 --> sensor led

<img width="778" height="717" alt="Screenshot 2026-06-28 162254" src="https://github.com/user-attachments/assets/3a5a618a-85e7-411a-81e5-89372aa1899a" />

# 3D printing notes  

Standard settings work fine (I used PLA, 2 walls, 0.2mm layer height)
Please note, this should ideally be printed in black to avoid color contamination for the sensor. If you print in a different color please blackout the sensor shroud using marker or paint.

# Assembly 
Wire together all components (Ideally with soldered connections)  
Place ESP32, button, and sensor in their respective sockets in the main case  
Slide OLED display under hook in top case and secure with two mounting brackets  
Place the top over the main case and screw in the four corners. 
<img width="880" height="1173" alt="IMG_6380" src="https://github.com/user-attachments/assets/ee552c08-1de9-4c85-af5d-b62d9eb6c121" />

# Bill of Materials  
3D printed parts:  
1x Case Top  
1x Main Case  
2x Display Mounting Bracket  

Components:  
1x Generic ESP32 Devboard  
1x ssd1306 0.96in OLED display  
1x TCS34725 Color Sensor Devboard (Get the one seen in the wiring diagram) 
1x 6x6x12mm pushbutton  
Wires for wiring  
4x M3 12mm screws  
4x M3 6mm screws 
(You can use differently sized M3 screws, just consult the CAD to see if they fit.) 

# Links  
Onshape CAD
https://cad.onshape.com/documents/70483fd3f9557aaf4b7bc699/w/9afb3eae3ce6437ed4a82568/e/d381e982bd1c6c0bcb748ca7?renderMode=0&uiState=6a41ad054af3a7a0cfb2e8ca
