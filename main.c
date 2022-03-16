#include <stdio.h>
#include "mlink.h"


/*
* Wrapper function for int
*/
int int_append(manage_t *m, int number)
{
    return append(m, &number); 
}

/*
* Wrapper function for double
*/
int double_append(manage_t *m, double number)
{
    return append(m, &number); 
}


int main( void ) {

    
/*
    * Example int
    */
    
    manage_t int_list = {.root = NULL, .tail = NULL, .byte_size = sizeof(int) };

    int number = 25;

    append(&int_list, &number); 
    number = 64;
    append(&int_list, &number);

  
    int_append(&int_list, 25);
    int_append(&int_list, 37);
    int_append(&int_list, 47);

    
    for( iter_t iter = get_iter(&int_list); NULL != iter.root; iterate(&iter)) {
   
        printf("int: %d\n", *(int*)iter.data);
        
    }

/*
    * Example double
    */

    manage_t double_list = {.root = NULL, .tail = NULL, .byte_size = sizeof(double) };

    double number2 = 14.29349;

    append(&double_list, &number2); 
    number2 = 32.123;
    append(&double_list, &number2);

    double_append(&double_list, 45.2344);
    double_append(&double_list, 98.6788);


    for( iter_t iter = get_iter(&double_list); NULL != iter.root; iterate(&iter)) {
        
        printf("double: %f\n", *(double*)iter.data);
      
    }


    return 0;
}