//
// Created by lyates27 on 15/05/2024.
//

#ifndef MODULE_H
#define MODULE_H

#include <Color.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Plant/Plants.h>

enum Commands
{
    LightLevel,
    SetPlant
};

enum EepromLocations
{
    PlantType
};

namespace Planter {

class Module {
public:
    static Module& getInstance()
    {
        static Module instance;
        return instance;
    }

     void setup() {
        Wire.begin(0x01);
        Serial.begin(9600);
        pinMode(LED_BUILTIN, OUTPUT);

        Wire.onReceive(onRecieveStatic);
    }

    void update() {
        const int modifiedLightLevel = map(lightLevel * plant->getModifier(), 0, 1023, 0, 255);
        color = Color(modifiedLightLevel, modifiedLightLevel, modifiedLightLevel);

        analogWrite(3, color.r);
        analogWrite(5, color.g);
        analogWrite(6, color.b);
    }

    Module(Module const&) = delete;
    void operator=(Module const&) = delete;

private:
    Module()
        : color(Color::black()), plant(readPlant(EEPROM.read(PlantType)))
    {}

    int lightLevel{};
    Color color;
    Plant* plant;

    void onRecieve(int howMany)
    {
        while (Wire.available())
        {
            const int command = Wire.read();

            switch (command)
            {
            case command == LightLevel:
                const byte highByte = Wire.read();
                const byte lowByte = Wire.read();
                lightLevel = (highByte << 8) | lowByte;

                break;
            case command == SetPlant:
                const byte newPlant = Wire.read();
                EEPROM.write(PlantType, newPlant);
                plant = readPlant(newPlant);

                break;
            default:
                Serial.println("[ERROR] No command find with receive byte");
            }
        }
    }

    static void onRecieveStatic(int howMany)
    {
        getInstance().onRecieve(howMany);
    }
};

} // Planter

#endif //MODULE_H
