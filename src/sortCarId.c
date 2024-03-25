#include "../include/headerA3.h"

void sortCarId(a3Car **headLL) {
    int length;
    a3Car *temp = NULL;
    a3Car *prev = NULL;
    a3Car *ptr = NULL;

    if (*headLL == NULL) {
        printf("List is empty. \n");
        return;
    }

    length = countCars(*headLL);

    if (length == 1) {
        printf("Ordered. \n");
        return;
    }


    for (int i = 0; i < length - 1; i++) 
    {
        ptr = *headLL;
        for (int j = 0; j < length - i - 1; j++) 
        {
            if (ptr->carId > ptr->nextCar->carId) 
            {
                temp = ptr->nextCar;
                ptr->nextCar = temp->nextCar;
                temp->nextCar = ptr;
                if (ptr == *headLL) 
                {
                    *headLL = temp;
                } 
                else 
                {
                    prev->nextCar = temp;
                }
                ptr = temp;
            }
            prev = ptr;
            ptr = ptr->nextCar;
        }
    }
}
