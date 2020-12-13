#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Country.h"
#include "Human.h"
#include "Simulator.h"
#include "Word.h"
#include "HealthState.h"


using namespace std;


//MAIN DEL PROGRAMA POR AHORA
int main()
{
    //seed para los numeros random
    srand((unsigned) time(0));
    //comienzo de la simulacion, parametros a ingresar que permito
    int rows;
    int columns;
    int peop;
    double perCent_infected;
    int days_topass;
    cout << "Beginning of the Simulation" << endl;
    cout << "The Word is an rows x columns grid with a fixed number of people, a percentage of which is infected with a disease." << endl;
    cout << "Please enter the following parameters: " << endl;
    cout << "Rows (integer number): ";
    cin >> rows;
    cout << "Columns (integer number): ";
    cin >> columns;
    cout << "Number of people (integer number): ";
    cin >> peop;
    cout << "Percentage of infected people (number between 0 and 1): ";
    cin >> perCent_infected;
    cout << "Days to pass in the simulation (integer number): ";
    cin >> days_topass;
    //creo un objeto tipo mundo
    World w(rows,columns,peop,perCent_infected);
    cout << w; //imprimo el estado inicial
    for(int i = 0;i<days_topass;i++){
        w.passDay(); //paso un dia
        cout << w; //imprimo el estado del mundo despues
    }
}
