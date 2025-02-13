#include "simulation.h"

Simulation* Create_simulation() {
    Simulation* sim = malloc(sizeof(Simulation));
    sim->environment = Create_environment();
    sim->time = 0;
    return sim;
}

Simulation* Add_body(Simulation* sim, const char* name, double mass, double radius, Vector3_d position, Vector3_d velocity) {
    sim->environment = Add_body_fast(sim->environment, name, mass, radius, position, velocity);
    return sim;
}

Simulation* Progress_simulation(Simulation* sim, double time) {
    Progress_simulation_euler(sim->environment, time);
    sim->time += time;
    return sim;
}

Simulation* Free_simulation(Simulation* sim) {
    Free_environment(sim->environment);
    free(sim);
    return NULL;
}

char** Get_body_names(Simulation* sim) {
    char** names = malloc((sim->environment->num_bodies + 1) * sizeof(char*));
    Node* current = sim->environment->bodies;
    for (int i = 0; i < sim->environment->num_bodies; i++) {
        Body* body = (Body*)current->data;
        names[i] = body->name;
        current = current->next;
    }
    names[sim->environment->num_bodies] = NULL;
    return names;
}

Vector3_d Get_body_position(Simulation* sim, const char* name) {
    Body* body = Find_body_by_name(sim->environment, name);
    return body->trajectory.position;
}

Vector3_d Get_body_velocity(Simulation* sim, const char* name) {
    Body* body = Find_body_by_name(sim->environment, name);
    return body->trajectory.velocity;
}

double Get_time(Simulation* sim) {
    return sim->time;
}