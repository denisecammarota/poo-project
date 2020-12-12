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
    days_sick++;
    if(days_sick == g_simpars.getUntilDeadChanceDays()){
        if(g_simpars.dieDiceThrow()){
            h->Become_Dead();
        }
    }
    if(days_sick == g_simpars.getUntilImmuneDays()){
        h->Become_Immune();
    }
    //completar aca
}



