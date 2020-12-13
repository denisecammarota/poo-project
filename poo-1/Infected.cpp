#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Infected.h"
#include "SimulatorRules.h"
#include "Human.h"


bool Infected::isInfected() { return true; }
bool Infected::isInfectious()  {return true;}
void Infected::passDay(Human * h) {
    days_infected++; //pasar un dia que la persona esta infectada
    if(days_infected == g_simpars.getUntilSickDays()){ //pasada una determinada cantidad de dias, pasa a estar enferma
        h->Become_Sick();
    }
};
