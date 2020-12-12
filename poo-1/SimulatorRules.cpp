#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "SimulatorRules.h"

SimulationParameters::SimulationParameters(){};
SimulationParameters::~SimulationParameters(){};
int  SimulationParameters::getMaxStayDays(){return daysMaxStay;}
int  SimulationParameters::getMinStayDays(){return daysMinStay;}
int  SimulationParameters::getUntilSickDays(){return daysUntilSick;}
int  SimulationParameters::getUntilDeadChanceDays(){return daysUntilDeadChance;}
int  SimulationParameters::getUntilImmuneDays(){return daysUntilImmune;}
int  SimulationParameters::getUntilHealthyDays(){return daysUntilHealthy;}
bool  SimulationParameters::infectionDiceThrow(){
    double number = ((double) rand() / (RAND_MAX));
    return number <= probToTransmitVirus;
}
bool  SimulationParameters::travelDiceThrow(){
    double number = ((double) rand() / (RAND_MAX));
    return number <= probToTravel;
}
bool SimulationParameters::dieDiceThrow(){
    double number = ((double) rand() / (RAND_MAX));
    return number <= probToDie;
}

SimulationParameters g_simpars;
