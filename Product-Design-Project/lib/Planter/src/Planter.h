//
// Created by lyates27 on 10/05/2024.
//

#ifndef PLANTER_H
#define PLANTER_H

#include <LightSensor.h>
#include <Wire.h>


#include "Plant/Plant.h"
#include "Plant/Lettuce.h"
#include "Plant/Plants.h"

#include "Module/Module.h"

namespace Planter {
    enum Commands;

    class Planter {
    public:
        explicit Planter()
            : lightSensor(A0)
        {

        }
        ~Planter()
        {
            for (int i = 0; i < moduleCount; ++i) {
                delete modules[i];
            }
        }

        void setup()
        {
            Wire.begin();
            Serial.begin(9600);
            pinMode(LED_BUILTIN, OUTPUT);

            const Module* module = addModule(0x01);
            module->setPlant(LETTUCE);
        };

        void update()
        {
            const int lightLevel = lightSensor.read();

            for (int i = 0; i < moduleCount; ++i) {
                modules[i]->update(lightLevel);
            }

            delay(100);
        };

    private:
        LightSensor lightSensor;

        int moduleCount{};
        Module* modules[6]{};

        Module* addModule(const int address)
        {
            moduleCount++;
            modules[address] = new Module(address);
            return modules[address];
        }
    };
}



#endif //PLANTER_H
