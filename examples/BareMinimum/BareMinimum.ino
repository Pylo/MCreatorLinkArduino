#include "MinecraftLink.h"

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(20);
    MinecraftLink.setup(Serial);
}

void loop() {
    MinecraftLink.loop();
}