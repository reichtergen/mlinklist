#ifndef MLINK_H
#define MLINK_H


#include <stdlib.h> // for malloc, free
#include <string.h> // for memcpy

typedef struct node_t {
    void          *data;
    struct node_t *next;
} node_t;

typedef struct manage {
    node_t *root, *tail;
} manage;


typedef node_t iter_t;

int append(manage * list_manager, const void* data, size_t byte_size);
int find(manage list_manager, const void* compare, size_t byte_size);

void iterate(manage *iter);

#endif