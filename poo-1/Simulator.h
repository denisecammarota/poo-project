#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Country.h"

//CLASE SIMULATOR
class Simulator{
    //atributos
    vector<Country*> list_countries;
    int days_passed;
    int rows;
    int columns;
    //metodos
    public:
        Simulator(int r,int c);
        void populate(int peop,double pcinf);
        ~Simulator(); //completar
        void passDay();
        int getDaysPassed();
};



#endif // SIMULATOR_H_INCLUDED
