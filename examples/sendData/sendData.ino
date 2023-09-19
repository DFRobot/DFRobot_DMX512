/*!
 * @file lightControlLED.ino
 * @brief This is an example of controlling LED lights using DMX512.
 * @copyright  Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version V1.0
 * @date 2022-02-14
 * @url https://github.com/DFRobot/DFRobot_DMX512
 */
#include "DFRobot_DMX512.h"

DFRobot_DMX512 dmx512;
int x = 0;
int y = 0;
uint8_t buf[512];
uint8_t i = 0;
void setup() {
  Serial.begin(115200);
  while(dmx512.begin() != 0){
    Serial.println("Initialization error");
    delay(1000);
  }
  Serial.println("Initialization successful");
}

void loop() {
  dmx512.write(1, 255);
  dmx512.write(2, 255);
  dmx512.write(3, 100);
  dmx512.write(4, 255);
  dmx512.write(5, 255);
  dmx512.write(6, 255);
  dmx512.write(7, 0);
  dmx512.write(8, 0);
  dmx512.write(9, 0);
  delay(2000);
}
