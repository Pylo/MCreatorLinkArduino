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

#ifndef MCreatorLink_h
#define MCreatorLink_h

#include "Arduino.h"
#include "BoardNames.h"

class MCreatorLinkImpl
{
  private:
    Stream* serial;
    bool setupComplete = false;
    int inputReadRefreshRate = 20;
    bool pollInputs = false;
    unsigned long lastInputPollMillis = 0;
    void (*event)(String command, String data);
    String deviceName;
  public:

    /*
    Constructor for the MCreatorLinkImpl object, does nothing at the moment
    */
    MCreatorLinkImpl();

    /*
    Setup function that needs to be called in order for Minecraft Link to work.
    Serial communication is initialized at this point for the selected HardwareSerial interface.
    */
    void setup(Stream &serial_ref = SERIAL_PORT_MONITOR, String deviceName = BOARD);
	
    /*
    Actual Link logic happens here. This function needs to be called each Arduino loop iteration.
    */
    void loop();

    /*
    Call this function to send custom message through the link.
    */
    void sendMessage(String message);

    /*
    Here the listener function for the inbound messages can be set. See examples for more info.
    */
    void setListener(void (*event)(String command, String data));

    /*
    Function to set the refresh rate of the input checking.
    */
    void setRefreshRate(int rate);
};

static MCreatorLinkImpl MCreatorLink;

#endif
