#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include "SimulatorRules.h"
#include "Simulator.h"

using namespace std;
//CLASE WORD/MUNDO
class World{
    private:
        //atributo
        Simulator * simulator; //objeto tipo simulator
        class RowNumberError{};
        class ColumnNumberError{};
        class PercentageNumberError{};
    public:
        //metodo
        World(int rows,int columns,int people,double perCent_infected); //constructor
        ~World(); //destructor
        void passDay(); //pasar dia en el mundo
        void print_world_bycountries(); //imprime el estado de salud de cada pais en un dia determinado
        void print_world_all(); //imprime el estado de salud del mundo (suma de todos los paises)
        friend ostream & operator << (ostream &out, const World &w); //sobrecarga del operador <<
};

#endif // WORD_H_INCLUDED
