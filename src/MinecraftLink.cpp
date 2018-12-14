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

#include "MinecraftLink.h"

MinecraftLinkImpl::MinecraftLinkImpl() {
}

void MinecraftLinkImpl::setup(HardwareSerial &serial_ref, String _deviceName) {
  if(!setupComplete) {
    serial = &serial_ref;
    serial->begin(115200);
    serial->setTimeout(20);
    deviceName = _deviceName;
    setupComplete = true;
  }
}

void MinecraftLinkImpl::setListener(void (*event_ptr)(String command, String data)) {
  event = event_ptr;
}

void MinecraftLinkImpl::setRefreshRate(int rate) {
  inputReadRefreshRate = rate;
}

void MinecraftLinkImpl::sendMessage(String message) {
  serial->print("msg:" + message + "\n");
}

void MinecraftLinkImpl::loop() {
  // 1: read, parse and react to commands
  if(serial->available()>0) {
    String command = serial->readStringUntil('?');
    String data = serial->readStringUntil('\n');
    if(command.equals("ident")) {
      serial->print("tnedi:Minecraft Link (1.0);" + deviceName + ";" + String(NUM_DIGITAL_PINS) + ";" + String(NUM_ANALOG_INPUTS) + "\n");
    } else if(command.equals("pstrt")) {
      pollInputs = true;
    } else if(command.equals("pstop")) {
      pollInputs = false;
    } else if(command.equals("prate")) {
      inputReadRefreshRate = data.toInt();
    } else if (command.equals("pinmd")) {
      int loc = data.indexOf(":");
      if(loc != -1) {
        int pin = data.substring(0, loc).toInt();
        String mode = data.substring(loc + 1, data.length());
        if(mode.equals("in"))
          pinMode(pin, INPUT);
        else if(mode.equals("out"))
          pinMode(pin, OUTPUT);
        else if(mode.equals("in_p"))
          pinMode(pin, INPUT_PULLUP);
      }
    } else if (command.equals("diwrt")) {
      int loc = data.indexOf(":");
      if(loc != -1) {
        int pin = data.substring(0, loc).toInt();
        int val = data.substring(loc + 1, data.length()).toInt();
        digitalWrite(pin, val);
      }
    } else if (command.equals("anwrt")) {
      int loc = data.indexOf(":");
      if(loc != -1) {
        int pin = data.substring(0, loc).toInt();
        int val = data.substring(loc + 1, data.length()).toInt();
        analogWrite(pin, val);
      }
    } else if (command.equals("msg")) {
      event(command, data);
    }
  }
  
  // 2: read all inputs and publish on fixed interval
  unsigned long currentMillis = millis();
  if(currentMillis - lastInputPollMillis > inputReadRefreshRate && pollInputs) {
    serial->print("digrd:");
    for(int i = 0; i < NUM_DIGITAL_PINS; i++) {
      serial->print(digitalRead(i) == HIGH ? 1 : 0);
    }
    serial->print("\n");
    
    serial->print("anlrd:");
    for(int i = 0; i < NUM_ANALOG_INPUTS; i++) {
      serial->print(analogRead(i));
      serial->print('#');
    }
    serial->print("\n");
    
    lastInputPollMillis = currentMillis;
  }
}
