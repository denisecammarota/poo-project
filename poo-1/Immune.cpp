#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Immune.h"
#include "SimulatorRules.h"
#include "Human.h"


bool Immune::isImmune() { return true; }
bool Immune::isInfectious() {return true;}
void Immune::passDay(Human * h) {
    days_immune++;
    if(days_immune == g_simpars.getUntilHealthyDays()){
        h->Become_Healthy();
        }
}

