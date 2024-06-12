//
// Created by lyates27 on 10/05/2024.
//

#ifndef LETTUCE_H
#define LETTUCE_H

#include "Plant.h"

namespace Planter {
    class Lettuce : public Plant {
    public:
         Lettuce()
            : Plant("Lettuce")
        {
        }

        int getType() const override
         {
             return 1;
         };

        float getModifier() const override
        {
            return 1;
        }
    };
}

#endif //LETTUCE_H
