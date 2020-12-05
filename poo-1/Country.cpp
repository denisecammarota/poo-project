#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Human.h"
#include "Country.h"

using namespace std;


Country::Country(string s){country_name = s;id_country = total_countries;total_countries++;};
Country::~Country(){}
void Country::addHuman(Human * h){};
int Country::get_id(){return id_country;}
string Country::get_name(){return country_name;}

int Country::total_countries= 0;
