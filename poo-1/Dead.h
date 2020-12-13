#ifndef DEAD_H_INCLUDED
#define DEAD_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

//CLASE DEAD/MUERTA HEREDADA DE HEATHSTATE/ESTADO DE SALUD
class Dead: public HealthState{
    public:
        bool isDead() override;  //en este caso devuelve true
        bool isInfectious() override; //en este caso devuelve true
};


#endif // DEAD_H_INCLUDED
