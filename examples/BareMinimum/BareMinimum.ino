#include "MCreatorLink.h"

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(20);
    MCreatorLink.setup(Serial);
}

void loop() {
    MCreatorLink.loop();
}