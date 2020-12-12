#ifndef SIMULATORRULES_H_INCLUDED
#define SIMULATORRULES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//CLASE SIMULATOR PARAMETERS,
class SimulationParameters{
    //atributos
    private:
        //parametros como dias
        int daysMaxStay =  10; //dias maximos de estancia en un pais
        int daysMinStay = 5; //dias minimos de estacia en un pais
        int daysUntilSick = 6; //dias hasta enfermarse, una vez que una persona se infecta
        int daysUntilDeadChance = 8; //a 8 dias, puede morirse una persona con una probabilidad determinada
        int daysUntilImmune = 10; // a 10 dias, si sobrevive, una persona se vuelve inmune
        int daysUntilHealthy = 2; //dias que dura la inmunidad. luego de 2 dias, vuelve a estar sana y poder infectarse
        //probabilidades de cosas
        double probToTransmitVirus = 0.4; //probabilidad de contraer el virus
        double probToDie = 0.25; //probabilidad de morirse
        //double probToTravel = 0.4; // esto no se usa, podria usarse para el futuro para viaje a otros paises no vecinos
    //metodos
    public:
        SimulationParameters(); // constructor
        ~SimulationParameters(); // destructor
        int getMaxStayDays(); // devuelve daysMaxStay
        int getMinStayDays(); //devuelve daysMinStay
        int getUntilSickDays(); // devuelve daysUntilSick
        int getUntilDeadChanceDays(); // devuelve daysUntilDeadChance
        int getUntilImmuneDays(); // devuelve daysUntilImmune
        int getUntilHealthyDays(); // deviuelve daysUntilHealthy
        bool infectionDiceThrow(); // devuelve true o false con una probabilidad, para ver si una persona se infecta o no
        // bool travelDiceThrow(); // esto no se usa, de nuevo es para viaje a paises no vecinos
        bool dieDiceThrow(); // devuelve true o falso con una probabilidad, para ver si una persona se muere o no
};

extern SimulationParameters g_simpars; //instancia global de esta clase SimulatorRules

#endif // SIMULATORRULES_H_INCLUDED
