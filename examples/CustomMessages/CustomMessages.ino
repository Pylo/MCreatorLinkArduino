#include "MCreatorLink.h"

void dataEvent(String command, String data) {
  // if you send a message from the Link API inside Minecraft with this format command?data
  // this function will be called when the message is received
  // you can then parse these messages inside this function and use them
  if(command.equals("customCommand1")) {
    // do something
  }
}

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(20);
    MCreatorLink.setup(Serial, "Device Name");
    MCreatorLink.setListener(dataEvent);
}

void loop() {
    MCreatorLink.loop();
}