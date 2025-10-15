#include <stdio.h>
#include <string.h>

int main(){
    char item_name[50];
    float price;
    int quantity;

    printf("Item name: ");
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strlen(item_name) - 1] = '\0';

    printf("Price for each: ");
    scanf("%f", &price);

    printf("How many of those: ");
    scanf("%d", &quantity);

    printf("----------------------------\n");
    printf("You have bought %d %s's, %.3f each.\n", quantity, item_name ,price);
    printf("Your total is %.2f", quantity * price);
    
}