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
