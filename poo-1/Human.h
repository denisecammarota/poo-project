#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Country.h"
#include "HealthState.h"


class Country;
//CLASE HUMANOS
class Human{
    private:
        //atributos de una persona
        static int total_humans; //cantidad de personas creadas
        int id_persona; //id de la persona
        int days_until_move; //dias que faltan hasta movimiento
        HealthState * health; //estado de salud
        Country * country; //pais donde esta la persona
        SimulationParameters sim_pars;
    public:
        Human(Country * c);
        ~Human();
        int get_id();
        void Gen_MoveDays();
        void Become_Healthy();
        void Become_Infected();
        void Become_Sick();

};





#endif // HUMAN_H_INCLUDED
