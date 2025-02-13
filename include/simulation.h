#ifndef SIMULATION_H
#define SIMULATION_H

#include "simulation_objects.h"
#include "integration.h"
#include "magnitudes.h"
#include "utils.h"
#include <stdlib.h>

typedef struct Simulation {
    Environment *environment;
    double time;
} Simulation;

#ifdef __cplusplus
extern "C" {
#endif

Simulation* Create_simulation(void);

Simulation* Add_body(Simulation* sim, const char* name, double mass, double radius, Vector3_d position, Vector3_d velocity);

Simulation* Progress_simulation(Simulation* sim, double time);

Simulation* Free_simulation(Simulation* sim);

char** Get_body_names(Simulation* sim);

Vector3_d Get_body_position(Simulation* sim, const char* name);

Vector3_d Get_body_velocity(Simulation* sim, const char* name);

double Get_time(Simulation* sim);

#ifdef __cplusplus
}
#endif

#endif