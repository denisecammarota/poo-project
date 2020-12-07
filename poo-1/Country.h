#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Human.h"
#include "HealthStats.h"
#include <algorithm>

using namespace std;

class Human;
//CLASE COUNTRY/PAISES
class Country{
    //atributos
    private:
        static int total_countries;
        int id_country;
        string country_name;
        HealthStats country_stats;
        vector <Country*> country_neighbours; //paises vecinos
        vector <Human*> country_people; //personas en el paises
        vector <Human*> country_arrivals; //personas que entran en el pais
    //metodos
    public:
        Country(string s);
        ~Country();
        int get_id();
        string get_name();
        //aniadir y remover personas
        void addHuman(Human * h);
        void removeHuman(Human * h);
        //aniadir paises vecinos
        void addNeighbour(Country * c);
        //metodos llamados de humans
        void moveHuman(Human * h);
        bool hasVisiblyInfectious();
        bool hasInfectious();
        vector <Country *> get_countryneighbours();
        vector <Human *> get_countryresidents();
        //metodos de get y update los health statistics de salud
        void UpdateHealthStats();
        int get_healthypeople();
        int get_infectedpeople();
        int get_sickpeople();
        int get_immunepeople();
        int get_deadpeople();
        int get_infectiouspeople();
        int get_visiblyinfectiouspeople();
        HealthStats get_countrystats();
};


#endif // COUNTRY_H_INCLUDED
