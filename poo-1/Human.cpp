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

//CLASE HUMAN/HUMANOS


        //constructor de un humano
        Human::Human(Country * c){
            id_persona = total_humans; //asigna id de la persona
            country = c; //asignar pais
            c->addHuman(this); //aniadir persona a pais, completar
            health = new Healthy;
            Become_Healthy();
            Gen_MoveDays(); //asigna dias hasta el proximo movimiento, completar
            total_humans++; //fin de creacion +1 persona
        }
        //destructor
        Human::~Human(){
            delete health;
            health = nullptr;
        };

        int Human::get_id(){return id_persona;} //devuelve id de persona

        void Human::Gen_MoveDays(){ //genera cantidad de dias hasta moverse aleatoriamente en un rango
            int maximum = g_simpars.getMaxStayDays(); //max dias de quedarse en un pais
            int minimum = g_simpars.getMinStayDays(); //min dias de quedarse en un pais
            days_until_move = (rand()%(maximum-minimum+1))+minimum; //generacion de la cantidad de dias
        }

        void Human::Become_Healthy(){ //asigna estado sano a una persona
            delete health;
            health = new Healthy;
        };
        void Human::Become_Infected(){ //asigna estado infectado a una persona
            delete health;
            health = new Infected;
        };
        void Human::Become_Sick(){ //asigna estado enfermo a una persona
            delete health;
            health = new Sick;
        };
        void Human::Become_Dead(){ //asigna estado muerto a una persona
            delete health;
            health = new Dead;
        };
        void Human::Become_Immune(){ //asigna estado inmune a una persona
            delete health;
            health = new Immune;
        };

        //preguntas sobre los estados de salud de las personas
        //explicadas antes
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

//elegir pais de destino
Country * Human::selectDestination(){
    vector<Country*> moving_candidates; //en ppio todos los candidatos
    vector<Country*> filtered_candidates; //los candidatos filtrados
    moving_candidates = country->get_countryneighbours();
    int n_candidates = moving_candidates.size();
    //filtro primero los candidatos posibles
    for(int i=0;i<n_candidates;i++){
        if(moving_candidates[i]->hasVisiblyInfectious()){
            filtered_candidates.push_back(moving_candidates[i]);
        }
    }
    //ahora elijo un pais para moverme
    n_candidates = filtered_candidates.size(); //actualizo por los filtrados ahora
    Country * dest_country = nullptr; //en ppio es nullptr
    if(n_candidates != 0){
        int idx = rand()%(n_candidates);
        dest_country = filtered_candidates[idx];
    }
    return dest_country;
}

//mover una persona de pais
void Human::moving(Country * dest_country){
    dest_country->moveHuman(this);
    country = dest_country; //pais de destino lo asigno como pais nuevo de la persona (no modificamos nada aca a la altura del pais,
                            //eso se hace en la clase country)
    if(country->hasVisiblyInfectious() && g_simpars.infectionDiceThrow()){ //si se infecta o no (pasa al moverse) con una probabilidad y si en un pais hay gente que contagia
        if(isInfectious() == false){ //si la persona no es infectious (son de esta categoria sick,immune,dead e infected)
        Become_Infected(); //enfermar a una persona
        }
    }
};

//pasa un dia en la vida de una persona
void Human::passDay(){
    health->passDay(this);
    if(isDead()!=true){ //si esta muerto no hago nada
        days_until_move--;
    }
    if(days_until_move == 0){ //si se tiene que mover una persona
        Gen_MoveDays(); //genero nuevos dias hasta que se tenga que mover
        Country * dest_country = selectDestination(); //genero pais de destino
        if(dest_country != nullptr){
            moving(dest_country); //si hay algun pais para moverse, muevo a la persona ahi
        }
    }
}

//devuelve el pais en el que esta una persona
Country * Human::get_country(){
    return country;
}

int Human::total_humans = 0;
