#include <iostream>

using namespace std;

//CLASE SIMULATOR PARAMETERS
class SimulationParameters{
    //atributos
    private:
        //parametros como dias
        int daysMaxStay =  10;
        int daysMinStay = 5;
        int daysUntilSick = 6;
        int daysUntilDeadChance = 8;
        int daysUntilHealthy = 2;
        //probabilidades de cosas
        double probToTransmitVirus = 0.4;
        double probToDie = 0.25;
        double probToTravel = 0.4;

    //metodos
    public:
        SimulationParameters(){};
        ~SimulationParameters(){};
        int getMaxStayDays(){return daysMaxStay;}
        int getMinStayDays(){return daysMinStay;}
        int getUntilSickDays(){return daysUntilSick;}
        int getUntilHealthyDays(){return daysUntilHealthy;}
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
