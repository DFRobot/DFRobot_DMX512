# DFRobot_DMX512
- [English Version](./README_CN.md)

这是一款集成多种功能的开发板，其中板载集成DMX512、RTC、ADC、DAC、串口、i2c、RS485等丰富接口，
使用方便，功能强大。


![产品效果图片](./resources/images/SEN0xxx.png)


## 产品链接（https://www.dfrobot.com.cn/）

    SKU：SEN0xxx

## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

* edg101WE 集成多种丰富接口
* 使用方便功能强大

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法 DFRobot_DMX512

```C++
    /**
   * @fn begin
   * @brief 初始化函数
   * @return 返回初始化状态
   * @return NONE
   */
  uint8_t begin(void);
  /**
   * @brief 控制LED灯
   * 
   * @param addr 灯的起始地址
   * @param number 灯的数据量
   * @param data 灯的亮度 
   * @return uint8_t 返回0，超出范围，返回1，正常
   */
  uint8_t LEDLight(uint16_t addr, uint8_t number, uint8_t data);
  /**
   * @brief 控制RGB灯
   * 
   * @param addr 灯的起始地址
   * @param number 灯条数
   * @param R 红色
   * @param G 绿色
   * @param B 蓝色
   * @return uint8_t 返回0，超出范围，返回1，正常
   */
  uint8_t RGBLight(uint16_t addr, uint8_t number, uint8_t R, uint8_t G, uint8_t B);
  /**
   * @brief 给指定的地址写值
   * 
   * @param addr 需要写值得地址
   * @param data 写入得数据
   */
  
  void write(uint16_t addr, uint8_t data);
```

## 方法 DFRobot_RTC

```C++
  /**
   * @fn begin
   * @brief 初始化外设传感器
   * @return 返回初始化状态
   */
  uint8_t begin(void)

  /**
   * @fn startClock
   * @brief 开始计时
   * @return NONE
   */
  void startClock(void)

  /**
   * @fn stopClock
   * @brief 停止计时
   * @return NONE
   */
  void stopClock(void)

  /**
   * @fn setYear
   * @brief 设置年
   * @param year 设置年份，范围0到99
   * @return NONE
   */
  void setYear(uint8_t year)

  /**
   * @fn setMonth
   * @brief 设置月
   * @param month 设置月份
   * @return NONE
   */
  void setMonth(eMonth month)

  /**
   * @fn setDay
   * @brief 设置天数
   * @param day 设置天数，范围1到31
   * @return NONE
   */
  void setDay(uint8_t day)

  /**
   * @fn setWeekday
   * @brief 设置星期
   * @param weekday 选择星期几
   * @return NONE
   */
  void setWeekDay(eWeekDay weekDay)

  /**
   * @fn setHour
   * @brief 设置小时值
   * @param hour 设置小时，范围0到23
   * @return NONE
   */
  void setHour(uint8_t hour)

  /**
   * @fn setMinut
   * @brief 设置分钟值
   * @param minut 设置分钟值，范围0到59
   * @return NONE
   */
  void setMinut(uint8_t minut)

  /**
   * @fn setSecond
   * @brief 设置秒钟值
   * @param second 设置秒钟值，范围0到59
   * @return NONE
   */
  void setSecond(uint8_t second)

  /**
   * @fn getTime
   * @brief 获取RTC中的时间
   * @return 返回时间结构体
   */
  sTime_t getTime(void)
```



## 兼容性

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | :----:
   dmx512          |      √       |              |             |



## 历史

- 2023/09/04 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))





