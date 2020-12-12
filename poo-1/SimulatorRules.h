#ifndef SIMULATORRULES_H_INCLUDED
#define SIMULATORRULES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//NAMESPACE SIMULATOR PARAMETERS
class SimulationParameters{
    //atributos
    private:
        //parametros como dias
        int daysMaxStay =  10;
        int daysMinStay = 5;
        int daysUntilSick = 6;
        int daysUntilDeadChance = 8;
        int daysUntilImmune = 10;
        int daysUntilHealthy = 2;
        //probabilidades de cosas
        double probToTransmitVirus = 0.4;
        double probToDie = 0.25;
        double probToTravel = 0.4;
    //metodos
    public:
        SimulationParameters();
        ~SimulationParameters();
        int getMaxStayDays();
        int getMinStayDays();
        int getUntilSickDays();
        int getUntilDeadChanceDays();
        int getUntilImmuneDays();
        int getUntilHealthyDays();
        bool infectionDiceThrow();
        bool travelDiceThrow();
        bool dieDiceThrow();
};

extern SimulationParameters g_simpars;

#endif // SIMULATORRULES_H_INCLUDED
