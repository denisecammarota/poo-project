#ifndef HEALTHSTATS_H_INCLUDED
#define HEALTHSTATS_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

class HealthStats{
    //estadisticas
    int healthy;
    int infected;
    int sick;
    int immune;
    int dead;
    int infectious;
    int visiblyInfectious;
    public:
        //
        int get_healthyCount();
        void set_healthyCount(int hc);
        //
        int get_infectedCount();
        void set_infectedCount(int ic);
        //
        int get_sickCount();
        void set_sickCount(int sc);
        //
        int get_immuneCount();
        void set_immuneCount(int ic);
        //
        int get_deadCount();
        void set_deadCount(int dc);
        //
        int get_infectiousCount();
        void set_infectiousCount(int ic);
        //
        int get_visiblyInfectiousCount();
        void set_visiblyInfectiousCount(int vic);
        //
        void add(HealthStats other);
        void print();
};

#endif // HEALTHSTATS_H_INCLUDED
