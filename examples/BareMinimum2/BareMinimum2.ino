#include "MCreatorLink.h"

void setup() {
    // in this bare minimum setup, we specify a custom name for the Arduino: Device Name
    Serial.begin(115200);
    Serial.setTimeout(20);
    MCreatorLink.setup(Serial, "Device Name");
}

void loop() {
    MCreatorLink.loop();
}
