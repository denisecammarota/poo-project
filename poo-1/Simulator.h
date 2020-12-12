#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED

#include <algorithm>
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
        //aniadir vecinos para un pais
        void westNeighbourAdd(Country *  c, int index);
        void eastNeighbourAdd(Country * c, int index);
        void northNeighbourAdd(Country * c, int index);
        void southNeighbourAdd(Country * c, int index);
        void print_simulator_bycountries();
        void print_simulator_all();
};



#endif // SIMULATOR_H_INCLUDED
