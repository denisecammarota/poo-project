#ifndef HEALTHSTATE_H_INCLUDED
#define HEALTHSTATE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"

class Human; //forward declaration de la clase Human

//clase HealthState que representa estado de salud
class HealthState{
    public:
        //acciones
        virtual void passDay(Human * h);
        //preguntas de tipo de estado de salud
        virtual bool isHealthy();
        virtual bool isInfected();
        virtual bool isSick();
        virtual bool isImmune();
        virtual bool isDead();
        // preguntas de tipo tambien
        virtual bool isInfectious();
        virtual bool isVisiblyInfectious();
};

#endif // HEALTHSTATE_H_INCLUDED
