#ifndef HEALTHSTATE_H_INCLUDED
#define HEALTHSTATE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"

class Human;

class HealthState{
    public:
        //acciones
        void passDay(Human * h);
        bool getInfected(bool infectious); //si se va a infectar o no
        //preguntas de tipo de estado de salud
        bool isHealthy();
        bool isInfected();
        bool isSick();
        bool isImmune();
        bool isDead();
        // preguntas de tipo tambien
        bool isInfectious();
        bool isVisiblyInfectious();
};

#endif // HEALTHSTATE_H_INCLUDED
