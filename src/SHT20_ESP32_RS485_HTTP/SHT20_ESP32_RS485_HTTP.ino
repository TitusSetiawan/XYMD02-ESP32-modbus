#include <ModbusMaster.h>
#include <AntaresESP32HTTP.h>

/*
 * HTTP Protocol
 */
///////// PIN /////////
#define MAX485_DE      4
#define MAX485_RE_NEG  0
#define RX2 16
#define TX2 17

//// Preparartion for Publish Antares ////
#define ACCESSKEY "XXXXXXXXXX"
#define WIFISSID "......"
#define PASSWORD "haha1112"
#define projectName "XYMD02-ESP32"
#define deviceName "Sensor1"

ModbusMaster node;
AntaresESP32HTTP antares(ACCESSKEY);

uint8_t result;
float temp, hum;
void preTransmission()
{
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
}

void postTransmission()
{
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
}

void setup()
{
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);
  node.begin(1, Serial2);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID, PASSWORD);
}

void loop()
{
  // Data Frame --> 01 04 00 01 00 02 20 0B
  result = node.readInputRegisters(0x0001, 2);
  if (result == node.ku8MBSuccess)
  {
    temp = node.getResponseBuffer(0) / 10.0f;
    hum = node.getResponseBuffer(1) / 10.0f;
    //    Serial.print("Temp: "); Serial.print(temp); Serial.print("\t");
    //    Serial.print("Hum: "); Serial.print(hum);
    Serial.println();
    node.clearResponseBuffer();
    node.clearTransmitBuffer();

    antares.add("Temperature", temp);
    antares.add("Humidity", hum);
    antares.send(projectName, deviceName);
    delay(1000);
  }
}
