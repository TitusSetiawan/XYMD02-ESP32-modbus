# XYMD02-ESP32-Modbus
Read data XY MD02 sensor with ESP32 and RS485

1. ESP32 Devkitc
2. RS485 Modbus Module
3. XY-MD02 Temperature Humidity Transmitter Acquisition Module Transducer SHT20 Temperature & Humidity Sensors

## Wiring Diagram
XY-MD02&nbsp;&nbsp;A&nbsp;&nbsp;-->&nbsp;&nbsp;A&nbsp;&nbsp;&nbsp;&nbsp;RS485<br/>
XY-MD02&nbsp;&nbsp;B&nbsp;&nbsp;-->&nbsp;&nbsp;B&nbsp;&nbsp;&nbsp;&nbsp;RS485<br/>
XY-MD02&nbsp;&nbsp;+&nbsp;&nbsp;-->&nbsp;&nbsp;5V&nbsp;&nbsp;RS485<br/>
XY-MD02&nbsp;&nbsp;-&nbsp;&nbsp;-->&nbsp;&nbsp;GND&nbsp;&nbsp;RS485<br/>
<br/>
ESP32&nbsp;&nbsp;IO0&nbsp;&nbsp;-->&nbsp;&nbsp;RE&nbsp;&nbsp;RS485<br/>
ESP32&nbsp;&nbsp;IO4&nbsp;&nbsp;-->&nbsp;&nbsp;DE&nbsp;&nbsp;RS485<br/>
ESP32&nbsp;&nbsp;IO16&nbsp;&nbsp;-->&nbsp;&nbsp;RO&nbsp;&nbsp;RS485<br/>
ESP32&nbsp;&nbsp;IO17&nbsp;&nbsp;-->&nbsp;&nbsp;DI&nbsp;&nbsp;RS485<br/>
ESP32&nbsp;&nbsp;5V&nbsp;&nbsp;&nbsp;&nbsp;-->&nbsp;&nbsp;VCC&nbsp;&nbsp;RS485<br/>
ESP32&nbsp;&nbsp;GND&nbsp;&nbsp;-->&nbsp;&nbsp;GND&nbsp;&nbsp;RS485<br/>
