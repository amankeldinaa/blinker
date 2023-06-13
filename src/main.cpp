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

int receivedData = 0;

void executeCodeForInteger1();
void executeCodeForInteger2();
void executeCodeForInteger3();
void executeCodeForInteger4();
void executeCodeForInteger5();
void executeCodeForInteger6();
void executeCodeForInteger7();
void executeCodeForInteger8();
void executeCodeForInteger9();

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

    if (sensorValue < 100){
      receivedData = 0;
    }
    else if(sensorValue > 100 && sensorValue < 500){
      receivedData = 1;
    }
    else if (sensorValue > 500 && sensorValue < 900){
      receivedData = 2;
    }
    else if (sensorValue > 900 && sensorValue < 1300){
      receivedData = 3;
    }
    else if (sensorValue > 1300 && sensorValue < 1700){
      receivedData = 4;
    }
    else if (sensorValue > 1700 && sensorValue < 2100){
      receivedData = 5;
    }
     else if (sensorValue > 2100 && sensorValue < 2500){
      receivedData = 6;
    }
     else if (sensorValue > 2500 && sensorValue < 2900){
      receivedData = 7;
    }
     else if (sensorValue > 2900 && sensorValue < 3300){
      receivedData = 8;
    }
     else if (sensorValue > 3300 && sensorValue < 3700){
      receivedData = 9;
    }
  }
}

void Task2code( void * pvParameters ){
  while(1){
    if (receivedData==0){
      Serial.println("Executing code for integer 0");
      tft.fillRect(15, 65, 300, 200, TFT_BLACK);
      delay(100);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, LOW);
      digitalWrite(bit4, LOW);
    }
    else if(receivedData==1){
      Serial.println("Executing code for integer 1");
      executeCodeForInteger1();
    }else if(receivedData==2){
      Serial.println("Executing code for integer 2");
      executeCodeForInteger2();
    }else if(receivedData==3){
      Serial.println("Executing code for integer 3");
      executeCodeForInteger3();
    }else if(receivedData==4){
      Serial.println("Executing code for integer 4");
      executeCodeForInteger4();
    }else if(receivedData==5){
      Serial.println("Executing code for integer 5");
      executeCodeForInteger5();
    }else if(receivedData==6){
      Serial.println("Executing code for integer 6");
      executeCodeForInteger6();
    }else if(receivedData==7){
      Serial.println("Executing code for integer 7");
      executeCodeForInteger7();
    }else if(receivedData==8){
      Serial.println("Executing code for integer 8");
      executeCodeForInteger8();
    }else if(receivedData==9){
      Serial.println("Executing code for integer 9");
      executeCodeForInteger9();
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
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, LOW);
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
  
  delay(100);

  // tft.fillRect(15, 65, 300, 200, TFT_BLACK);
  // delay(100);
  // Your code for integer 2
  // This code will execute continuously until new data is received
  // You can add a condition to break the loop if needed
}

void executeCodeForInteger3() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, LOW);
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
  delay(70);
}

void executeCodeForInteger4() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
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
  delay(300);
}

void executeCodeForInteger5() {

  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 5", 110, 210);
  static int counter = 0;
    if (counter < 2 ) {
      tft.fillRect(198, 65, 45, 20, TFT_COLORR);
      tft.fillRect(258, 65, 45, 20, TFT_COLORR);
      tft.fillRect(178, 100, 45, 20, TFT_COLORR);
      tft.fillRect(238, 100, 45, 20, TFT_COLORR);
      tft.fillRect(98, 135, 45, 20, TFT_COLORB);
      tft.fillRect(98, 170, 45, 20, TFT_COLORB);
      delay(80);  // LEDs ON for 500ms
      tft.fillRect(98, 65, 45, 135, TFT_BLACK);
      delay(80);  // LEDs OFF for 500ms500ms

      tft.fillRect(15, 65, 350, 135, TFT_BLACK);
      counter++;
      } else if ( counter < 4){
      tft.fillRect(15, 65, 45, 20, TFT_COLORB);
      tft.fillRect(75, 65, 45, 20, TFT_COLORB);
      tft.fillRect(38, 100, 45, 20, TFT_COLORB);
      tft.fillRect(98, 100, 45, 20, TFT_COLORB);
      tft.fillRect(178, 135, 45, 20, TFT_COLORR);
      tft.fillRect(178, 170, 45, 20, TFT_COLORR);
      delay(80);  // LEDs ON for 500ms
      tft.fillRect(198, 65, 45, 135, TFT_BLACK);
      delay(80);  // LEDs OFF for 500ms
      tft.fillRect(15, 65, 350, 135, TFT_BLACK);
      counter++;
      }else{
      counter = 0;
      }

  // delay(70);
  // tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  // tft.setFreeFont(&Open_Sans_Bold_22);
  // tft.drawString("NUSQA 5", 110, 210);
  // static int counter = 0;
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

void executeCodeForInteger6() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 6", 110, 210);
  tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  tft.fillRect(98, 170, 45, 20, TFT_COLORB);
  tft.fillRect(178, 135, 45, 20, TFT_COLORR);
  tft.fillRect(178, 170, 45, 20, TFT_COLORR);
  delay(200);
  tft.fillRect(98, 135, 45, 20, TFT_BLACK);
  tft.fillRect(98, 170, 45, 20, TFT_BLACK);
  tft.fillRect(178, 135, 45, 20, TFT_BLACK);
  tft.fillRect(178, 170, 45, 20, TFT_BLACK);
  tft.fillRect(38, 100, 45, 20, TFT_COLORB);
  tft.fillRect(98, 100, 45, 20, TFT_COLORB);
  tft.fillRect(178, 100, 45, 20, TFT_COLORR);
  tft.fillRect(238, 100, 45, 20, TFT_COLORR);
  delay(200);
  tft.fillRect(38, 100, 45, 20, TFT_BLACK);
  tft.fillRect(98, 100, 45, 20, TFT_BLACK);
  tft.fillRect(178, 100, 45, 20, TFT_BLACK);
  tft.fillRect(238, 100, 45, 20, TFT_BLACK);
  tft.fillRect(15, 65, 45, 20, TFT_COLORB);
  tft.fillRect(75, 65, 45, 20, TFT_COLORB);
  tft.fillRect(198, 65, 45, 20, TFT_COLORR);
  tft.fillRect(258, 65, 45, 20, TFT_COLORR);

  delay(200);
  tft.fillRect(15, 65, 45, 20, TFT_BLACK);
  tft.fillRect(75, 65, 45, 20, TFT_BLACK);
  tft.fillRect(198, 65, 45, 20, TFT_BLACK);
  tft.fillRect(258, 65, 45, 20, TFT_BLACK);
  delay(70);

}

void executeCodeForInteger7() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit4, LOW);
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 7", 110, 210);
  tft.fillRect(15, 65, 45, 20, TFT_COLORB);
  tft.fillRect(75, 65, 45, 20, TFT_COLORB);
  tft.fillRect(198, 65, 45, 20, TFT_COLORR);
  tft.fillRect(258, 65, 45, 20, TFT_COLORR);
  delay(100);
  tft.fillRect(15, 65, 45, 20, TFT_BLACK);
  tft.fillRect(75, 65, 45, 20, TFT_BLACK);
  tft.fillRect(198, 65, 45, 20, TFT_BLACK);
  tft.fillRect(258, 65, 45, 20, TFT_BLACK);
  delay(70);

}

void executeCodeForInteger8() {
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, HIGH);
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 8", 110, 210);
  tft.fillRect(98, 135, 45, 20, TFT_COLORB);
  tft.fillRect(98, 170, 45, 20, TFT_COLORB);
  tft.fillRect(178, 135, 45, 20, TFT_COLORR);
  tft.fillRect(178, 170, 45, 20, TFT_COLORR);

  delay(100);
  tft.fillRect(98, 135, 45, 20, TFT_BLACK);
  tft.fillRect(98, 170, 45, 20, TFT_BLACK);
  tft.fillRect(178, 135, 45, 20, TFT_BLACK);
  tft.fillRect(178, 170, 45, 20, TFT_BLACK);

  delay(100);
}

void executeCodeForInteger9() {
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit4, HIGH);
  tft.fillRect(100, 210, 200, 50, TFT_BLACK);
  tft.setFreeFont(&Open_Sans_Bold_22);
  tft.drawString("NUSQA 9", 110, 210);
  static int counter = 0;
      if (counter < 2 ) {
        tft.fillRect(178, 100, 45, 20, TFT_COLORR);
        tft.fillRect(238, 100, 45, 20, TFT_COLORR);
        tft.fillRect(178, 135, 45, 20, TFT_COLORR);
        tft.fillRect(178, 170, 45, 20, TFT_COLORR);
        tft.fillRect(15, 65, 45, 20, TFT_COLORB);
        tft.fillRect(75, 65, 45, 20, TFT_COLORB);
        delay(80);  // LEDs ON for 500ms

        tft.fillRect(15, 65, 45, 20, TFT_BLACK);
        tft.fillRect(75, 65, 45, 20, TFT_BLACK);
        tft.fillRect(38, 100, 45, 20, TFT_BLACK);
        tft.fillRect(98, 100, 45, 20, TFT_BLACK);
        tft.fillRect(98, 135, 45, 20, TFT_BLACK);
        tft.fillRect(98, 170, 45, 20, TFT_BLACK);


        tft.fillRect(178, 100, 45, 20, TFT_BLACK);
        tft.fillRect(238, 100, 45, 20, TFT_BLACK);
        tft.fillRect(178, 135, 45, 20, TFT_BLACK);
        tft.fillRect(178, 170, 45, 20, TFT_BLACK);
        tft.fillRect(15, 65, 45, 20, TFT_BLACK);
        tft.fillRect(75, 65, 45, 20, TFT_BLACK);
        delay(80); 
        counter++;
      } else if (counter < 4){
        tft.fillRect(38, 100, 45, 20, TFT_COLORB);
        tft.fillRect(98, 100, 45, 20, TFT_COLORB);
        tft.fillRect(98, 135, 45, 20, TFT_COLORB);
        tft.fillRect(98, 170, 45, 20, TFT_COLORB);
        tft.fillRect(198, 65, 45, 20, TFT_COLORR);
       tft.fillRect(258, 65, 45, 20, TFT_COLORR);
        delay(80); 

        tft.fillRect(198, 65, 45, 20, TFT_BLACK);
        tft.fillRect(258, 65, 45, 20, TFT_BLACK);
        tft.fillRect(178, 100, 45, 20, TFT_BLACK);
        tft.fillRect(238, 100, 45, 20, TFT_BLACK);
        tft.fillRect(178, 135, 45, 20, TFT_BLACK);
        tft.fillRect(178, 170, 45, 20, TFT_BLACK);
   

        tft.fillRect(38, 100, 45, 20, TFT_BLACK);
        tft.fillRect(98, 100, 45, 20, TFT_BLACK);
        tft.fillRect(98, 135, 45, 20, TFT_BLACK);
        tft.fillRect(98, 170, 45, 20, TFT_BLACK);
        tft.fillRect(198, 65, 45, 20, TFT_BLACK);
        tft.fillRect(258, 65, 45, 20, TFT_BLACK);
        delay(80); 

        counter++;
      }else{
      counter = 0;
      }
}