#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Node{
    void* data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(void* data);

typedef struct Vector3_d{
    double x;
    double y;
    double z;
} Vector3_d;

Vector3_d Vector3_d_add(struct Vector3_d a, struct Vector3_d b);

Vector3_d Vector3_d_subtract(struct Vector3_d a, struct Vector3_d b);

Vector3_d Vector3_d_scale(struct Vector3_d v, double scalar);

Vector3_d Vector3_d_normalize(struct Vector3_d vector);

double Vector3_d_length(Vector3_d vector);

double Vector3_d_length_cb(Vector3_d vector);

#ifdef __cplusplus
}
#endif

#endif