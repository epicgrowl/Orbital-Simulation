#include "utils.h"
#include <stdlib.h>
#include <math.h>

Node* createNode(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Vector3_d Vector3_d_subtract(Vector3_d a, Vector3_d b) {
    Vector3_d result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vector3_d Vector3_d_scale(Vector3_d v, double scalar) {
    Vector3_d result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

double Vector3_d_length(Vector3_d vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}
double Vector3_d_length_cb(Vector3_d vector) {
    return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z) * (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

Vector3_d Vector3_d_normalize(Vector3_d vector)
{
    double length = Vector3_d_length(vector);
    if (length == 0.0) {
        Vector3_d zero_vector = {0.0, 0.0, 0.0};
        return zero_vector;
    }
    return Vector3_d_scale(vector, 1.0 / length);
}

Vector3_d Vector3_d_add(Vector3_d a, Vector3_d b) {
    Vector3_d result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}