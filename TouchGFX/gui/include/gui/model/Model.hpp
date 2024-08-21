#ifndef MODEL_HPP
#define MODEL_HPP

#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include "DHT22.h"

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
