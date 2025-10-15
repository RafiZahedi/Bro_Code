#include <stdio.h>
#include <string.h>

void remove_newline(char *str){
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n'){
        str[len - 1] = '\0';
    }
}

int main(){
    char adjectvies[3][50];
    printf("Enter an ajective (description): ");
    fgets(adjectvies[0], sizeof(adjectvies[0]), stdin);
    remove_newline(adjectvies[0]);

    char noun[50];
    printf("\nEnter a noun (animal or a person): ");
    fgets(noun, sizeof(noun), stdin);
    remove_newline(noun);

    printf("\nEnter an ajective (description): ");
    fgets(adjectvies[1], sizeof(adjectvies[1]), stdin);
    remove_newline(adjectvies[1]);

    char verb[50];
    printf("\nEnter a verb (ending w/ -ing): ");
    fgets(verb, sizeof(verb), stdin);
    remove_newline(verb);
     char adjective_3[50];
    printf("\nEnter an ajective (description): ");
    fgets(adjectvies[2], sizeof(adjectvies[2]), stdin);
    remove_newline(adjectvies[2]);

    printf("-------------------\n");
    printf("Today I went to a %s zoo.\n", adjectvies[0]);
    printf("In an axhibit, I saw a %s.\n", noun);
    printf("%s was %s and %s.\n", noun, verb, adjectvies[1]);
    printf("I was %s.", adjectvies[2]);


    return 0;
}