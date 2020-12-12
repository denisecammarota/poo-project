#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Human.h"
#include "HealthStats.h"
#include "Country.h"
#include <algorithm>

using namespace std;


Country::Country(string s){
    country_name = s;
    id_country = total_countries;
    total_countries++;
    UpdateHealthStats();
};


Country::~Country(){
    int n = country_people.size();
    for(int i=0;i<n;i++){
        delete country_people[i];
        country_people[i] = nullptr;
    }
    n = country_arrivals.size();
    for(int i=0;i<n;i++){
        delete country_arrivals[i];
        country_arrivals[i] = nullptr;
    }
}


int Country::get_id(){return id_country;}
string Country::get_name(){return country_name;}

//aniadir y remover personas
void Country::addHuman(Human * h){country_people.push_back(h);};
void Country::removeHuman(Human * h){
    country_people.erase(std::remove(country_people.begin(), country_people.end(), h), country_people.end());
    }; //ref: https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
//aniadir paises vecinos
void Country::addNeighbour(Country * c){
    country_neighbours.push_back(c);
};

//metodos llamados desde humans
void Country::moveHuman(Human * h){country_arrivals.push_back(h);};

bool Country::hasVisiblyInfectious(){
    return country_stats.get_visiblyInfectiousCount() > 0;
};
bool Country::hasInfectious(){
    return country_stats.get_infectiousCount() > 0;
};

vector <Country *> Country::get_countryneighbours(){
    return country_neighbours;
};

vector <Human *> Country::get_countryresidents(){
    return country_people;
};

//estadisticas sanitarias
void Country::UpdateHealthStats(){
    country_stats.set_healthyCount(get_healthypeople());
    country_stats.set_infectedCount(get_infectedpeople());
    country_stats.set_deadCount(get_deadpeople());
    country_stats.set_immuneCount(get_immunepeople());
    country_stats.set_sickCount(get_sickpeople());
    country_stats.set_infectiousCount(get_infectiouspeople());
    country_stats.set_visiblyInfectiousCount(get_visiblyinfectiouspeople());
}

int Country::get_healthypeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isHealthy()){
                res = res+1;
        }
    }
    return res;
}

int Country::get_infectedpeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isInfected()){
                res = res+1;
        }
    }
    return res;
}


int Country::get_deadpeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isDead()){
                res = res+1;
        }
    }
    return res;
}

int Country::get_sickpeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isSick()){
                res = res+1;
        }
    }
    return res;
}


int Country::get_immunepeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isImmune()){
                res = res+1;
        }
    }
    return res;
}

int Country::get_infectiouspeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isInfectious()){
                res = res+1;
        }
    }
    return res;
}


int Country::get_visiblyinfectiouspeople(){
    int n = country_people.size();
    int res = 0;
    for(int i=0;i<n;i++){
        if(country_people[i]->isVisiblyInfectious()){
                res = res+1;
        }
    }
    return res;
}

HealthStats Country::get_countrystats(){
    return country_stats;
}

//basicamente pasamos un dia para las personas del pais, despues eliminamos a las que se fueron
void Country::runHealthActions(){
    int npeople = country_people.size();
    //pasa un dia para las personas, algunas se mueven, otras se quedan en el pais donde estan
    for(int i = 0;i<npeople;i++){
        country_people[i]->passDay();
    }
    //removemos a las que se fueron del pais
    vector <Human *> people_toremove;
    //busco primero a los que voy a borrar
    for(int i=0;i<npeople;i++){
        if(country_people[i]->get_country() != this){
            people_toremove.push_back(country_people[i]);
        }
    }
    //ahora si los borro
    int nremovedpeople = people_toremove.size();
    for(int i=0;i<nremovedpeople;i++){
        removeHuman(people_toremove[i]);
    }

}

//aca aniadimos a las personas que llegaron al pais
void Country::processMoves(){
    int narrivedpeople = country_arrivals.size();
    for(int i=0;i<narrivedpeople;i++){
        addHuman(country_arrivals[i]);
    }
    country_arrivals.clear();
}

int Country::total_countries= 0;
