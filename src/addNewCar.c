#include "../include/headerA3.h"

void addNewCar (struct car ** headLL)
{
    char carModel[MAX_LENGTH];
    char carType[MAX_LENGTH];
    int year;
    double price;
    int carId = 0;
    a3Car *ptr = NULL;
    
    printf("Enter the car model: ");
    scanf("%s", carModel);
    
    printf("Enter the car type: ");
    scanf("%s", carType);
    printf("\n");

    printf("Enter its year of manufacture: ");
    scanf("%d", &year);

    printf("Enter its price: ");
    scanf("%lf", &price);
    printf("\n");

    for(int i = 0; i < strlen(carModel); i++)
    {
        carId += (int)carModel[i];
    }

    carId += strlen(carType);

    ptr = *headLL;

    while(ptr!=NULL)
    {
        if(ptr->carId == carId)
        {
            carId += rand() % 1000;
            ptr = *headLL;
        }
        ptr = ptr->nextCar;
    }

    printf("Your computer generated carId is: %d \n", carId);

    a3Car *newCar = malloc(sizeof(a3Car));

    newCar->year = year;
    newCar->price = price;
    strcpy(newCar->model, carModel);
    strcpy(newCar->type, carType);
    newCar->carId = carId;

    ptr = *headLL;

    if (ptr == NULL) 
    {
        *headLL = newCar;
    }
    else 
    {
        while (ptr->nextCar != NULL) 
        {
            ptr = ptr->nextCar;
        }
        ptr->nextCar = newCar;
    }
    newCar->nextCar = NULL;

}
