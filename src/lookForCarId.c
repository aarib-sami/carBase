#include "../include/headerA3.h"

int lookForCarId (struct car * headLL, int key)
{
    if (headLL == NULL)
    {
        printf("List is empty. \n");
        return -1;
    }
    
    a3Car *ptr;
    int count = 1;

    ptr = headLL;

    while(ptr != NULL)
    { 
        if(ptr->carId == key)
        {
            printOne(headLL, count);
            return count;
        }
        else
        {
            ptr = ptr->nextCar;
        count++;
        }
    }

    printf("None found. \n");
    return -1;
    
}
