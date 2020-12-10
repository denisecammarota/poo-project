#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "HealthStats.h"

using namespace std;

//
int HealthStats::get_healthyCount(){return healthy;};
void HealthStats::set_healthyCount(int hc){
    healthy = hc;
};
//
int HealthStats::get_infectedCount(){return infected;};
void HealthStats::set_infectedCount(int ic){
    infected = ic;
};
//
int HealthStats::get_sickCount(){return sick;};
void HealthStats::set_sickCount(int sc){
    sick = sc;
};
//
int HealthStats::get_immuneCount(){return immune;};
void HealthStats::set_immuneCount(int ic){
    immune = ic;
};
//
int HealthStats::get_deadCount(){return dead;};
void HealthStats::set_deadCount(int dc){
    dead = dc;
};
//
int HealthStats::get_infectiousCount(){return infectious;};
void HealthStats::set_infectiousCount(int ic){
    infectious = ic;
};
//
int HealthStats::get_visiblyInfectiousCount(){return visiblyInfectious;};
void HealthStats::set_visiblyInfectiousCount(int vic){
    visiblyInfectious = vic;
};
//
void HealthStats::add(HealthStats other){
    healthy += other.healthy;
    infected += other.infected;
    immune += other.immune;
    dead += other.dead;
    sick += other.sick;
    infectious += other.infectious;
    visiblyInfectious += other.visiblyInfectious;

};
//
void HealthStats::print(){
    cout << "healthy: " << healthy << " immune:" << immune << " dead: " << dead << " infected: " << infected << " sick: " << sick << endl;
};
