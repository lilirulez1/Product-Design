#include <Arduino.h>

#include <Planter.h>

Planter::Planter planter;

void setup() {
    planter.setup();
}

void loop() {
    planter.update();
}