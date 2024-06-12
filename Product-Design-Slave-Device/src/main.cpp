#include <Arduino.h>
#include <Module.h>

void setup() {
    Planter::Module::getInstance().setup();
}

void loop() {
    Planter::Module::getInstance().update();
}