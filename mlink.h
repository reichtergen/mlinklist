#ifndef MLINK_H
#define MLINK_H


#include <stdlib.h> // for malloc, free
#include <string.h> // for memcpy

typedef struct node_t {
    void          *data;
    struct node_t *next;
} node_t;

typedef struct manage_t {
    node_t *root, *tail;
    size_t byte_size;
} manage_t;

typedef struct iter_t {
    node_t *root;
    void   *data;
} iter_t;


int append(manage_t * list_manage, const void* data);
int find(manage_t list_manage, const void* compare);

iter_t get_iter(manage_t *list_manage);
void iterate(iter_t *iter);

#endif