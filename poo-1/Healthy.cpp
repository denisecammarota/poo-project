#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Healthy.h"
#include "SimulatorRules.h"
#include "Human.h"
#include "SimulatorRules.h"

bool Healthy::isHealthy() { return true; }
void Healthy::getInfected(Human * h) {
    SimulationParameters sim_pars;
    if(sim_pars.infectionDiceThrow()){
        h->Become_Infected();
    }
} //volver a escribir cuando esten las reglas y etc
