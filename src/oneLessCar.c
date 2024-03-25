#include "../include/headerA3.h"

void oneLessCar (a3Car ** headLL, int whichOne)
{
    int count = 1;
    a3Car *ptr = *headLL;
    a3Car *temp = NULL;
    
    if (*headLL == NULL)
    {
        printf("List is empty. \n");
        return;
    }

    if(countCars(*headLL) == 1)
    {
        free(*headLL);
        *headLL = NULL;
        return;
    }


    while(ptr != NULL && count != whichOne)
    { 
        temp = ptr;
        ptr = ptr->nextCar;
        count++;
    }

    temp->nextCar = ptr->nextCar;
    
    free(ptr);
}
