#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "SimulatorRules.h"
#include "Simulator.h"
#include "Word.h"

//CLASE WORD/MUNDO
Word::Word(int rows,int columns,int people,double perCent_infected){
    simulator = new Simulator(rows,columns);
    simulator->populate(people,perCent_infected);
}

Word::~Word(){delete simulator; simulator = nullptr;}


void Word::passDay(){
    simulator->passDay();
}

void Word::print_word_bycountries(){
    simulator->print_simulator_bycountries();
}

void Word::print_word_all(){
    simulator->print_simulator_all();
}
