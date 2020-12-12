#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Country.h"
#include "HealthState.h"
#include "Healthy.h"

class Country;
class HealthState;
//CLASE HUMANOS
class Human{
    private:
        //atributos de una persona
        static int total_humans; //cantidad de personas creadas
        int id_persona; //id de la persona
        int days_until_move; //dias que faltan hasta movimiento
        HealthState * health; //estado de salud
        Country * country; //pais donde esta la persona
    public:
        Human(Country * c);
        ~Human();
        int get_id();
        void Gen_MoveDays();
        //
        void Become_Healthy();
        void Become_Infected();
        void Become_Sick();
        void Become_Dead();
        void Become_Immune();
        //
        bool isHealthy();
        bool isInfected();
        bool isSick();
        bool isImmune();
        bool isDead();
        //
        bool isInfectious();
        bool isVisiblyInfectious();
        //imprimir (despues si tengo tiempo hago el overloading, por ahora no)
        void print();
        //moving y etc
        Country * selectDestination();
        void moving(Country * dest_country);
        //pass day que creo que es el ultimo metodo que me quedaba
        void passDay();
        //get country
        Country * get_country();
};





#endif // HUMAN_H_INCLUDED
