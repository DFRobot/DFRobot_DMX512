/*!
 * @file  DFRobot_DMX512.cpp
 * @brief 这是一个通过DMX512库的实现
 * @copyright	Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license   The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2023-09-04
 * @url       https://github.com/DFRobot/DFRobot_DMX512
 */
#include "DFRobot_DMX512.h"

DFRobot_DMX512::DFRobot_DMX512(TwoWire *pWire,uint8_t adaddressdr)
{
  _pWire  = pWire;
  _addr = adaddressdr;
}

//extern uart_inst_t * const uart1;
uint8_t DFRobot_DMX512::begin(void)
{   
  uint8_t head = 0x55;
  uint8_t addrL = 1 & 0xff;
  uint8_t addrH = (1 >> 8 ) & 0xff;
  pinMode(PIN_DI1,INPUT);
  pinMode(PIN_DI2,INPUT);
  pinMode(PIN_DI3,INPUT);
  pinMode(PIN_DI4,INPUT);
  pinMode(PIN_DI5,INPUT);
  pinMode(PIN_DI6,INPUT);
  pinMode(PIN_DI7,INPUT);
  pinMode(PIN_DI8,INPUT);
  pinMode(PIN_OUT,OUTPUT);
  delay(100);
  _pWire->begin(1,2);
  _pWire->beginTransmission(_addr);
  if(_pWire->endTransmission() == 0){
    _pWire->beginTransmission(_addr);
    _pWire->write(&head,1);
    _pWire->write(&addrL,1);
    _pWire->write(&addrH,1);
    for(uint16_t i = 0; i < 512;i++){
      _pWire->write(0);
    }
    _pWire->endTransmission();
    return 0;
  }
    return 1;

}


void DFRobot_DMX512::write(uint16_t addr, uint8_t data)
{
  uint8_t head = 0x55;
  uint8_t addrL = addr & 0xff;
  uint8_t addrH = (addr >> 8 ) & 0xff;
  _pWire->beginTransmission(_addr);
  _pWire->write(&head,1);
  _pWire->write(&addrL,1);
  _pWire->write(&addrH,1);
  _pWire->write(data);
  _pWire->endTransmission();
  
}


  uint8_t DFRobot_DMX512::LEDLight(uint16_t addr, uint8_t number, uint8_t data)
  {
    uint16_t i = 0;
    uint8_t _addr = addr;
    uint8_t len = number;
    if((len + _addr) > 512){
      return 0;
    }
    for(;i < len;i++){
      write(_addr,data);
      _addr += 1;
    }
    return 1;
  }

  uint8_t DFRobot_DMX512::RGBLight(uint16_t addr, uint8_t number, uint8_t R, uint8_t G, uint8_t B)
  {
    uint16_t i = 0;
    uint8_t _addr = addr;
    uint8_t len = number * 3;
    if((len + _addr) > 512){
      return 0;
    }
    for(;i < len;){
      write(_addr,R);
      write(_addr+1,G);
      write(_addr+2,B);
      _addr+=3;
      i += 3;
    }
  return 1;
  }

  uint8_t DFRobot_DMX512::digitalIN(ePin pin){
    uint8_t data = 0;
    switch(pin){
      case DI1:
        data = digitalRead(PIN_DI1);
      break;
      case DI2:
        data = digitalRead(PIN_DI2);
      break;
      case DI3:
        data = digitalRead(PIN_DI3);
      break;
      case DI4:
        data = digitalRead(PIN_DI4);
      break;
      case DI5:
        data = digitalRead(PIN_DI5);
      break;
      case DI6:
        data = digitalRead(PIN_DI6);
      break;
      case DI7:
        data = digitalRead(PIN_DI7);
      break;
      case DI8:
        data = digitalRead(PIN_DI8);
      break;
      default:
      break;
    }
    return data;
  }

 void DFRobot_DMX512::relayOUT(uint8_t mode){
  digitalWrite(PIN_OUT,mode);
 }

