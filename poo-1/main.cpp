#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//clases declaradas al comienzo porque despues las necesito
class Country; //solo la declaracion
class SimulationParameters; //solo la declaracion

//CLASE HEALTHSTATE DE UNA PERSONA + HEREDADAS
class HealthState{
    public:
        //acciones
        void passDay(Human * h){};
        bool getInfected(bool infectious) {return false;} //si se va a infectar o no
        //preguntas de tipo de estado de salud
        bool isHealthy() { return false; }
        bool isInfected() { return false; }
        bool isSick() { return false; }
        bool isImmune() { return false; }
        bool isDead() { return false; }
        // preguntas de tipo tambien
        bool isInfectious() { return false; }
        bool isVisiblyInfectious() { return false; }
};


class Healthy:public HealthState{ //a completar
    public:
        bool isHealthy() { return true; }
        bool getInfected(bool infectious,Human * h) {return false;h->Become_Infected();} //volver a escribir cuando esten las reglas y etc
};

class Infected:public HealthState{ //a completar
    int days_infected = 0;
    SimulationParameters sim_pars;
    public:
        bool isInfected() { return true; }
        bool isInfectious()  {return true;}
        void passDay(Human * h) {
            days_infected++;
            if(days_infected == sim_pars.getUntilSickDays()){
                h->Become_Sick();
            }
        };
}; //completar con definicion

class Sick:public HealthState{ //a completar
    int days_sick = 0;
    SimulationParameters sim_pars;
    public:
        bool isSick(){return true;}
        bool isInfectious(){return true;}
        bool isVisiblyInfectious() {return true;}
        void passDay(Human * h){
            days_sick++;
            //completar aca
        }
}; //completar con definicion

class Immune:public HealthState{ //esta listo
    int days_immune = 0;
    SimulationParameters sim_pars;
    public:
        bool isImmune() { return true; }
        bool isInfectious() {return true;}
        void passDay(Human * h) {
            days_immune++;
            if(days_immune == sim_pars.getUntilHealthyDays){
                h->Become_Healthy();
            }
        }
}; //completar con definicion

class Dead:public HealthState{ //creo que esta completo
    public:
        bool isDead(){return true;}
        bool isInfectious(){return true;}
        bool isVisiblyInfectious(){return true;}
}; //completar con definicion

//CLASE SIMULATOR
class Simulator{
    //atributos
    vector<Country*> list_countries;
    int days_passed;
    int rows;
    int columns;
    //metodos
    public:
        Simulator(int r,int c){
            //asignamos filas y columnas
            rows = r;
            columns = c;
            days_passed = 0;
        };
        void populate(int peop,double pcinf){};
        ~Simulator(){}; //completar
        void passDay(){};
        int getDaysPassed(){return days_passed + 1;}
};


//CLASE SIMULATOR PARAMETERS
class SimulationParameters{
    //atributos
    private:
        int maxStayDays =  10;
        int minStayDays = 5;
        int daysUntilSick = 6;
        int daysUntilHealthy = 2;
    //metodos
    public:
        SimulationParameters(){};
        ~SimulationParameters(){};
        int getMaxStayDays(){return maxStayDays;}
        int getMinStayDays(){return minStayDays;}
        int getUntilSickDays(){return daysUntilSick;}
        int getUntilHealthyDays(){return daysUntilHealthy;}
};

//CLASE WORD/MUNDO
class Word{
    private:
        Simulator * simulator;
        SimulationParameters sim_pars;
    public:
        Word(int rows,int columns,int people,double perCent_infected){
            sim_pars = SimulationParameters();
            simulator = new Simulator(rows,columns);
            simulator->populate(people,perCent_infected);
        }
        ~Word(){delete simulator; simulator = nullptr;}
        void passDay(){simulator->passDay();}
};

//CLASE COUNTRY/PAISES
class Country{
    //atributos
    private:
        static int total_countries;
        int id_country;
        string country_name;
        vector <Country*> country_neighbours; //paises vecinos
        vector <Human*> country_people; //personas en el paises
        vector <Human*> country_arrivals; //personas que entran en el pais
    //metodos
    public:
        Country(string s){country_name = s;id_country = total_countries;total_countries++;};
        ~Country(){}
        void addHuman(Human * h){};
        int get_id(){return id_country;}
        string get_name(){return country_name;}
        friend ostream& operator<<(ostream& os, const Country& c);
};

int Country::total_countries= 0;

ostream& operator<<(ostream& os, const Country& c){return os;}; //completar

//CLASE HUMANOS
class Human{
    private:
        //atributos de una persona
        static int total_humans; //cantidad de personas creadas
        int id_persona; //id de la persona
        int days_until_move; //dias que faltan hasta movimiento
        HealthState * health; //estado de salud
        Country * country; //pais donde esta la persona
        SimulationParameters sim_pars;
    public:
        Human(Country * c){
            id_persona = total_humans; //asigna id de la persona
            country = c; //asignar pais
            c->addHuman(this); //aniadir persona a pais, completar
            Become_Healthy(); //asigna estado de salud = sano, completar
            Gen_MoveDays(); //asigna dias hasta el proximo movimiento, completar
            total_humans++; //fin de creacion +1 persona
        }
        ~Human(){delete country;country = nullptr;}
        int get_id(){return id_persona;} //devuelve id de persona
        void Gen_MoveDays(){ //genera cantidad de dias hasta moverse
            int maximum = sim_pars.getMaxStayDays();
            int minimum = sim_pars.getMinStayDays();
            days_until_move = (rand()%(maximum-minimum+1))+minimum;
        }
        void Become_Healthy(){ //asigna estado sano a una persona

        }
        void Become_Infected(){

        }
        void Become_Sick(){

        }
        friend ostream& operator<<(ostream& os, const Human& h);

};

ostream& operator<<(ostream& os, const Human& h)
{
    os << "Humano con indice: " << h.id_persona << " en el pais: " << h.country->get_id();
    return os;
}


int Human::total_humans = 0;




//MAIN DEL PROGRAMA POR AHORA
int main()
{
    srand((unsigned) time(0));
}
