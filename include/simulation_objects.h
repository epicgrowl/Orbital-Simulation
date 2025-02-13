#ifndef SIMULATION_OBJECTS_H
#define SIMULATION_OBJECTS_H

#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Node Body_list;

typedef struct Trajectory {
    Vector3_d position;
    Vector3_d velocity;
} Trajectory;

typedef struct Body {
    char* name;
    double mass;
    double radius;
    Trajectory trajectory;
} Body;

typedef struct Environment {
    Node* bodies;
    int num_bodies;
} Environment;

Environment* Create_environment();

Environment* Add_body_fast(Environment* environment, const char* name, double mass, double radius, Vector3_d position, Vector3_d velocity);

Body* Find_body_by_name(Environment* environment, const char* name);

Environment* Free_environment(Environment* environment);

#ifdef __cplusplus
}
#endif

#endif