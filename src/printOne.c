#include "../include/headerA3.h"

void printOne(struct car *headLL, int whichOne) {
    a3Car *ptr;
    int count = 1;
    char price[10];

    ptr = headLL;

    while (ptr != NULL && count != whichOne) {
        ptr = ptr->nextCar;
        count++;
    }

    if (ptr != NULL) {
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
    } 
    else 
    {
        printf("No cars found\n");
    }
}
