#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "simulation_objects.h"
#include "utils.h"
#include "magnitudes.h"

#ifdef __cplusplus
extern "C" {
#endif

int Progress_simulation_euler(Environment* environment, double time_delta);

int Progress_simulation_RK4(Environment* environment, double time_delta);

Vector3_d Get_acceleration(Environment* environment, Body* body);

Vector3_d Get_acceleration_point_body(Environment* environment, Body* body);

Vector3_d NewtonLawGrav(Vector3_d position, double mass, Body* body);

#ifdef __cplusplus
}
#endif

#endif