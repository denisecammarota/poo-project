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
    vector<Country*> list_countries; //lista de los paises del mundo
    int days_passed; //dias que han pasado desde el comienzo de la simulacion
    int rows; //filas, ya que el mundo es una grilla de rows x columns
    int columns; //columnas, ya que el mundo es una grilla de rows x columns
    //metodos
    public:
        Simulator(int r,int c); //constructor. crea los paises del mundo
        void populate(int peop,double pcinf);  // añade personas al mundo
        ~Simulator(); // destructor
        void passDay(); //pasar un dia
        int getDaysPassed(); //retorna los dias pasados (days_passed)
        //metodos que sirven para añadir vecinos para un pais
        void westNeighbourAdd(Country *  c, int index); //añadir vecino al west/oeste
        void eastNeighbourAdd(Country * c, int index); //añadir vecino al east/este
        void northNeighbourAdd(Country * c, int index); //añadir vecino al north/norte
        void southNeighbourAdd(Country * c, int index); //añadir vecino al south/sur
        //metodos de impresión
        friend ostream & operator << (ostream &out, const Simulator * sim);
};



#endif // SIMULATOR_H_INCLUDED
