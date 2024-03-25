#include "../include/headerA3.h"

void noMoreCars (a3Car ** headLL)
{
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


    while(*headLL != NULL)
    { 
        temp = *headLL;
        *headLL = temp->nextCar;
        free(temp);
    }
}
