#include "simulation_objects.h"
#include <stdlib.h>
#include <string.h>

Environment* Create_environment() {
    Environment* environment = (Environment*)malloc(sizeof(Environment));
    environment->num_bodies = 0;
    environment->bodies = NULL;
    return environment;
}

Environment* Add_body_fast(Environment* environment, const char* name, double mass, double radius, Vector3_d position, Vector3_d velocity) {
    Body* new_body = (Body*)malloc(sizeof(Body));
    new_body->name = strdup(name);
    new_body->mass = mass;
    new_body->radius = radius;
    new_body->trajectory.position = position;
    new_body->trajectory.velocity = velocity;

    Node* new_node = createNode(new_body);
    if (environment->bodies == NULL) {
        environment->bodies = new_node;
    } else {
        Node* current = environment->bodies;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }

    environment->num_bodies++;
    return environment;
}

Body* Find_body_by_name(Environment* environment, const char* name) {
    Node* current = environment->bodies;
    while (current != NULL) {
        Body* body = (Body*)current->data;
        if (strcmp(body->name, name) == 0) {
            return body;
        }
        current = current->next;
    }
    return NULL;
}

Environment* Free_environment(Environment* environment) {
    Node* current = environment->bodies;
    while (current != NULL) {
        Node* next = current->next;
        Body* body = (Body*)current->data;
        free(body->name);
        free(body);
        free(current);
        current = next;
    }
    free(environment);
    return NULL;
}