#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Simulator.h"
#include "Country.h"
#include <algorithm>
#include <cmath> //para la funcion round


Simulator::Simulator(int r,int c){
    //asignamos filas y columnas
    rows = r;
    columns = c;
    days_passed = 0;
    for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                //creo un pais
                string s_pais = to_string(row + 1) + "x" + to_string(column + 1);
                list_countries.push_back(new Country(s_pais));
        }
    }
    int countries_size = (int) list_countries.size();
    for (int cont = 0;cont<countries_size;cont++){
        westNeighbourAdd(list_countries[cont],cont);
        eastNeighbourAdd(list_countries[cont],cont);
        northNeighbourAdd(list_countries[cont],cont);
        southNeighbourAdd(list_countries[cont],cont);
    }

};

//inicializar el simulador
void Simulator::populate(int peop,double pcinf){
    vector <Human*> humans;
    //aniado humanos
    for(int i=0;i<peop;i++){
        int idx =  rand() % list_countries.size(); //chequeado, esta okay
        humans.push_back(new Human(list_countries[idx]));
    }
    //generar estados de salud
    //a priori los creo sanos a los humanos, ahora los enfermo a los que corresponde
    double infectados =  round(pcinf * peop); //pcinf esta entre 0 y 1, no en porcentaje en este caso
    for(int i=0;i<infectados;i++){
        int idx = rand() % humans.size();
        while(humans[idx]->isInfected()){ //si ya infecte a uno random antes y vuelve a salir, infecto a otro tipo
            idx = rand() % humans.size();
        }
        humans[idx]->Become_Infected();
    }
    //inicializar los healthstats para cada pais el primer dia
    int npaises = list_countries.size();
    for(int i=0;i<npaises;i++){
        list_countries[i]->UpdateHealthStats();
    }
};


Simulator::~Simulator(){}; //completar

void Simulator::passDay(){ //hasta aca esta todo bien verdaderamente, vamos a chequear paso por paso por que no hay movimiento
    int npaises = list_countries.size();
    for(int i=0;i<npaises;i++){
        list_countries[i]->runHealthActions(); //probamos esta parte primero
    }
    for(int i=0;i<npaises;i++){
        list_countries[i]->processMoves();
    }
    //actualizo los healthstats de cada pais
    for(int i=0;i<npaises;i++){
        list_countries[i]->UpdateHealthStats();
    }
   days_passed++; //sumo un dia al contador
};

int Simulator::getDaysPassed(){return days_passed + 1;}


//aniadir vecinos para cada pais
void Simulator::westNeighbourAdd(Country * c, int index){
    int neighbour;
    if (index % columns != 0) {
        neighbour = index - 1;
    } else {
            neighbour = index - 1 + columns;
    }
    c->addNeighbour(list_countries[neighbour]);
};


void Simulator::eastNeighbourAdd(Country * c, int index){
    int neighbour;
    if ((index % columns) != (columns - 1)) {
        neighbour = index + 1;
    } else {
        neighbour = index + 1 - columns;
    }
    c->addNeighbour(list_countries[neighbour]);
};


void Simulator::northNeighbourAdd(Country *  c, int index){
    int neighbour;
    if (index - columns >= 0) {
        neighbour = index - columns;
    } else {
        neighbour = list_countries.size() - columns + (index % columns);
    }
    c->addNeighbour(list_countries[neighbour]);
};


void Simulator::southNeighbourAdd(Country * c, int index){
    int neighbour;
    if (index + columns < (int) list_countries.size()) {
        neighbour = index + columns;
    } else {
        neighbour = index % columns;
    }
    c->addNeighbour(list_countries[neighbour]);
};

void Simulator::print_simulator_bycountries(){
    int npaises = list_countries.size();
    cout << "Day " << days_passed << endl;
    for(int i=0;i<npaises;i++){
        cout << list_countries[i]->get_name() << ": ";
        list_countries[i]->get_countrystats().print();
    }
}

void Simulator::print_simulator_all(){
    int npaises = list_countries.size();
    int h = 0;
    int in = 0;
    int s = 0;
    int d = 0;
    int im = 0;
    cout << "Word (sum): ";
    for(int i=0;i<npaises;i++){
        h += list_countries[i]->get_countrystats().get_healthyCount();
        in += list_countries[i]->get_countrystats().get_infectedCount();
        d += list_countries[i]->get_countrystats().get_deadCount();
        s += list_countries[i]->get_countrystats().get_sickCount();
        im += list_countries[i]->get_countrystats().get_immuneCount();
    }
    cout << "healthy: " << h << " immune:" << im << " dead: " << d << " infected: " << in << " sick: " << s << endl;
}

