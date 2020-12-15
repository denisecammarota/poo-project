#ifndef HEALTHSTATS_H_INCLUDED
#define HEALTHSTATS_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//CLASE HEALTHSTATS/ESTADISTICAS DE SALUD
class HealthStats{
    //numeros de la estadisticas de salud
    int healthy;
    int infected;
    int sick;
    int immune;
    int dead;
    int infectious;
    int visiblyInfectious;
    public: //metodos
        // get y set de numero de personas healthy/sanas
        int get_healthyCount();
        void set_healthyCount(int hc);
        // get y set de numero de personas infected/infectadas
        int get_infectedCount();
        void set_infectedCount(int ic);
        // get y set de numero de personas sick/enfermas
        int get_sickCount();
        void set_sickCount(int sc);
        // get y set de numero de personas immune/inmunes
        int get_immuneCount();
        void set_immuneCount(int ic);
        // get y set de numero de personas dead/muertas
        int get_deadCount();
        void set_deadCount(int dc);
        // get y set de numero de personas infectious
        int get_infectiousCount();
        void set_infectiousCount(int ic);
        // get y set de numero de personas visibly infectious
        int get_visiblyInfectiousCount();
        void set_visiblyInfectiousCount(int vic);
        //sobrecarga del operador <<
        friend ostream & operator << (ostream &out, const HealthStats hs);
};

#endif // HEALTHSTATS_H_INCLUDED
