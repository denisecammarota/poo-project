#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "SimulatorRules.h"
#include "Simulator.h"
#include "Word.h"

//CLASE WORD/MUNDO
Word::Word(int rows,int columns,int people,double perCent_infected){ //constructor
    simulator = new Simulator(rows,columns);
    simulator->populate(people,perCent_infected);
}

Word::~Word(){delete simulator; simulator = nullptr;} //destructor


void Word::passDay(){ //pasar dia en el mundo, llama al passDay de simulator
    simulator->passDay();
}

void Word::print_word_bycountries(){ //imprimir paises, llama al metodo de simulator
    simulator->print_simulator_bycountries();
}

void Word::print_word_all(){ //idem anterior, llama a un metodo de simulator
    simulator->print_simulator_all();
}
