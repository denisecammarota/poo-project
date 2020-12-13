#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Country.h"
#include "HealthState.h"
#include "Healthy.h"

class Country; //forward declaration de la clase country
class HealthState; //forward declaration de la clase HealthState
//CLASE HUMAN/HUMANOS
class Human{
    private:
        //atributos de una persona
        static int total_humans; //cantidad de personas creadas
        int id_persona; //id de la persona
        int days_until_move; //dias que faltan hasta ver si se muda a otro pais
        HealthState * health; //estado de salud
        Country * country; //pais donde esta la persona
    public:
        Human(Country * c); //constructor, asigna pais al que pertenece la persona
        ~Human(); //destructor
        int get_id(); //devuelve id de una persona determinada
        void Gen_MoveDays(); //genera dias que le faltan hasta ver si se mueve a otro pais
        //
        void Become_Healthy(); //hace que una persona este healthy/sana
        void Become_Infected(); //hace que una persona este infected/infectada
        void Become_Sick(); //hace que una persona este sick/enferma
        void Become_Dead(); //hace que una persona este dead/muerta
        void Become_Immune(); //hace que una persona este immune/inmune
        //
        bool isHealthy(); //devuelve true si una persona esta sana/healthy y false en caso constrario
        bool isInfected(); //idem anterior pero con infected/infectado
        bool isSick(); //idem anterior pero con sick/enfermo
        bool isImmune(); //idem anterior pero con immune/inmune
        bool isDead(); //idem anterior pero con dead/muerto
        //
        bool isInfectious(); //idem, pero para infectious (son de esta categoria sick,immune,dead e infected)
        bool isVisiblyInfectious(); //idem, pero con visibly infectious (es de esta categoria sick)
        //moving y etc
        Country * selectDestination();  //elegir el pais de destino al que se muda una persona
        void moving(Country * dest_country); //cambia el pais de una persona por el de destino en caso de que la persona se muda
        void passDay(); //pasa un dia, resta dias a days_until_move y genera days_until_move de ser necesario
        //devuelve el pais en el que esta una persona
        Country * get_country();
};





#endif // HUMAN_H_INCLUDED
