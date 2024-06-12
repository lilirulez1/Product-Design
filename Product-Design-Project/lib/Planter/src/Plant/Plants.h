//
// Created by lyates27 on 31/05/2024.
//

#ifndef PLANTS_H
#define PLANTS_H

#include "Plant.h"
#include "Lettuce.h"

namespace Planter
{
    static Plant* plants[10] = { nullptr };

    static Plant& registerPlant(Plant* plant) {
        plants[plant->getType()] = plant;
        return *plant;
    }

    static Lettuce LETTUCE = dynamic_cast<Lettuce&>(registerPlant(new Lettuce()));

    static Plant* readPlant(const int index) {
        return plants[index];
    }

    static int serializePlant(const Plant* plant) {
        return plant->getType();
    }
}

#endif //PLANTS_H
