#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Country.h"
#include "HealthState.h"


        Human::Human(Country * c){
            id_persona = total_humans; //asigna id de la persona
            country = c; //asignar pais
            c->addHuman(this); //aniadir persona a pais, completar
            Become_Healthy(); //asigna estado de salud = sano, completar
            Gen_MoveDays(); //asigna dias hasta el proximo movimiento, completar
            total_humans++; //fin de creacion +1 persona
        }
        Human::~Human(){}; // completar posiblemente
        int Human::get_id(){return id_persona;} //devuelve id de persona
        void Human::Gen_MoveDays(){ //genera cantidad de dias hasta moverse
            int maximum = sim_pars.getMaxStayDays();
            int minimum = sim_pars.getMinStayDays();
            days_until_move = (rand()%(maximum-minimum+1))+minimum;
        }
        void Human::Become_Healthy(){ //asigna estado sano a una persona

        };
        void Human::Become_Infected(){

        };
        void Human::Become_Sick(){

        };

int Human::total_humans = 0;
