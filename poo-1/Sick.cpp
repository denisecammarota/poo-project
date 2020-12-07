#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Sick.h"
#include "SimulatorRules.h"
#include "Human.h"


bool Sick::isSick(){return true;}
bool Sick::isInfectious(){return true;}
bool Sick::isVisiblyInfectious() {return true;}
void Sick::passDay(Human * h){
    SimulationParameters sim_pars;
    days_sick++;
    if(days_sick == sim_pars.getUntilDeadChanceDays()){
        if(sim_pars.dieDiceThrow()){
            h->Become_Dead();
        }
    }
    if(days_sick == sim_pars.getUntilImmuneDays()){
        h->Become_Immune();
    }
    //completar aca
}



