//
// Created by lyates27 on 10/05/2024.
//

#ifndef PLANT_H
#define PLANT_H

namespace Planter {

    class Plant {
    public:
        Plant(const String& name, const int requiredLight)
           : name(name), requiredLight(requiredLight)
        {
        }

        virtual ~Plant() = default;

        virtual int getType() const = 0;
    private:
        String name;
        int requiredLight;
    };

}

#endif //PLANT_H
