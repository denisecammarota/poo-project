#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Simulator.h"
#include "Country.h"
#include <algorithm>
#include <cmath> //para la funcion round


Simulator::Simulator(int r,int c){ //constructor, recibe c (columnas) y r (filas)
    //asignamos filas y columnas
    rows = r;
    columns = c;
    days_passed = 0; //iniciamos con dias = 0
    for (int row = 0; row < rows; row++) { //loop de filas
            for (int column = 0; column < columns; column++) { //loop de columnas
                //creo un pais
                string s_pais = to_string(row + 1) + "x" + to_string(column + 1); //asigna nombre al pais como numero de fila x numero de columna
                list_countries.push_back(new Country(s_pais)); //añade pais a la lista de paises
        }
    }
    int countries_size = (int) list_countries.size(); //cantidad de paises
    //asignar vecinos a cada pais
    for (int cont = 0;cont<countries_size;cont++){
        westNeighbourAdd(list_countries[cont],cont);
        eastNeighbourAdd(list_countries[cont],cont);
        northNeighbourAdd(list_countries[cont],cont);
        southNeighbourAdd(list_countries[cont],cont);
    }

};


void Simulator::populate(int peop,double pcinf){ //popular el mundo
    //recibe peop (cantidad de personas) y pcinf (porcentaje de infectados)
    vector <Human*> humans;
    //añado humanos, en principio todos sanos, al mundo. pais elegido aleatoriamente.
    for(int i=0;i<peop;i++){
        int idx =  rand() % list_countries.size(); //generar pais aleatoriamente
        humans.push_back(new Human(list_countries[idx])); //añadir persona al país
    }
    //generar estados de salud
    //enfermo a las personas que correspondan
    double infectados =  round(pcinf * peop); //pcinf esta entre 0 y 1, no en porcentaje en este caso
    for(int i=0;i<infectados;i++){
        int idx = rand() % humans.size();
        while(humans[idx]->isInfected()){ //si ya infecte a uno aletoriamente antes y vuelve a salir, infecto a otra persona
                                            //(esto sirve sobre todo cuando hay pocos humanos)
            idx = rand() % humans.size();
        }
        humans[idx]->Become_Infected(); //infectar a la persona correspondiente
    }
    //inicializar los healthstats para cada pais el primer dia
    int npaises = list_countries.size();
    for(int i=0;i<npaises;i++){
        list_countries[i]->UpdateHealthStats();
    }
};


Simulator::~Simulator(){ //destructor
    int npaises = list_countries.size();
    for(int i=0;i<npaises;i++){
        delete list_countries[i];
        list_countries[i] = nullptr;
    }
};

void Simulator::passDay(){ //pasar dia en el mundo/simulacion
    int npaises = list_countries.size();
    //primero pasamos un dia para las personas, eliminamos a los que se van de cada pais
    //de la lista de personas de cada pais
    for(int i=0;i<npaises;i++){
        list_countries[i]->runHealthActions();
    }
    // se procesan las llegadas al pais para cada pais
    for(int i=0;i<npaises;i++){
        list_countries[i]->processMoves();
    }
    //actualizo los healthstats de cada pais
    for(int i=0;i<npaises;i++){
        list_countries[i]->UpdateHealthStats();
    }
   days_passed++; //sumo un dia al contador de dias
};

int Simulator::getDaysPassed(){return days_passed + 1;} //retorna la cantidad de dias pasados


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

//metodos de impresion, estos son bastantes simples verdaderamente


ostream & operator << (ostream &out, const Simulator  * sim){
    int npaises = sim->list_countries.size();
    out << string(100, '-') << endl;
    out << "Day " << sim->days_passed << endl;
    for(int i=0;i<npaises;i++){
        out << sim->list_countries[i]->get_name() << ": ";
        out << sim->list_countries[i]->get_countrystats();
    }
    //estadisticas totales del mundo
    int h = 0;
    int in = 0;
    int s = 0;
    int d = 0;
    int im = 0;
    out << "Word (sum): ";
    for(int i=0;i<npaises;i++){
        h += sim->list_countries[i]->get_countrystats().get_healthyCount();
        in += sim->list_countries[i]->get_countrystats().get_infectedCount();
        d += sim->list_countries[i]->get_countrystats().get_deadCount();
        s += sim->list_countries[i]->get_countrystats().get_sickCount();
        im += sim->list_countries[i]->get_countrystats().get_immuneCount();
    }
    out << "healthy: " << h << " immune:" << im << " dead: " << d << " infected: " << in << " sick: " << s << endl;
    return out;
}
