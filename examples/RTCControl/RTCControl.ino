/*!
 * @file DACControl.ino
 * @brief This is a RTC example that sets the time and then retrieves it, printing the time via serial communication.
 * @copyright  Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version V1.0
 * @date 2022-02-14
 * @url https://github.com/DFRobot/DFRobot_DMX512
 */
#include "DFRobot_Peripheral.h"

DFRobot_RTC rtc;

void setup() {
  Serial.begin(115200);
  while(rtc.begin() != 0){
    Serial.println("init error");
    delay(1000);
  }
  Serial.println("init succeed");
  rtc.stopClock();
  rtc.setYear(22);
  rtc.setMonth(rtc.eFebruary);
  rtc.setDay(16);
  rtc.setWeekDay(rtc.eWednesday);
  rtc.setHour(8);
  rtc.setMinute(10);
  rtc.setSecond(30);
  rtc.startClock();
}

void loop(){
  sTime_t time;
  time = rtc.getTime();
  Serial.print("year:20");
  Serial.println(time.year);
  Serial.print("month:");
  Serial.println(time.month);
  Serial.print("day:");
  Serial.println(time.day);
  Serial.print("weekday:");
  Serial.println(time.weekday);
  Serial.print("hour:");
  Serial.println(time.hour);
  Serial.print("minute:");
  Serial.println(time.minute);
  Serial.print("second:");
  Serial.println(time.second);
  Serial.println("--------------------------------------------------------");
  delay(100);
}
