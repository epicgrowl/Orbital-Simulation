#include <stdio.h>
#include "simulation.h"

/* TEMPLATE EXAMPLE FILE */

int main() {
    // Create simulation
    Simulation* sim = Create_simulation();

    // Add bodies
    Add_body(sim, "Earth", EARTH_MASS, EARTH_RADIUS, (Vector3_d){0, 0, 0}, (Vector3_d){0, 0, 0});
    Add_body(sim, "Moon", MOON_MASS, MOON_RADIUS, (Vector3_d){0, 384400000, 0}, (Vector3_d){1022, 0, 0});

    // Output initial positions
    printf("Earth position: (%f, %f, %f)\n", Get_body_position(sim, "Earth").x, Get_body_position(sim, "Earth").y, Get_body_position(sim, "Earth").z);
    printf("Moon position: (%f, %f, %f)\n", Get_body_position(sim, "Moon").x, Get_body_position(sim, "Moon").y, Get_body_position(sim, "Moon").z);

    // Simulate for 100 seconds
    Progress_simulation(sim, 100);

    // Output results
    printf("Earth position: (%f, %f, %f)\n", Get_body_position(sim, "Earth").x, Get_body_position(sim, "Earth").y, Get_body_position(sim, "Earth").z);
    printf("Moon position: (%f, %f, %f)\n", Get_body_position(sim, "Moon").x, Get_body_position(sim, "Moon").y, Get_body_position(sim, "Moon").z);

    // Free simulation
    Free_simulation(sim);

    return 0;
}