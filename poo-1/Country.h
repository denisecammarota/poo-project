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

class Human; //forward declaration de la clase Human

//CLASE COUNTRY/PAISES
class Country{
    private: //atributos
        static int total_countries; //numero total de paises
        int id_country; //id de un pais
        string country_name; //nombre de un pais
        HealthStats country_stats; //estadisticas de salud de un pais
        vector <Country*> country_neighbours; //paises vecinos
        vector <Human*> country_people; //personas en el paises
        vector <Human*> country_arrivals; //personas que entran en el pais
    public: //metodos
        Country(string s); //constructor, recibe solo el nombre del pais
        ~Country(); //destructor
        int get_id(); //devuelve el id de un pais
        string get_name(); //devuelve el nombre de un pais
        //añadir y remover personas del pais
        void addHuman(Human * h);
        void removeHuman(Human * h);
        //añadir paises vecinos al pais en cuestion
        void addNeighbour(Country * c);
        //metodos llamados desde instancias de human
        void moveHuman(Human * h); //mover persona de pais, sacarla de la lista del pais anterior
        bool hasVisiblyInfectious(); //true si hay personas visiblemente infectious (sick), false en caso contrario
        bool hasInfectious(); //true si hay personas infectious (infected,sick,dead o immune), false en caso contrario
        vector <Country *> get_countryneighbours(); //devuelve vecinos de un pais
        vector <Human *> get_countryresidents(); //devuelve residentes de un pais
        //metodos de get y update los health statistics de salud
        void UpdateHealthStats(); //actualiza las estadisticas de salud de un pais
        int get_healthypeople(); //devuelve numero de personas sanas en un pais
        int get_infectedpeople(); //devuelve el numero de personas infectadas en un pais
        int get_sickpeople(); //devuelve el numero de personas enfermas en un pais
        int get_immunepeople(); //devuleve el numero de personas inmunes en un pais
        int get_deadpeople(); //devuelve el numero de personas muertas en un pais
        int get_infectiouspeople(); //devuelve el numero de personas infectious en un pais
        int get_visiblyinfectiouspeople(); //devuelve el numero de personas visiblemente infectious en un pais
        HealthStats get_countrystats(); //devuelve objeto de estadisticas de salud de un pais
        //metodos de procesar movimientos y pasar dia para los humanos, llamados de passday en simulator que tiene paises
        void runHealthActions(); // pass day de las personas de un pais, se eliminan las personas que se van
        void processMoves(); // añade personas que llegan a un pais
};


#endif // COUNTRY_H_INCLUDED
