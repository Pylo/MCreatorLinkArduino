#include "MinecraftLink.h"

void setup() {
    MinecraftLink.setup(Serial2, "Device Name"); // Any hardware serial port can be used in the setup
}

void loop() {
    MinecraftLink.loop();
}