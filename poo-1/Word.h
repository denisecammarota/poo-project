#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include "SimulatorRules.h"
#include "Simulator.h"

//CLASE WORD/MUNDO
class Word{
    private:
        //atributo
        Simulator * simulator; //objeto tipo simulator
    public:
        //metodo
        Word(int rows,int columns,int people,double perCent_infected); //constructor
        ~Word(); //destructor
        void passDay(); //pasar dia en el mundo
        void print_word_bycountries(); //imprime el estado de salud de cada pais en un dia determinado
        void print_word_all(); //imprime el estado de salud del mundo (suma de todos los paises)
};

#endif // WORD_H_INCLUDED
