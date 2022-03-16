#include "mlink.h"


int append(manage *list_manager, const void *data, size_t byte_size) {

    if ( NULL == list_manager->root ) {
        
        list_manager->root = malloc( sizeof( node_t ) );

        if ( NULL == list_manager->root )
            return -1;

        list_manager->root->data = malloc( byte_size);

        if ( NULL == list_manager->root->data ) {

            free( list_manager->root );
            list_manager->root = NULL;
            return -1;
        }

        memcpy(list_manager->root->data, data, byte_size);

        list_manager->root->next = NULL;
        list_manager->tail = list_manager->root;

    }else {
        node_t *temp =  malloc( sizeof(node_t) );
        if ( NULL == temp )
            return -1;

        temp->data = malloc( byte_size);

        if ( NULL == temp->data ) {

            free( temp );
            return -1;
        }

        temp->next = NULL;
        memcpy(temp->data, data, byte_size);

        list_manager->tail->next = temp;
        list_manager->tail = temp;

    }

    return 0;
}


int find(manage list_manager, const void *compare, size_t byte_size) {
    int r ;
    for(;list_manager.root != NULL;) {
        
        r = memcmp(list_manager.root->data , compare, byte_size);
        if(!r){
            return r;
        }
        list_manager.root = list_manager.root->next;
    }
    return r;
}


void iterate(manage *iter) {
    iter->root = iter->root->next;
}