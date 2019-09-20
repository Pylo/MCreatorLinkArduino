#include "MCreatorLink.h"

void setup() {
    MCreatorLink.setup(Serial2, "Device Name"); // Any hardware serial port can be used in the setup
}

void loop() {
    MCreatorLink.loop();
}