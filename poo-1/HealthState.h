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
        void passDay(Human * h){};
        bool getInfected(bool infectious) {return false;} //si se va a infectar o no
        //preguntas de tipo de estado de salud
        bool isHealthy() { return false; }
        bool isInfected() { return false; }
        bool isSick() { return false; }
        bool isImmune() { return false; }
        bool isDead() { return false; }
        // preguntas de tipo tambien
        bool isInfectious() { return false; }
        bool isVisiblyInfectious() { return false; }
};


class Healthy:public HealthState{ //a completar
    public:
        bool isHealthy() { return true; }
        bool getInfected(bool infectious,Human * h) {return false;h->Become_Infected();} //volver a escribir cuando esten las reglas y etc
};

class Infected:public HealthState{ //a completar
    int days_infected = 0;
    SimulationParameters sim_pars;
    public:
        bool isInfected() { return true; }
        bool isInfectious()  {return true;}
        void passDay(Human * h) {
            days_infected++;
            if(days_infected == sim_pars.getUntilSickDays()){
                h->Become_Sick();
            }
        };
}; //completar con definicion

class Sick:public HealthState{ //a completar
    int days_sick = 0;
    SimulationParameters sim_pars;
    public:
        bool isSick(){return true;}
        bool isInfectious(){return true;}
        bool isVisiblyInfectious() {return true;}
        void passDay(Human * h){
            days_sick++;
            //completar aca
        }
}; //completar con definicion

class Immune:public HealthState{ //esta listo
    int days_immune = 0;
    SimulationParameters sim_pars;
    public:
        bool isImmune() { return true; }
        bool isInfectious() {return true;}
        void passDay(Human * h) {
            days_immune++;
            if(days_immune == sim_pars.getUntilHealthyDays()){
                h->Become_Healthy();
            }
        }
}; //completar con definicion

class Dead:public HealthState{ //creo que esta completo
    public:
        bool isDead(){return true;}
        bool isInfectious(){return true;}
        bool isVisiblyInfectious(){return true;}
}; //completar con definicion




#endif // HEALTHSTATE_H_INCLUDED
