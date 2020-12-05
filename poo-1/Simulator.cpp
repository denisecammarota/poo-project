#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Simulator.h"
#include "Country.h"

Simulator::Simulator(int r,int c){
    //asignamos filas y columnas
    rows = r;
    columns = c;
    days_passed = 0;
};

void Simulator::populate(int peop,double pcinf){};//completar
Simulator::~Simulator(){}; //completar
void Simulator::passDay(){days_passed++;};
int Simulator::getDaysPassed(){return days_passed + 1;}


