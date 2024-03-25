#include "../include/headerA3.h"

int lookForCarModelType (struct car * headLL, char key [100])
{
    a3Car *ptr;
    int count = 1;
    char model[MAX_LENGTH];
    char type[MAX_LENGTH];
    
    if (headLL == NULL)
    {
        printf("List is empty. \n");
        return -1;
    }

    sscanf(key, "%s %s", model, type);

    ptr = headLL;

    while(ptr != NULL)
    { 
        if((strcmp(ptr->model, model) == 0) && (strcmp(ptr->type, type) == 0))
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
