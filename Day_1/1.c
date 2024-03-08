#include <stdio.h>

struct Date
{
    int dd;
    int mm;
    int yy;
};
void initDate(struct Date* ptr)
{
    *ptr = (struct Date) {.dd = 05, .mm = 3, .yy = 2024};
}

void printDateOnConsole(struct Date* ptr)
{
    printf("Day:%d ", ptr->dd);
    printf("Month:%d ", ptr->mm);
    printf("Year:%d ", ptr->yy);
}

void acceptDateFromConsole(struct Date* ptr)
{
    printf("Enter day: ");
    scanf("%d", &ptr->dd);
    printf("Enter month: ");
    scanf("%d", &ptr->mm);
    printf("Enter year: ");
    scanf("%d", &ptr->yy);
}

int main(void)
{
    struct Date d1;
    int choice;
    do{
        
        printf("\nEnter choice: 0. Exit\n1. Initialize date\n2. Print date\n3. Accept date:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
            printf("Exiting program!");
            break;
        
            case 1:
               initDate(&d1);
               break;

            case 2:
                printDateOnConsole(&d1);
                break;

            case 3:
               acceptDateFromConsole(&d1); 
               break;

            default:
                printf("Invalid choice!!");
                break;

        }
            


    }while(choice != 0);

}
