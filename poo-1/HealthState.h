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

//clase HealthState/Estado de salud de una persona
class HealthState{
    public: //metodos
        virtual void passDay(Human * h); //pasar un dia para una persona, modificar el estado de salud
        //preguntas de tipo de estado de salud
        virtual bool isHealthy(); //true si la persona esta healthy/sana, false en caso contrario
        virtual bool isInfected(); //idem para infected
        virtual bool isSick();  //idem para sick
        virtual bool isImmune(); //idem para immune
        virtual bool isDead(); //idem para dead
        // preguntas de tipo tambien
        virtual bool isInfectious(); //idem anteriores para infectious
        virtual bool isVisiblyInfectious(); //idem anteriores para visibly infectious
};

#endif // HEALTHSTATE_H_INCLUDED
