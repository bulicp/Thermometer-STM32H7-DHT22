#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include "DHT22.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateTempData(DHT22_DataTypedef* DHT22_Data) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
