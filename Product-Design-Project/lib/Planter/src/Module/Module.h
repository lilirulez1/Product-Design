//
// Created by lyates27 on 10/05/2024.
//

#ifndef MODULE_H
#define MODULE_H

#include "Plant/Plant.h"

namespace Planter
{
    enum Commands
    {
        LightLevel,
        SetPlant
    };

    class Module
    {
    public:
        explicit Module(const byte address)
            : address(address)
        {}

        ~Module()
        = default;

        void update(const int lightLevel) const {
            const uint8_t highByte = (lightLevel >> 8) & 0x03;
            const uint8_t lowByte = lightLevel & 0xFF;

            Wire.beginTransmission(address);
            Wire.write(LightLevel);
            Wire.write(highByte);
            Wire.write(lowByte);
            Wire.endTransmission();
        }

        void setPlant(const Plant& plant) const
        {
            Wire.beginTransmission(address);
            Wire.write(SetPlant);
            Wire.write(plant.getType());
            Wire.endTransmission();
        }

    private:
        byte address;
    };
} // Planter

#endif //MODULE_H
