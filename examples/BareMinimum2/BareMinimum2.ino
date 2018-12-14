#include "MinecraftLink.h"

void setup() {
    // in this bare minimum setup, we specify a custom name for the Arduino: Device Name
    MinecraftLink.setup(Serial, "Device Name");
}

void loop() {
    MinecraftLink.loop();
}
