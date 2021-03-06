#include <stdio.h>
#include "mlink.h"


/*
* Wrapper function for int
*/
int int_append(mlink_t *m, int number)
{
    return append(m, &number); 
}

/*
* Wrapper function for double
*/
int double_append(mlink_t *m, double number)
{
    return append(m, &number); 
}


int main( void ) {

    
/*
    * Example int
    */
    
    mlink_t int_list = {.root = NULL, .tail = NULL, .byte_size = sizeof(int) };

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

    mlink_t double_list = {.root = NULL, .tail = NULL, .byte_size = sizeof(double) };

    double number2 = 14.29349;

    append(&double_list, &number2); 
    number2 = 32.123;
    append(&double_list, &number2);

    double_append(&double_list, 45.2344);
    double_append(&double_list, 98.6788);


    for( iter_t iter = get_iter(&double_list); NULL != iter.root; iterate(&iter)) {
        
        printf("double: %f\n", *(double*)iter.data);
      
    }

    mlink_t string_list = {.root = NULL, .tail = NULL, sizeof(char)*50};

    append(&string_list, "This is test message!");
    append(&string_list, "Can you read me?");
    append(&string_list, "Write a dolor lorem ipsum.");


    for( iter_t iter = get_iter(&string_list); NULL != iter.root; iterate(&iter)) {
        
        printf("char array: %s\n", (char*)iter.data);
      
    }

    delete_list(&int_list);
    delete_list(&double_list);
    delete_list(&string_list);

    return 0;
}