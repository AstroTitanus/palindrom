#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStrLength(char slovo[]) {
    char currentChar = 'a';
    int counter = 0;
    while (currentChar != '\0') {
        currentChar = slovo[counter];
        counter++;
    }
    return counter-1;
}

char* reverseStr(char slovo[]) {
    int slovoLength = getStrLength(slovo);

    char* reversedSlovo;
    reversedSlovo = (char*) malloc((slovoLength)*sizeof(char));
    if (reversedSlovo != NULL) {
        reversedSlovo[slovoLength] = '\0';

        for (int i = 0; i < slovoLength; i++) {
            reversedSlovo[slovoLength-1-i] = slovo[i];
        }
        // printf("Reversed: %s\n", reversedSlovo);
        return reversedSlovo;
    } else {
        printf("Error: Nepodarilo sa alokovat potrebnu pamat.\n");
        return NULL;
    }

}

int main(int argc, char *argv[]) {

    if (argc > 1) {

        char* otoceneSlovo = reverseStr(argv[1]);

        if (otoceneSlovo != NULL) {
            
            if (strcmp(argv[1], otoceneSlovo) == 0) {
                printf("Slovo %s je palindrom.\n", argv[1]);
            } else {
                printf("Slovo %s nie je palindrom.\n", argv[1]);
            }

            free(otoceneSlovo);
        }
    }

    return 0;
}
