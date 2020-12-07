#ifndef IMMUNE_H_INCLUDED
#define IMMUNE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

class Immune:public HealthState{ //esta listo
    int days_immune = 0;
    public:
        bool isImmune();
        bool isInfectious();
        void passDay(Human * h);
};


#endif // IMMUNE_H_INCLUDED
