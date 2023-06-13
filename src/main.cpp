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

TaskHandle_t Task1;
TaskHandle_t Task0;

TFT_eSPI tft = TFT_eSPI();

const int potentiometer = 35;
const int bit1 = 0;
const int bit2 = 14;
const int bit3 = 27;
const int bit4 = 26; 

int selectedMode = 0;

void executeCodeForInteger1();
void executeCodeForInteger2();
void executeCodeForInteger3();
void executeCodeForInteger4();
void executeCodeForInteger5();
void executeCodeForInteger6();
void executeCodeForInteger7();
void executeCodeForInteger8();
void executeCodeForInteger9();
void executeCodeForInteger10();

void setLEDs(boolean blue1, boolean blue2, boolean red1, boolean red2);

void Task1code( void * pvParameters ){
  while(1){
    delay(100);
    int sensorValue = 0;
    for(int i=0; i<100; i++){
      sensorValue += analogRead(potentiometer);
    }
    sensorValue = sensorValue/100;

    Serial.print("Received sensor: ");
    Serial.println(sensorValue);

    selectedMode = (300 + sensorValue)/400;
  }
}

void Task2code( void * pvParameters ){
  while(1){
    if (selectedMode==0){
      Serial.println("Executing code for integer 0");
      tft.fillRect(15, 65, 300, 200, TFT_BLACK);
      delay(100);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, LOW);
      digitalWrite(bit4, LOW);
    }
    else if(selectedMode==1){
      Serial.println("Executing code for integer 1");
      executeCodeForInteger1();
    }else if(selectedMode==2){
      Serial.println("Executing code for integer 2");
      executeCodeForInteger2();
    }else if(selectedMode==3){
      Serial.println("Executing code for integer 3");
      executeCodeForInteger3();
    }else if(selectedMode==4){
      Serial.println("Executing code for integer 4");
      executeCodeForInteger4();
    }else if(selectedMode==5){
      Serial.println("Executing code for integer 5");
      executeCodeForInteger5();
    }else if(selectedMode==6){
      Serial.println("Executing code for integer 6");
      executeCodeForInteger6();
    }else if(selectedMode==7){
      Serial.println("Executing code for integer 7");
      executeCodeForInteger7();
    }else if(selectedMode==8){
      Serial.println("Executing code for integer 8");
      executeCodeForInteger8();
    }else if(selectedMode==9){
      Serial.println("Executing code for integer 9");
      executeCodeForInteger9();
    }else if(selectedMode==10){
      Serial.println("Executing code for integer 10");
      executeCodeForInteger10();
    }else{
      Serial.println("Unrecognized integer");
      tft.fillRect(15, 65, 300, 200, TFT_BLACK);
  }
  }
}

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

  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);

  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Control Display",     /* name of task. */
                    4096,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 0 */                  
  delay(100); 

  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Control output",     /* name of task. */
                    4096,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task0,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */ 

}

void loop (){
}


void executeCodeForInteger1() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 1", 110, 190);
  
  setLEDs(1,1,0,0);
  delay(250);
  setLEDs(0,0,1,1);
  delay(250);
}

void executeCodeForInteger2() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 2", 110, 190);

  setLEDs(1,1,1,1);
  delay(100);
}

void executeCodeForInteger3() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 3", 110, 190);
  
  setLEDs(1,1,1,1);
  delay(70);
  setLEDs(0,0,0,0);
  delay(70);
}

void executeCodeForInteger4() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 4", 110, 190);
  setLEDs(1,0,0,1);
  delay(300);
  setLEDs(0,1,1,0);
  delay(300);
}

void executeCodeForInteger5() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 5", 110, 190);

  setLEDs(0,1,0,1);
  delay(200);
  setLEDs(1,0,1,0);
  delay(200);
}

void executeCodeForInteger6() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 6", 110, 190);
  
  static int counter = 0;
  if (counter < 3){
    setLEDs(1,0,0,1);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter < 6){
    setLEDs(0,1,1,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if(counter < 9){
    setLEDs(1,1,1,1);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else{
    counter = 0;
  }
}

void executeCodeForInteger7() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 7", 110, 190);

  static int counter = 0;
  if (counter == 0 || counter == 2 || counter == 3 || counter == 5){ 
    setLEDs(1,0,0,1);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if(counter == 1 || counter == 4 || counter == 6 || counter == 7){ 
    setLEDs(0,1,1,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else{
    counter = 0;
  }

}

void executeCodeForInteger8() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, HIGH);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 8", 110, 190);
  static int counter = 0;
  if (counter == 0){
    setLEDs(0,1,0,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter == 1){
    setLEDs(1,0,0,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter == 2){
    setLEDs(0,0,1,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter == 3){
    setLEDs(0,0,0,1);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else {
    counter = 0;
  }
}

void executeCodeForInteger9() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, HIGH);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 9", 110, 190);
  static int counter = 0;
  if (counter < 2){
    setLEDs(1,0,1,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter < 4){
    setLEDs(0,1,1,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter < 6){
    setLEDs(1,0,1,0);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else if (counter < 8){
    setLEDs(1,0,0,1);
    delay(100);
    setLEDs(0,0,0,0);
    delay(100);
    counter++;
  }else{
    counter=0;
  }
}

void executeCodeForInteger10() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, HIGH);
  tft.fillRect(100, 190, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 10", 110, 190);

  setLEDs(1,0,1,0);
  delay(150);
  setLEDs(0,0,0,0);
  delay(150);
}

void setLEDs(boolean blue1, boolean blue2, boolean red1, boolean red2){
  if (blue1 == 1){
    tft.fillRect(15, 100, 45, 20, TFT_COLORB);
    tft.fillRect(75, 100, 45, 20, TFT_COLORB);
  }else {
    tft.fillRect(15, 100, 45, 20, TFT_BLACK);
    tft.fillRect(75, 100, 45, 20, TFT_BLACK);
  } 

  if (blue2 == 1){
    tft.fillRect(38, 135, 45, 20, TFT_COLORB);
    tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  }else {
    tft.fillRect(38, 135, 45, 20, TFT_BLACK);
    tft.fillRect(98, 135, 45, 20, TFT_BLACK);
  }

  if (red1 == 1){
    tft.fillRect(198, 100, 45, 20, TFT_COLORR);
    tft.fillRect(258, 100, 45, 20, TFT_COLORR);
  }else{
    tft.fillRect(198, 100, 45, 20, TFT_BLACK);
    tft.fillRect(258, 100, 45, 20, TFT_BLACK);
  }

  if (red2 == 1){
    tft.fillRect(178, 135, 45, 20, TFT_COLORR);
    tft.fillRect(238, 135, 45, 20, TFT_COLORR);
  }else {
    tft.fillRect(178, 135, 45, 20, TFT_BLACK);
    tft.fillRect(238, 135, 45, 20, TFT_BLACK);
  }
}