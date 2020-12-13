#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "SimulatorRules.h"
#include "Simulator.h"
#include "Word.h"

using namespace std;
//CLASE WORD/MUNDO


World::World(int rows,int columns,int people,double perCent_infected){ //crea el mundo una vez recibidos los parametros
    if(perCent_infected > 1){
        throw PercentageNumberError();
    }
    if(rows < 1){
        throw RowNumberError{};
    }
    if(columns < 1){
        throw ColumnNumberError{};
    }
    simulator = new Simulator(rows,columns);
    simulator->populate(people,perCent_infected);
}

World::~World(){delete simulator; simulator = nullptr;} //destructor


void World::passDay(){ //pasar dia en el mundo, llama al passDay de simulator
    simulator->passDay();
}


ostream & operator << (ostream &out, const World &w){
    out << w.simulator;
    return out;
}


