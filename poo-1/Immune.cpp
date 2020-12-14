#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Immune.h"
#include "SimulatorRules.h"
#include "Human.h"


bool Immune::isImmune() { return true; }
void Immune::passDay(Human * h) {
    days_immune++;
    if(days_immune == g_simpars.getUntilHealthyDays()){ //despues de una determinada cantidad de casos, vuelve a ser sana
                                                        //y se va a poder volver a infectar
        h->Become_Healthy();
        }
}

