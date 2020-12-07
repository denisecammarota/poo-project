#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "SimulatorRules.h"
#include "Human.h"
#include "HealthState.h"

//acciones
void HealthState::passDay(Human * h){};
//preguntas de tipo de estado de salud
bool HealthState::isHealthy() { return false; }
bool HealthState::isInfected() { return false; }
bool HealthState::isSick() { return false; }
bool HealthState::isImmune() { return false; }
bool HealthState::isDead() { return false; }
// preguntas de tipo tambien
bool HealthState::isInfectious() { return false; }
bool HealthState::isVisiblyInfectious() { return false; }
