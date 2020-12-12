#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "SimulatorRules.h"

//como explicado en el .h, es bastante directo lo que hago aca
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
bool SimulationParameters::dieDiceThrow(){
    double number = ((double) rand() / (RAND_MAX));
    return number <= probToDie;
}
//para posibles futuras implementaciones, como se aclaro en el .h
//bool  SimulationParameters::travelDiceThrow(){
    //double number = ((double) rand() / (RAND_MAX));
    //return number <= probToTravel;
//}

SimulationParameters g_simpars; //objeto global g_simpars
