#include "../include/headerA3.h"

void printAll (struct car * headLL)
{
    a3Car *ptr;
    int count = 1;
    char price[10];

    ptr = headLL;

    while(ptr != NULL)
    { 
        printf("Car # %d\n", count);
        printf("\t Car id: %d\n", ptr->carId);
        printf("\t Model: %s\n", ptr->model);
        printf("\t Type: %s\n", ptr->type);
        
        sprintf(price, "%.2lf", ptr->price);
        int len = strlen(price);
        int i = len - 6;
        while (i > 0)
        {
            memmove(&price[i+1], &price[i], len - i + 1);
            price[i] = ',';
            i -= 3;
        }
        printf("\t Price: CDN $%s\n", price);

        printf("\t Year of Manufacture: %d\n", ptr->year);
        ptr = ptr->nextCar;
        count++;
    }

    if(count != 1)
    {
        printf("Currently, there are %d cars.\n\n", count-1);
    }
    else
    {
        printf("No cars found.\n\n");
    }

}
