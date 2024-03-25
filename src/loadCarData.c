#include "../include/headerA3.h"

void loadCarData(struct car **headLL, char fileName[MAX_LENGTH]) {

    char carModel[MAX_LENGTH];
    char carType[MAX_LENGTH];
    int year;
    double price;
    int carId;
    a3Car *ptr = NULL;
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return;
    }


    while ((fscanf(file, "%d,%[^,],%[^,],%d,%lf\n", &carId, carModel, carType, &year, &price) == 5)) 
    {
        ptr = *headLL;

        while (ptr != NULL) 
        {
            if (ptr->carId == carId) {
                carId += rand() % 1000;
                ptr = *headLL;
            }
            ptr = ptr->nextCar;
        }

        a3Car *newCar = malloc(sizeof(a3Car));
    
        newCar->year = year;
        newCar->price = price;
        strcpy(newCar->model, carModel);
        strcpy(newCar->type, carType);
        newCar->carId = carId;
        newCar->nextCar = NULL;

        if (*headLL == NULL) 
        {
            *headLL = newCar;
        } 
        else 
        {
            ptr = *headLL;
            while (ptr->nextCar != NULL) 
            {
                ptr = ptr->nextCar;
            }
            ptr->nextCar = newCar;
        }
    }

    fclose(file);
}
