#ifndef SICK_H_INCLUDED
#define SICK_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

class Sick:public HealthState{ //a completar
    int days_sick = 0;
    public:
        bool isSick() override;
        bool isInfectious() override;
        bool isVisiblyInfectious() override;
        void passDay(Human * h) override;
};

#endif // SICK_H_INCLUDED
