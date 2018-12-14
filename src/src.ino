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

// this file is only a placeholder so this folder can be open in Arduino as a project
// you can also use it for debugging purposes

#include "MinecraftLink.h"

void dataEvent(String command, String data) {
    if(command.equals("customCommand1")) {
        // do something with the inbound data
    }
}

void setup() {
    MinecraftLink.setup();
    //MinecraftLink.setup(Serial);
    //MinecraftLink.setup(Serial, "Device LNK1");
    MinecraftLink.setListener(dataEvent);
}

void loop() {
    MinecraftLink.loop();
}
