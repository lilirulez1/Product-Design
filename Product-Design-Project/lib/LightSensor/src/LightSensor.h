//
// Created by lyates27 on 10/05/2024.
//

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H



class LightSensor {
public:
    explicit LightSensor(const int pin)
        : pin(pin)
    {

    }
    ~LightSensor() = default;

    int read()
    {
        value = analogRead(pin);
        return value;
    }

private:
    int pin;
    int value{};
};



#endif //LIGHTSENSOR_H
