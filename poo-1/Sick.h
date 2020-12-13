#ifndef SICK_H_INCLUDED
#define SICK_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

//CLASE SICK/ENFERMA HEREDADA DE HEATHSTATE/ESTADO DE SALUD
class Sick:public HealthState{ //atributos
    int days_sick = 0; //contador de dias que una persona esta enferma
    public:
        bool isSick() override; //devuelve true en este caso
        bool isInfectious() override; //develve true en este caso
        bool isVisiblyInfectious() override; //idem, devuelve true
        void passDay(Human * h) override; //pasar dias para una persona enferma
};

#endif // SICK_H_INCLUDED
