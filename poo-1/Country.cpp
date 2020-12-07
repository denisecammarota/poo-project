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


Country::Country(string s){country_name = s;id_country = total_countries;total_countries++;};
Country::~Country(){}
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

void Country::moveHuman(Human * h){country_arrivals.push_back(h);};

int Country::total_countries= 0;
