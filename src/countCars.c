#include "../include/headerA3.h"

int countCars (a3Car * headLL)
{
    a3Car *ptr;
    int count = 0;

    ptr = headLL;

    while(ptr != NULL)
    { 
        ptr = ptr->nextCar;
        count++;
    }

    return count;
}
