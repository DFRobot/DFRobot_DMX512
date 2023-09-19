# DFRobot_DMX512
- [Chinese Version](./README_CN.md)

This is a development board that integrates various functions, including onboard DMX512, RTC, ADC, DAC, serial, i2c, RS485, and more. It is easy to use and powerful.

![Product Image](./resources/images/SEN0xxx.png)

## Product Link (https://www.dfrobot.com.cn/)

SKU: DFR0994

## Table of Contents

  * [Overview](#overview)
  * [Library Installation](#library-installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Authors](#authors)

## Overview

* edg101WE integrates various rich interfaces.
* Easy to use and powerful in functionality.

## Library Installation

Before using this library, please download the library files, paste them into the \Arduino\libraries directory, and then open the examples folder and run the demo in that folder.

## Methods DFRobot_DMX512

```C++
    /**
   * @fn begin
   * @brief Initialization function
   * @return Initialization status
   * @return NONE
   */
  uint8_t begin(void);
  /**
   * @brief Control LED lights
   * 
   * @param addr Starting address of the lights
   * @param number Number of lights
   * @param data Brightness of the lights 
   * @return uint8_t Returns 0 if out of range, 1 if normal
   */
  uint8_t LEDLight(uint16_t addr, uint8_t number, uint8_t data);
  /**
   * @brief Control RGB lights
   * 
   * @param addr Starting address of the lights
   * @param number Number of light strips
   * @param R Red color
   * @param G Green color
   * @param B Blue color
   * @return uint8_t Returns 0 if out of range, 1 if normal
   */
  uint8_t RGBLight(uint16_t addr, uint8_t number, uint8_t R, uint8_t G, uint8_t B);
  /**
   * @brief Write a value to the specified address
   * 
   * @param addr Address to write the value to
   * @param data Data to be written
   */
  
  void write(uint16_t addr, uint8_t data);

```

## Methods DFRobot_RTC

```C++
   /**
   * @fn begin
   * @brief Initialize peripheral sensor
   * @return Initialization status
   */
  uint8_t begin(void)

  /**
   * @fn startClock
   * @brief Start the clock
   * @return NONE
   */
  void startClock(void)

  /**
   * @fn stopClock
   * @brief Stop the clock
   * @return NONE
   */
  void stopClock(void)

  /**
   * @fn setYear
   * @brief Set the year
   * @param year Year to set, range from 0 to 99
   * @return NONE
   */
  void setYear(uint8_t year)

  /**
   * @fn setMonth
   * @brief Set the month
   * @param month Month to set
   * @return NONE
   */
  void setMonth(eMonth month)

  /**
   * @fn setDay
   * @brief Set the day
   * @param day Day to set, range from 1 to 31
   * @return NONE
   */
  void setDay(uint8_t day)

  /**
   * @fn setWeekday
   * @brief Set the day of the week
   * @param weekday Day of the week to choose
   * @return NONE
   */
  void setWeekDay(eWeekDay weekDay)

  /**
   * @fn setHour
   * @brief Set the hour value
   * @param hour Hour to set, range from 0 to 23
   * @return NONE
   */
  void setHour(uint8_t hour)

  /**
   * @fn setMinute
   * @brief Set the minute value
   * @param minute Minute to set, range from 0 to 59
   * @return NONE
   */
  void setMinute(uint8_t minute)

  /**
   * @fn setSecond
   * @brief Set the second value
   * @param second Second to set, range from 0 to 59
   * @return NONE
   */
  void setSecond(uint8_t second)

  /**
   * @fn getTime
   * @brief Get the time from RTC
   * @return Time structure
   */
  sTime_t getTime(void)
```



## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | :----:
   dmx512          |      √       |              |             |



## History
- 2023/09/04 - Version 1.0.0

## Authors

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
