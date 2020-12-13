#ifndef HEALTHY_H_INCLUDED
#define HEALTHY_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

//CLASE HEALHY/SANA HEREDADA DE HEATHSTATE/ESTADO DE SALUD
class Healthy: public HealthState{
    public:
        bool isHealthy() override; //en este caso, esta funcion devuelve true
};


#endif // HEALTHY_H_INCLUDED
