#ifndef DEAD_H_INCLUDED
#define DEAD_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

class Dead: public HealthState{
    public:
        bool isDead();
        bool isInfectious();
        bool isVisiblyInfectious();
};


#endif // DEAD_H_INCLUDED
