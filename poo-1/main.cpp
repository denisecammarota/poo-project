#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Country.h"
#include "Human.h"
#include "Simulator.h"
#include "Word.h"
#include "HealthState.h"

using namespace std;



//MAIN DEL PROGRAMA POR AHORA
int main()
{
    srand((unsigned) time(0));
    Country * c = new Country("Argentina");
    Human * h = new Human(c);
    c->addHuman(h);
    c->removeHuman(h);
    cout << "hasta aca funciona" << endl;
}
