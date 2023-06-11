#include <WiFi.h>
#include <WiFiServer.h>
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <clev.h>
#include <opensans12.h>
#include <opensans14.h>
#include <opensans24.h>


#define TFT_COLOR1 0xA71F
#define TFT_COLORB 0x033F
#define TFT_COLORR 0xFA08

TFT_eSPI tft = TFT_eSPI();

const char* ssid = "Cleverest.tech";
const char* password = "d96328a2ecc99b9caad75219067b6b02f3e3dd99";
const int serverPort = 1234;  // Port to listen on

WiFiServer server(serverPort);
WiFiClient client;
int receivedData = 0;

void executeCodeForInteger1();
void executeCodeForInteger2();
void executeCodeForInteger3();
void executeCodeForInteger4();
void executeCodeForInteger5();

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  //clev.tech icon
  tft.setSwapBytes(true);
  tft.pushImage(10, 10, 29, 35, clev);
  tft.setFreeFont(&Open_Sans_Bold_14);   
  tft.setTextColor(TFT_COLOR1); 
  tft.drawString("Cleverest.tech", 45, 15);
  tft.setFreeFont(&Open_Sans_Regular_12);
  tft.drawString("Cleverest Defence Systems", 45, 35);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("Receiver IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started");
}

void loop() {
  if (!client.connected()) {
    client = server.available();
    delay(100);
  }

  if (client.connected() && client.available()) {
    // Data is received, execute the corresponding code
    client.read((uint8_t*)&receivedData, sizeof(int));
    Serial.print("Received integer: ");
    Serial.println(receivedData);

    switch (receivedData) {
      case 1:
        // Code to execute for integer 1
        Serial.println("Executing code for integer 1");
        executeCodeForInteger1();
        break;
      case 2:
        // Code to execute for integer 2
        Serial.println("Executing code for integer 2");
        executeCodeForInteger2();
        break;
      case 3:
        // Code to execute for integer 3
        Serial.println("Executing code for integer 3");
        executeCodeForInteger3();
        break;
      case 4:
        // Code to execute for integer 4
        Serial.println("Executing code for integer 4");
        executeCodeForInteger4();
        break;
      case 5:
        // Code to execute for integer 5
        Serial.println("Executing code for integer 5");
        executeCodeForInteger5();
        break;
      default:
        // Code to execute for unrecognized integers
        Serial.println("Unrecognized integer");
        // Your code here
        break;
    }
  } else {
    // No new data received, execute the corresponding code continuously
    switch (receivedData) {
      case 1:
        executeCodeForInteger1();
        break;
      case 2:
        executeCodeForInteger2();
        break;
      case 3:
        executeCodeForInteger3();
        break;
      case 4:
        executeCodeForInteger4();
        break;
      case 5:
        executeCodeForInteger5();
        break;
      default:
        // Code to execute for unrecognized integers
        // Your code here
        break;
    }
    delay(100); // Adjust the delay as needed to control the execution frequency
  }
}

void executeCodeForInteger1() {
  //mode 1 
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 1", 110, 210);
  tft.fillRect(15, 65, 45, 20, TFT_COLORB);
  tft.fillRect(75, 65, 45, 20, TFT_COLORB);
  tft.fillRect(38, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  tft.fillRect(98, 170, 45, 20, TFT_COLORB);

  delay(250);
  tft.fillRect(15, 65, 130, 130, TFT_BLACK);
  tft.fillRect(198, 65, 45, 20, TFT_COLORR);
  tft.fillRect(258, 65, 45, 20, TFT_COLORR);
  tft.fillRect(178, 100, 45, 20, TFT_COLORR);
  tft.fillRect(238, 100, 45, 20, TFT_COLORR);
  tft.fillRect(178, 135, 45, 20, TFT_COLORR);
  tft.fillRect(178, 170, 45, 20, TFT_COLORR);

  delay(250);
  tft.fillRect(175, 65, 130, 130, TFT_BLACK);
  // Your code for integer 1
  // This code will execute continuously until new data is received
  // You can add a condition to break the loop if needed
}

void executeCodeForInteger2() {
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 2", 110, 210);
  tft.fillRect(15, 65, 45, 20, TFT_COLORB);
  tft.fillRect(75, 65, 45, 20, TFT_COLORB);
  tft.fillRect(38, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  tft.fillRect(98, 170, 45, 20, TFT_COLORB);

  tft.fillRect(198, 65, 45, 20, TFT_COLORR);
  tft.fillRect(258, 65, 45, 20, TFT_COLORR);
  tft.fillRect(178, 100, 45, 20, TFT_COLORR);
  tft.fillRect(238, 100, 45, 20, TFT_COLORR);
  tft.fillRect(178, 135, 45, 20, TFT_COLORR);
  tft.fillRect(178, 170, 45, 20, TFT_COLORR);
  
  delay(6000);

  tft.fillRect(15, 65, 300, 200, TFT_BLACK);
  delay(100);
  // Your code for integer 2
  // This code will execute continuously until new data is received
  // You can add a condition to break the loop if needed
}

void executeCodeForInteger3() {
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 3", 110, 210);
  tft.fillRect(15, 65, 45, 20, TFT_COLORB);
  tft.fillRect(75, 65, 45, 20, TFT_COLORB);
  tft.fillRect(38, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  tft.fillRect(98, 170, 45, 20, TFT_COLORB);

  tft.fillRect(198, 65, 45, 20, TFT_COLORR);
  tft.fillRect(258, 65, 45, 20, TFT_COLORR);
  tft.fillRect(178, 100, 45, 20, TFT_COLORR);
  tft.fillRect(238, 100, 45, 20, TFT_COLORR);
  tft.fillRect(178, 135, 45, 20, TFT_COLORR);
  tft.fillRect(178, 170, 45, 20, TFT_COLORR);

  delay(70);

  tft.fillRect(15, 65, 300, 130, TFT_BLACK);
}

void executeCodeForInteger4() {
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 4", 110, 210);
  tft.fillRect(15, 65, 45, 20, TFT_COLORB);
  tft.fillRect(75, 65, 45, 20, TFT_COLORB);
  tft.fillRect(38, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 100, 45, 20, TFT_COLORB);
  tft.fillRect(178, 135, 45, 20, TFT_COLORR);
  tft.fillRect(178, 170, 45, 20, TFT_COLORR);

  delay(300);
  tft.fillRect(15, 65, 150, 80, TFT_BLACK);
  tft.fillRect(175, 135, 60, 70, TFT_BLACK);


  tft.fillRect(198, 65, 45, 20, TFT_COLORR);
  tft.fillRect(258, 65, 45, 20, TFT_COLORR);
  tft.fillRect(178, 100, 45, 20, TFT_COLORR);
  tft.fillRect(238, 100, 45, 20, TFT_COLORR);
  tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  tft.fillRect(98, 170, 45, 20, TFT_COLORB);

  delay(300);
  tft.fillRect(166, 65, 150, 80, TFT_BLACK);
  tft.fillRect(95, 135, 60, 70, TFT_BLACK);
}

void executeCodeForInteger5() {
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 5", 110, 210);
  static int counter = 0;
  if (counter < 4){
    tft.fillRect(15, 65, 45, 20, TFT_COLORB);
    tft.fillRect(75, 65, 45, 20, TFT_COLORB);
    tft.fillRect(98, 135, 45, 20, TFT_COLORB);
    tft.fillRect(98, 170, 45, 20, TFT_COLORB);
    tft.fillRect(178, 100, 45, 20, TFT_COLORR);
    tft.fillRect(238, 100, 45, 20, TFT_COLORR);
  
    delay(70);
    tft.fillRect(15, 65, 45, 20, TFT_BLACK);
    tft.fillRect(75, 65, 45, 20, TFT_BLACK);
    tft.fillRect(98, 135, 45, 20, TFT_BLACK);
    tft.fillRect(98, 170, 45, 20, TFT_BLACK);
    tft.fillRect(178, 100, 45, 20, TFT_BLACK);
    tft.fillRect(238, 100, 45, 20, TFT_BLACK);
    delay(70);
    counter++;

  }
  else if (counter < 8){
    tft.fillRect(198, 65, 45, 20, TFT_COLORR);
    tft.fillRect(258, 65, 45, 20, TFT_COLORR);
    tft.fillRect(178, 135, 45, 20, TFT_COLORR);
    tft.fillRect(178, 170, 45, 20, TFT_COLORR);
    tft.fillRect(38, 100, 45, 20, TFT_COLORB);
    tft.fillRect(98, 100, 45, 20, TFT_COLORB);

    delay(70);
    tft.fillRect(198, 65, 45, 20, TFT_BLACK);
    tft.fillRect(258, 65, 45, 20, TFT_BLACK);
    tft.fillRect(178, 135, 45, 20, TFT_BLACK);
    tft.fillRect(178, 170, 45, 20, TFT_BLACK);
    tft.fillRect(38, 100, 45, 20, TFT_BLACK);
    tft.fillRect(98, 100, 45, 20, TFT_BLACK);
    delay(70);
    counter++;
  }
  else 
    counter = 0;
}