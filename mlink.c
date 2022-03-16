#include "mlink.h"


int append(manage_t *list_manage, const void *data) {

    if ( NULL == list_manage->root ) {
        
        list_manage->root = malloc( sizeof( node_t ) );

        if ( NULL == list_manage->root )
            return -1;

        list_manage->root->data = malloc( list_manage->byte_size);

        if ( NULL == list_manage->root->data ) {

            free( list_manage->root );
            list_manage->root = NULL;
            return -1;
        }

        memcpy(list_manage->root->data, data, list_manage->byte_size);

        list_manage->root->next = NULL;
        list_manage->tail = list_manage->root;

    }else {
        node_t *temp =  malloc( sizeof(node_t) );
        if ( NULL == temp )
            return -1;

        temp->data = malloc( list_manage->byte_size);

        if ( NULL == temp->data ) {

            free( temp );
            return -1;
        }

        temp->next = NULL;
        memcpy(temp->data, data, list_manage->byte_size);

        list_manage->tail->next = temp;
        list_manage->tail = temp;

    }

    return 0;
}


int find(manage_t list_manage, const void *compare) {
    int r ;
    for(; NULL != list_manage.root; ) {
        
        r = memcmp(list_manage.root->data , compare, list_manage.byte_size);
        if(!r)
            return r;

        list_manage.root = list_manage.root->next;
    }
    return r;
}

iter_t get_iter(manage_t *list_manage) {
    iter_t iter;
    iter.root = list_manage->root;
    iter.data = list_manage->root->data;
    return iter;
}

void iterate(iter_t *iter) {
    iter->root = iter->root->next;
    if(NULL != iter->root)
        iter->data = iter->root->data;
}