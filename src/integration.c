#include "integration.h"
#include "stdio.h"
#include <stdlib.h>

int Progress_simulation_euler(Environment* environment, double time_delta) {
    int steps = (int)time_delta;
    for (int i = 0; i < steps; i++) {
        Node* current = environment->bodies;
        while (current != NULL) {
            Body* body = (Body*)current->data;
            Vector3_d acceleration = Get_acceleration_point_body(environment, body);
            body->trajectory.velocity = Vector3_d_add(body->trajectory.velocity, Vector3_d_scale(acceleration, 1.0));
            body->trajectory.position = Vector3_d_add(body->trajectory.position, Vector3_d_scale(body->trajectory.velocity, 1.0));
            current = current->next;
        }
    }
    return 0;
}

/*int Progress_simulation_RK4(Environment* environment, double time_delta) {
    return 0;
}*/

Vector3_d Get_acceleration_point_body(Environment* environment, Body* body) {
    Node* current = environment->bodies;
    Vector3_d position = body->trajectory.position;
    Vector3_d acceleration = {0.0, 0.0, 0.0};
    while (current != NULL) {
        Body* other_body = (Body*)current->data;
        if (other_body != body) {
            acceleration = Vector3_d_add(acceleration, NewtonLawGrav(position, body->mass, other_body));
        }
        current = current->next;
    }
    return acceleration;
}

Vector3_d NewtonLawGrav(Vector3_d position, double mass, Body* body) {
    Vector3_d r = Vector3_d_subtract(position, body->trajectory.position);
    double distance = Vector3_d_length(r);
    double scale = -GRAVITATIONAL_CONSTANT * body->mass / (distance * distance * distance);
    return Vector3_d_scale(r, scale);
}