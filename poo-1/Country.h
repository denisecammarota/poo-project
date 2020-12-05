#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Human.h"


using namespace std;

class Human;
//CLASE COUNTRY/PAISES
class Country{
    //atributos
    private:
        static int total_countries;
        int id_country;
        string country_name;
        vector <Country*> country_neighbours; //paises vecinos
        vector <Human*> country_people; //personas en el paises
        vector <Human*> country_arrivals; //personas que entran en el pais
    //metodos
    public:
        Country(string s);
        ~Country();
        void addHuman(Human * h);
        int get_id();
        string get_name();
};


#endif // COUNTRY_H_INCLUDED
