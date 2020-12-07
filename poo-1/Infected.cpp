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
    SimulationParameters sim_pars;
    days_infected++;
    if(days_infected == sim_pars.getUntilSickDays()){
        h->Become_Sick();
    }
};
