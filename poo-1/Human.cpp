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

void Human::moving(Country * dest_country){
    dest_country->moveHuman(this);
    country = dest_country; //destination country
    if(country->hasVisiblyInfectious() && sim_pars.infectionDiceThrow()){ //si se infecta o no (pasa al moverse)
        Become_Infected(); //creo que asi sin el this-> funcionara bien, SINO REVISAR Y CAMBIAR
    }
};

void Human::passDay(){
    health->passDay(this);
    if(isDead()!=true){
        days_until_move--;
    }
    if(days_until_move == 0){
        Gen_MoveDays();
        Country * dest_country = selectDestination();
        if(dest_country != nullptr){
            moving(dest_country);
        }
    }
}


int Human::total_humans = 0;
