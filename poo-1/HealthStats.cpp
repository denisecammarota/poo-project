#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "HealthStats.h"

using namespace std;


//CLASE HEALTHSTATS/ESTADISTICAS DE SALUD

// get y set de numero de personas healthy/sanas
int HealthStats::get_healthyCount(){return healthy;};
void HealthStats::set_healthyCount(int hc){
    healthy = hc;
};

// get y set de numero de personas infected/infectadas
int HealthStats::get_infectedCount(){return infected;};
void HealthStats::set_infectedCount(int ic){
    infected = ic;
};

// get y set de numero de personas sick/enfermas
int HealthStats::get_sickCount(){return sick;};
void HealthStats::set_sickCount(int sc){
    sick = sc;
};

// get y set de numero de personas immune/inmunes
int HealthStats::get_immuneCount(){return immune;};
void HealthStats::set_immuneCount(int ic){
    immune = ic;
};

// get y set de numero de personas dead/muertas
int HealthStats::get_deadCount(){return dead;};
void HealthStats::set_deadCount(int dc){
    dead = dc;
};

// get y set de numero de personas infectious
int HealthStats::get_infectiousCount(){return infectious;};
void HealthStats::set_infectiousCount(int ic){
    infectious = ic;
};

//get y set de numero de personas visibly infectious
int HealthStats::get_visiblyInfectiousCount(){return visiblyInfectious;};
void HealthStats::set_visiblyInfectiousCount(int vic){
    visiblyInfectious = vic;
};


//sobrecarga del operador <<
ostream & operator << (ostream &out, const HealthStats hs){
    out << "healthy: " << hs.healthy << " immune:" << hs.immune << " dead: " << hs.dead << " infected: " << hs.infected << " sick: " << hs.sick << endl;
    return out;
}
