/*!
 * @file DFRobot_Peripheral.h
 * @brief This is the library for peripheral functions of the DMX512 development board.
 * @copyright	Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version V1.0
 * @date 2022-2-10
 * @url https://github.com/DFRobot/DFRobot_DMX512
 */
#ifndef _DFROBOT_PERIPHERAL_H_
#define _DFROBOT_PERIPHERAL_H_

#include "Arduino.h"
#include "Wire.h"
#include "math.h"

//#define ENABLE_DBG //!< Uncomment this macro to enable detailed program execution logging
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define PERIPHERALSCLPIN 3
#define PERIPHERALSDAPIN 2

class DFRobot_Peripheral
{
public:
  /**
   * @fn begin
   * @brief Initialize peripheral sensors
   * @param reg Register to read
   * @return Initialization status
   */
  uint8_t begin(uint8_t addr, uint8_t reg);

  /**
   * @fn writeReg
   * @brief Write register function, designed as a virtual function, to be implemented by derived classes
   * @param reg Register address 8 bits
   * @param pBuf Buffer to write data to
   * @param size Length of data to be written
   * @return None
   */
  void writeReg(uint8_t addr, uint8_t reg, void* pBuf, size_t size);

  /**
   * @fn readReg
   * @brief Read register function, designed as a virtual function, to be implemented by derived classes
   * @param reg Register address 8 bits
   * @param pBuf Buffer to store the read data
   * @param size Length of data to be read
   * @return uint8_t type, indicating the read register status
   * @retval 0 Read successful
   * @retval 1 Read failed
   */
  uint8_t readReg(uint8_t addr, uint8_t reg, void* pBuf, size_t size);

  TwoWire *_pWire;
  
};

/**
 * @fn sTime_t
 * @brief Time data structure
 */
typedef struct{
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t weekday;
  uint8_t hour;
  uint8_t minute;
  uint8_t second; 
}sTime_t;

class DFRobot_RTC:public DFRobot_Peripheral
{
  #define CONTROLSTATUS1    0X00
  #define CONTROLSTATUS2    0X01
  #define VLSECONDS         0X02
  #define MINUTES           0X03
  #define HOURS             0X04
  #define DAYS              0X05
  #define WEEKDAYS          0X06
  #define CENTURYMONTHS     0X07
  #define YEARS             0X08
  #define MINUTEALARM       0X09
  #define HOURALARM         0X0A
  #define DAYALARM          0X0B
  #define WEEKDAYALARM      0x0C

public:

  /**
   * @fn eWeekDays
   * @brief Day of the week selection
   */
  typedef enum{
    eSun = 0,
    eMon,
    eTues,
    eWed,
    eThur,
    eFri,
    eSat,
  }eWeekDay;

  /**
   * @fn eMonth
   * @brief Month selection 
   */
  typedef enum{
    eJan = 1,
    eFeb,
    eMar,
    eApr,
    eMay,
    eJun,
    eJul,
    eAug,
    eSep,
    eOct,
    eNov,
    eDec,
  }eMonth;

 

  DFRobot_RTC(TwoWire *pWire = &Wire, uint8_t adaddressdr = 0X51);
  /**
   * @fn begin
   * @brief Initialize peripheral sensor
   * @return Initialization status
   */
  uint8_t begin(void);

  /**
   * @fn startClock
   * @brief Start the clock
   * @return None
   */
  void startClock(void);

  /**
   * @fn stopClock
   * @brief Stop the clock
   * @return None
   */
  void stopClock(void);

  /**
   * @fn setYear
   * @brief Set the year
   * @param year Year to set, range from 0 to 99
   * @return None
   */
  void setYear(uint8_t year);

  /**
   * @fn setMonth
   * @brief Set the month
   * @param month Month to set
   * @return None
   */
  void setMonth(eMonth month);

  /**
   * @fn setDay
   * @brief Set the day
   * @param day Day to set, range from 1 to 31
   * @return None
   */
  void setDay(uint8_t day);

  /**
   * @fn setWeekday
   * @brief Set the day of the week
   * @param weekday Day of the week to choose
   * @return None
   */
  void setWeekDay(eWeekDay weekDay);

  /**
   * @fn setHour
   * @brief Set the hour value
   * @param hour Hour to set, range from 0 to 23
   * @return None
   */
  void setHour(uint8_t hour);

  /**
   * @fn setMinute
   * @brief Set the minute value
   * @param minute Minute to set, range from 0 to 59
   * @return None
   */
  void setMinute(uint8_t minute);

  /**
   * @fn setSecond
   * @brief Set the second value
   * @param second Second to set, range from 0 to 59
   * @return None
   */
  void setSecond(uint8_t second);

  /**
   * @fn getTime
   * @brief Get the time from RTC
   * @return Time structure
   */
  sTime_t getTime(void);

  

private:
  uint8_t getSecondNumber(uint8_t number);
  uint8_t getFirstNumber(uint8_t number);
  uint8_t bcdToNumber(uint8_t first, uint8_t second);
  uint8_t _address;
  uint8_t _year;
};
#endif
