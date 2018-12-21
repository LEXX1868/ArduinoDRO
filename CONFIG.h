//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// НАСТРОЙКИ ПРОШИВКИ, МЕНЯТЬ ЗДЕСЬ !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma once
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Arduino.h>
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define _DEBUG // закомментировать для выключения отладочной информации (плюётся в Serial всякой отладочной инфой)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define SERIAL_SPEED 57600  // скорость работы с Serial
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// определения типов памяти, поддерживаемых прошивкой (не менять, это просто определения)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define EEPROM_BUILTIN 1 // встроенный EEPROM
#define EEPROM_AT24C32 2 // I2C-память AT24C32 
#define EEPROM_AT24C64 3 // I2C-память AT24C64 
#define EEPROM_AT24C128 4 // I2C-память AT24C128 
#define EEPROM_AT24C256 5 // I2C-память AT24C256 
#define EEPROM_AT24C512 6 // I2C-память AT24C512 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// какую память используем (менять ниже, на одно из значений, описанных выше)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define EEPROM_USED_MEMORY EEPROM_AT24C128 // I2C-память AT24C128
// если используется внешнняя память AT24C* - то ниже определяется индекс микросхемы. Например, китайский модуль часов реального времени
// с DS3231 на борту имеет модуль памяти с адресом на шине I2C 0x57, т.е. индекс такого модуля - 7, т.к. базовый адрес памяти на шине - 
// 0x50. Настройкой ниже можно указать адрес микросхемы памяти на шине I2C.
#define EEPROM_MEMORY_INDEX 0
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define SETT_HEADER1 0x6E // байты, сигнализирующие о наличии сохранённых настроек, первый
#define SETT_HEADER2 0xEA // и второй
//--------------------------------------------------------------------------------------------------------------------------------
// типы поддерживаемых дисплеев (не менять, это просто определения)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DISPLAY_TFT 1 // 7 '' 800x480 на контроллере SSD1963
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DISPLAY_USED DISPLAY_TFT // под какой дисплей собираем прошивку
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки модели и пинов для TFT
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define TFT_MODEL   CTE70   // 7 '' 800x480 на контроллере SSD1963
#define TFT_RS_PIN  38        // TFT RS pin
#define TFT_WR_PIN  39        // TFT WR pin
#define TFT_CS_PIN  40        // TFT CS pin
#define TFT_RST_PIN 41        // TFT RST pin

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки цветов для TFT (все цвета - в RGB565 !!!)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define BUTTON_COLORS VGA_WHITE, VGA_SILVER, VGA_GRAY, VGA_WHITE, VGA_SILVER // цвета кнопок
#define SCREEN_BACK_COLOR VGA_BLACK          // цвет фона
#define SCREEN_TEXT_COLOR VGA_WHITE          // цвет шрифта
#define AXIS_LABEL_COLOR  0x3DA9           // увет подписи для оси
#define AXIS_VALUE_COLOR 0x3DA9             // цвет для значения показаний линейки
#define AXIS_UNIT_COLOR  0x3DA9           // цвет для значения единиц измерений линейки
#define AXIS_NO_DATA_COLOR VGA_YELLOW           // цвет для "нет показаний" линейки
#define INACTIVE_AXIS_COLOR VGA_SILVER      // цвет текста для неактивной оси (выключенной из прошивки)

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// нстройки интерфейса
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define MAIN_SCREEN_LABELS_X_OFFSET 20 // с какой позиции по X рисовать подписи к линейкам
#define MAIN_SCREEN_AXIS_V_SPACING 40 // промежуток по Y между осями
#define MAIN_SCREEN_BUTTON_HEIGHT 100 // высота кнопки на главном экране
#define MAIN_SCREEN_BUTTON_V_SPACING 10 // расстояние между кнопками на главном экране, по Y
#define MAIN_SCREEN_BUTTON_H_SPACING 10 // расстояние между кнопками на главном экране, по X
#define MAIN_SCREEN_BUTTON_TEXT_PADDING 15 // расстояние от границы кнопки до текста, по X
#define MAIN_SCREEN_DATA_X_OFFSET 10 // расстояние от правой границы показаний до управляющих кнопок
#define XYZ_FONT_DOT_WIDTH  10 // ширина точки в шрифте XYZFont (точку не надо выводить во всю ширину символа шрифта
#define DIGIT_PLACES 4 // сколько знаков использовать до запятой при отображении значения оси

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки тачскрина
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define TFT_TOUCH_CLK_PIN 6
#define TFT_TOUCH_CS_PIN 5
#define TFT_TOUCH_DIN_PIN 4
#define TFT_TOUCH_DOUT_PIN 3
#define TFT_TOUCH_IRQ_PIN 2

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define RESET_TO_MAIN_SCREEN_DELAY  30000 // время в миллисекундах, после которого идёт переключение на главный экран, если какой-то экран висит долгое время
#define DISPLAY_INIT_DELAY          100  // сколько ждать инициализации дисплея, мс
#define TFT_EXTRA_RESET // закомментировать, если не нужен экстра-сброс дисплея при инициализации
#define USE_BACKLIGHT_PIN // закомментировать, если не нужно использовать пин управления подсветкой
#define BACKLIGHT_PIN A0 // номер пина управления подсветкой
#define BACKLIGHT_ON HIGH // уровень включения подстветки

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки пищалки
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define USE_BUZZER // использовать или нет пищалку (пищит при нажатии на экранные кнопки)
#define BUZZER_TIMER Timer5 // какой таймер использовать для баззера
#define BUZZER_DURATION 60 // сколько миллисекунд включать пищалку
#define BUZZER_BETWEEN_IDLE 100 // пауза между пищаниями, миллисекунд
#define BUZZER_HALT_DURATION 750 // сколько миллисекунд пищать при критической ошибке
#define BUZZER_DRIVE_PIN A10 // пин, на котором висит пищалка
#define BUZZER_ON HIGH // уровень для включения пищалки
#define BUZZER_CONTROLLER_STARTED_COUNT 3 // сколько раз пискнуть при старте контроллера

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// НАСТРОЙКИ ВНЕШНЕГО ВАТЧДОГА
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define USE_EXTERNAL_WATCHDOG // закомментировать, если не нужно использовать внешний ватчдог
#define WATCHDOG_REBOOT_PIN 66 // номер пина, на котором будут меняться уровни
#define WATCHDOG_NORMAL_LEVEL LOW // уровень на ноге, который держится WATCHDOG_WORK_INTERVAL миллисекунд
#define WATCHDOG_TRIGGERED_LEVEL HIGH // уровень импульса на ноге, который держится WATCHDOG_PULSE_DURATION миллисекунд
#define WATCHDOG_WORK_INTERVAL 5000 // через сколько миллисекунд на ноге будет уровень WATCHDOG_TRIGGERED_LEVEL
#define WATCHDOG_PULSE_DURATION 200 // сколько миллисекунд держать уровень WATCHDOG_TRIGGERED_LEVEL на ноге

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки датчиков линеек (используются емкостные с Али, см. README)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define SCALE_CLOCK_PIN 8 // номер пина для строба линеек
#define STROBE_DURATION 2 // длительность строба на линии DATA, микросекунд

// следующие две настройки нужны, если применяется схема, которая инвертирует любой из сигналов.
// по умолчанию считается, что высокий уровень на пине SCALE_CLOCK_PIN - поднимает шину в высокий уровень,
// а прочитанный высокий уровень с линий *_SCALE_DATA_PIN - означает установленную единицу бита.
// в этих настройках можно поменять это поведение.
#define BIT_IS_SET_LEVEL HIGH // уровень на шине данных, при котором считается, что бит установлен
#define STROBE_HIGH_LEVEL HIGH // уровень на линии CLK шины, который считается высоким

#define USE_X_SCALE // закомментировать, если не нужно использовать линейку по X
#define X_SCALE_DATA_PIN 9 // номер пина DATA для линейки по X
#define X_SCALE_ZERO_CAPTION "Обнулить X" // подпись на кнопке обнуления оси X

//#define USE_Y_SCALE // закомментировать, если не нужно использовать линейку по Y
#define Y_SCALE_DATA_PIN 10 // номер пина DATA для линейки по Y
#define Y_SCALE_ZERO_CAPTION "Обнулить Y" // подпись на кнопке обнуления оси Y

//#define USE_Z_SCALE // закомментировать, если не нужно использовать линейку по Z
#define Z_SCALE_DATA_PIN 11 // номер пина DATA для линейки по Z
#define Z_SCALE_ZERO_CAPTION "Обнулить Z" // подпись на кнопке обнуления оси Z

#define SCALES_UPDATE_INTERVAL 100 // через сколько миллисекунд обновлять данные с линеек (не стоит делать это значение слишком маленьким!)
//#define DUMP_SCALE_DATA_TO_SERIAL // закомментировать, если не нужно выводить данные с линеек в Serial

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки информационных диодов (НЕ ОБРАЩАЕМ ВНИМАНИЕ, ЭТО ХВОСТЫ С ПРЕДЫДУЩЕГО ПРОЕКТА)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define USE_STEPPER_RUN_DIODE // закомментировать, если не надо использовать светодиод индикации работы шаговых
#define STEPPER_RUN_DIODE_PIN A1 // номер пина светодиода индикации работы шаговых
#define STEPPER_RUN_DIODE_ON HIGH // уровень включения  светодиода индикации работы шаговых

//#define USE_NEXT_COMMAND_RUN_DIODE // закомментировать, если не надо использовать светодиод, мигающий при необходимости нажать кнопку выполнения следующей команды
#define NEXT_COMMAND_RUN_DIODE_PIN A4 // номер пина диода
#define NEXT_COMMAND_RUN_DIODE_ON HIGH // уровень включения диода

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ПРО ТАЙМЕРЫ !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
  https://github.com/ivanseidel/DueTimer/blob/master/TimerCounter.md
  
  СЛЕДУЮЩИЕ НОГИ МК - НЕ ЗАНИМАТЬ, ОНИ ИСПОЛЬЗУЮТСЯ ПОД ТАЙМЕРЫ:
  
    1. ДЛЯ ПИЩАЛКИ ИСПОЛЬЗУЕТСЯ ТАЙМЕР 5: (выводы МК PB16, PE13, PE14)

 */


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ДАЛЕЕ - СЛУЖЕБНАЯ ИНФОРМАЦИЯ, НЕ МЕНЯТЬ !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// ||
// \/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define USE_TOUCH // закомментировать, если не надо использовать тачскрин
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifdef _DEBUG
  #define DBG(s) { Serial.print((s)); }
  #define DBGLN(s) { Serial.print((s)); Serial.println(); }
#else
  #define DBG(s) (void) 0
  #define DBGLN(s) (void) 0
#endif
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

