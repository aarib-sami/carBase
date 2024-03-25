#include "../include/headerA3.h"

int main()
{
   int choice; 
   int input;
   char stringInput[100];
   a3Car *headLL = NULL;
   do
    {
      printf("Enter a choice:\n");
      printf("1. Add data on a new car\n2. Load data on cars from a given text file\n3. Print data of all cars\n4. Print data of the nth car\n5. Search car data based on carId\n6. Search car data based on model and type\n7. Count the total number of cars in the list\n8. Sort the cars in the list based on carId\n9. Remove data of the nth car\n10. Remove all car data\n11. Exit\n\n");
      printf("Choose menu option: ");
      scanf("%d", &choice);
      printf("\n");

      switch (choice)
      {
      case 1:
         addNewCar(&headLL);
         break;
      case 2:
         char fileName[25] = "inputFile.txt";
         loadCarData(&headLL, fileName);
         break;
      case 3:
         printAll(headLL);
         break;
      case 4:
         do
         {
            printf("Enter a position: ");
            scanf("%d", &input);
         }while (input > countCars(headLL) || input < 1);
         printOne(headLL, input);   
         break;
      case 5:
         printf("Enter a car ID: \n");
         scanf("%d", &input);
         input = lookForCarId(headLL, input);
         break;
      case 6:
         printf("Enter the model and type (separated by a space): ");
         getchar();
         fgets(stringInput, 100, stdin);
         input = lookForCarModelType(headLL, stringInput);
         break;
      case 7:
         input = countCars(headLL);
         printf("Total number of cars = %d\n", input);
         break;
      case 8:
         sortCarId(&headLL);
         printAll(headLL);
         break;
      case 9:
         do
         {
            printf("Currently there are %d cars\n", countCars(headLL));
            printf("Which car do you wish to remove – enter a value between 1 and %d: ", countCars(headLL));
            scanf("%d", &input);
         }while (input > countCars(headLL) || input < 1);
         oneLessCar(&headLL, input);

         printf("Car [Id: %d] removed. \n", input);
         printf("There are now %d cars remaining\n", countCars(headLL));
         break;
      case 10:
         do
         {
            printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
            scanf("%s", stringInput);
         }while (!(strcmp(stringInput, "y") == 0) && !(strcmp(stringInput, "n") == 0));
         if((strcmp(stringInput, "y") == 0))
         {
            noMoreCars(&headLL);
         }
         printf("All removed. Linked list is now empty. \n\n");
         break;
      case 11:
         printf("\nExiting\n");
         while(headLL != NULL)
         { 
            a3Car *temp = headLL;
            headLL = temp->nextCar;
            free(temp);
         }
         break;
      default: printf ("Invalid, will exit\n"); 
      }
    } while (choice != 11);
   return 0;
}
