#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include "SimulatorRules.h"
#include "Simulator.h"

//CLASE WORD/MUNDO
class Word{
    private:
        Simulator * simulator;
        SimulationParameters sim_pars;
    public:
        Word(int rows,int columns,int people,double perCent_infected);
        ~Word();
        void passDay();
        void print_word_bycountries();
        void print_word_all();
};

#endif // WORD_H_INCLUDED
