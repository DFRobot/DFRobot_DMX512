/*!
 * @file  DFRobot_DMX512.h
 * @brief This is a library for controlling lights via DMX512.
 * @copyright	Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license   The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2023-09-04
 * @url       https://github.com/DFRobot/DFRobot_DMX512
 */
#ifndef DFROBOT_DMX512_H
#define DFROBOT_DMX512_H

#include "Arduino.h"
#include "String.h"
#include "Wire.h"

#if 0
#define DBG(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define PIN_DI1 7
#define PIN_DI2 10
#define PIN_DI3 18
#define PIN_DI4 35
#define PIN_DI5 36
#define PIN_DI6 37
#define PIN_DI7 38
#define PIN_DI8 39
#define PIN_OUT 46

typedef enum{
      DI1,
      DI2,
      DI3,
      DI4,
      DI5,
      DI6,
      DI7,
      DI8
}ePin;

class DFRobot_DMX512
{
public:

  /**
   * @fn DFRobot_DMX512
   * @brief Constructor interface
   */
  DFRobot_DMX512(TwoWire *pWire = &Wire, uint8_t adaddressdr = 0x2E);

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
  /**
   * @brief read pin data
   * 
   * @param pin pin number
   * @return pin data
  */
  uint8_t digitalIN(ePin pin);
  /**
   * @brief pilot relay
   * 
   * @param mode 0:close,1:open
  */
  void relayOUT(uint8_t mode);

private:
  TwoWire *_pWire;
  uint8_t _addr;
  uint8_t _dataBuf[515];
};
#endif
