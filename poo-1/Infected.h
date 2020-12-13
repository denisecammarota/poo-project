#ifndef INFECTED_H_INCLUDED
#define INFECTED_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

//CLASE INFECTED/INFECTADA HEREDADA DE HEATHSTATE/ESTADO DE SALUD
class Infected:public HealthState{
    int days_infected = 0;
    public:
        bool isInfected() override; //devuelve true en este caso
        bool isInfectious() override; //devuelve true en este caso
        void passDay(Human * h) override; //pasar dia para una persona infectada
};


#endif // INFECTED_H_INCLUDED
