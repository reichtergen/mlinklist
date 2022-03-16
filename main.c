#include <stdio.h>
#include "mlink.h"


int main( void ) {

    

    manage int_list = {.root = NULL, .tail = NULL};

    int number = 25;

    append(&int_list, &number, sizeof(int)); 
    number = 36;
    append(&int_list, &number, sizeof(int)); 
    number = 21;
    append(&int_list, &number, sizeof(int)); 
    number = 24;
    append(&int_list, &number, sizeof(int)); 
    number = 77;
    append(&int_list, &number, sizeof(int)); 


    
    for( manage iter = int_list; iter.root != NULL; iterate(&iter)) {
        
        printf("int: %d\n", *(int*)iter.root->data );
      
    }

    return 0;
}