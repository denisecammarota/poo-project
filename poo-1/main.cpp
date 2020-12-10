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
    Word w(4,4,100,0.5);
    w.print_word();
    int dias_totales = 1;
    for(int i = 0;i<dias_totales;i++){
        w.passDay();
    }
    w.print_word();
}
