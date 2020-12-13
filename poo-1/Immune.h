#ifndef IMMUNE_H_INCLUDED
#define IMMUNE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"


//CLASE IMMUNE/INMUNE HEREDADA DE HEATHSTATE/ESTADO DE SALUD
class Immune:public HealthState{
    int days_immune = 0; //dias que lleva siendo inmune
    public:
        bool isImmune() override; //devuelve true en este caso
        bool isInfectious() override; //devuelve true en este caso
        void passDay(Human * h) override; //pasa un dia para una persona inmune
};


#endif // IMMUNE_H_INCLUDED
