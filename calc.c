#include <stdio.h>
#include <string.h>
#include <ctype.h> // Required for isdigit()
#include <stdlib.h> // For atoi()

void remove_newline(char *str){
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n'){
        str[len - 1] = '\0';
    }
}


void math(int opr){

    // add 
    if(opr == 1){
        // printf("Add has been selected!\n");

        // int a;
        // printf("Enter the fisrt number: \n");
        // scanf("%d", &a);
        
        // int b;
        // printf("Enter the second number: \n");
        // scanf("%d", &b);

        // printf("The result: %d", (a+b) );

        printf("Enter your number in this format: a + b + c + ... then hit enter max 50 chars\n");

        char numbers[50]; 

        fgets(numbers, 50, stdin);
        remove_newline(numbers);

        long total = 0;
        for(int i = 0; i < strlen(numbers) ; i++){
            char digits[50];
            if(isdigit(numbers[i])){
                
                int j = i + 1;
                // we go forward to get all the digits of the number
                while (!isspace(numbers[j])){
                    digits[i] = numbers[j];
                    j ++;
                }
            
            // convert the string to int.
            total += atoi(digits[j - i]);
            
            }
        }

    }

    // subtract
     if(opr == 2){
        printf("Subtract has been selected!\n");

        int a;
        printf("Enter the fisrt number: \n");
        scanf("%d", &a);
        
        int b;
        printf("Enter the second number: \n");
        scanf("%d", &b);

        printf("The result: %d", (a-b) );
    }


    // multiply
    if(opr == 3){
        printf("Multiply has been selected!\n");

        int a;
        printf("Enter the fisrt number: \n");
        scanf("%d", &a);
        
        int b;
        printf("Enter the second number: \n");
        scanf("%d", &b);

        printf("The result: %d", (a*b) );
    }

    // divide
     if(opr == 4){
        printf("Divide has been selected!\n");

        int a;
        printf("Enter the fisrt number: \n");
        scanf("%d", &a);
        
        int b;
        printf("Enter the second number: \n");
        scanf("%d", &b);
        while(b == 0){
            printf("Second number can't be zero! What the hell?? \n");
            scanf("%d", &b);
        }

        printf("The result: %d", (a+b) );
    }
}

int main(){
    printf("************ The Calculator ************\n");

    printf("Select You Operation\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");

    // getting the operation
    int operation;
    scanf("%d", &operation);

    math(operation);
    
    return 0;
}