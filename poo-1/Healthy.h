#ifndef HEALTHY_H_INCLUDED
#define HEALTHY_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

class Healthy: public HealthState{ //a completar
    public:
        bool isHealthy() override;
};


#endif // HEALTHY_H_INCLUDED
