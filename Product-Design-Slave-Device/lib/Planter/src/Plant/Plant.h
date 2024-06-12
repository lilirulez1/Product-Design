//
// Created by lyates27 on 10/05/2024.
//

#ifndef PLANT_H
#define PLANT_H

namespace Planter {

class Plant {
public:
     Plant(const String& name)
        : name(name)
    {
    }

    virtual ~Plant() = default;

    virtual int getType() const = 0;

    virtual float getModifier() const = 1;
private:
    String name;
};

}

#endif //PLANT_H
