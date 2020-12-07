#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Country.h"
#include "HealthState.h"
#include "Healthy.h"
#include "Infected.h"
#include "Sick.h"
#include "Immune.h"
#include "Dead.h"


        Human::Human(Country * c){
            id_persona = total_humans; //asigna id de la persona
            country = c; //asignar pais
            c->addHuman(this); //aniadir persona a pais, completar
            health = new Healthy;
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
            delete health;
            health = new Healthy;
        };
        void Human::Become_Infected(){
            delete health;
            health = new Infected;
        };
        void Human::Become_Sick(){
            delete health;
            health = new Sick;
        };
        void Human::Become_Dead(){
            delete health;
            health = new Dead;
        };
        void Human::Become_Immune(){
            delete health;
            health = new Immune;
        };

        //preguntas sobre los estados de salud de las personas
        bool Human::isHealthy(){
            bool v = health->isHealthy();
            return v;
        }
        bool Human::isDead(){
            bool v = health->isDead();
            return v;
        }
        bool Human::isSick(){
            bool v = health->isSick();
            return v;
        }
        bool Human::isInfected(){
            bool v = health->isInfected();
            return v;
        }
        bool Human::isImmune(){
            bool v = health->isImmune();
            return v;
        }
        bool Human::isInfectious(){
            bool v = health->isInfectious();
            return v;
        }
        bool Human::isVisiblyInfectious(){
            bool v = health->isVisiblyInfectious();
            return v;
        }
        void Human::print(){
            cout << "Humano con id: " << id_persona << "\nPais: " << country->get_name() << endl;
        }



int Human::total_humans = 0;
