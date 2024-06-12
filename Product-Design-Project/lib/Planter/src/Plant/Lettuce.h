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
           : Plant("Lettuce", 600)
        {
        }

        int getType() const override
        {
            return 1;
        };
    };
}

#endif //LETTUCE_H
