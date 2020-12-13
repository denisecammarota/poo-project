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
//metodo de pasar dia para una persona enferma
void Sick::passDay(Human * h){
    days_sick++;
    if(days_sick == g_simpars.getUntilDeadChanceDays()){ //morirse con una probabilidad despues de una determinada cantidad de dias
        if(g_simpars.dieDiceThrow()){
            h->Become_Dead(); //cambiar estado de salud a dead
        }
    }
    if(days_sick == g_simpars.getUntilImmuneDays()){ //hacerse inmune despues de una determinada cantidad de dias
        h->Become_Immune(); //cambiar estado de salud a inmune
    }
}



