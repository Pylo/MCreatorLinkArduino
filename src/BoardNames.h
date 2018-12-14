/*
 * Copyright 2018 Pylo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined(TEENSYDUINO)
    #if defined(__AVR_ATmega32U4__)
        #define BOARD "Teensy 2.0"
    #elif defined(__AVR_AT90USB1286__)
        #define BOARD "Teensy++ 2.0"
    #elif defined(__MK20DX128__)
        #define BOARD "Teensy 3.0"
    #elif defined(__MK20DX256__)
        #define BOARD "Teensy 3.2"
    #elif defined(__MKL26Z64__)
        #define BOARD "Teensy LC"
    #elif defined(__MK64FX512__)
        #define BOARD "Teensy 3.5"
    #elif defined(__MK66FX1M0__)
        #define BOARD "Teensy 3.6"
    #else
        #define BOARD "Arduino Link Device"
    #endif
#else
    #if   defined(ARDUINO_AVR_ADK)
        #define BOARD "Arduino Mega Adk"
    #elif defined(ARDUINO_AVR_BT)
        #define BOARD "Arduino Bt"
    #elif defined(ARDUINO_AVR_DUEMILANOVE)
        #define BOARD "Arduino Duemilanove"
    #elif defined(ARDUINO_AVR_ESPLORA)
        #define BOARD "Arduino Esplora"
    #elif defined(ARDUINO_AVR_ETHERNET)
        #define BOARD "Arduino Ethernet"
    #elif defined(ARDUINO_AVR_FIO)
        #define BOARD "Arduino Fio"
    #elif defined(ARDUINO_AVR_GEMMA)
        #define BOARD "Arduino Gemma"
    #elif defined(ARDUINO_AVR_LEONARDO)
        #define BOARD "Arduino Leonardo"
    #elif defined(ARDUINO_AVR_LILYPAD)
        #define BOARD "Arduino Lilypad"
    #elif defined(ARDUINO_AVR_LILYPAD_USB)
        #define BOARD "Arduino Lilypad Usb"
    #elif defined(ARDUINO_AVR_MEGA)
        #define BOARD "Arduino Mega"
    #elif defined(ARDUINO_AVR_MEGA2560)
        #define BOARD "Arduino Mega 2560"
    #elif defined(ARDUINO_AVR_MICRO)
        #define BOARD "Arduino Micro"
    #elif defined(ARDUINO_AVR_MINI)
        #define BOARD "Arduino Mini"
    #elif defined(ARDUINO_AVR_NANO)
        #define BOARD "Arduino Nano"
    #elif defined(ARDUINO_AVR_NG)
        #define BOARD "Arduino NG"
    #elif defined(ARDUINO_AVR_PRO)
        #define BOARD "Arduino Pro"
    #elif defined(ARDUINO_AVR_ROBOT_CONTROL)
        #define BOARD "Arduino Robot Ctrl"
    #elif defined(ARDUINO_AVR_ROBOT_MOTOR)
        #define BOARD "Arduino Robot Motor"
    #elif defined(ARDUINO_AVR_UNO)
        #define BOARD "Arduino Uno"
    #elif defined(ARDUINO_AVR_YUN)
        #define BOARD "Arduino Yun"
    #elif defined(ARDUINO_SAM_DUE)
        #define BOARD "Arduino Due"
    #elif defined(ARDUINO_SAMD_ZERO)
        #define BOARD "Arduino Zero"
    #elif defined(ARDUINO_ARC32_TOOLS)
        #define BOARD "Arduino 101"
    #else
        #define BOARD "Arduino Link Device"
    #endif
#endif