#ifndef INFECTED_H_INCLUDED
#define INFECTED_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

class Infected:public HealthState{
    int days_infected = 0;
    public:
        bool isInfected() override;
        bool isInfectious() override;
        void passDay(Human * h) override;
};


#endif // INFECTED_H_INCLUDED
