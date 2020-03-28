#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int indexNumbers = 0;
double numbers[100];

int length(double *array) {
    return (sizeof(array)/sizeof(double));
}

void copy(char *buffer) {
    char num[32];
    for(int i = 0; buffer[i] != '\0'; i++) {
        num[i] = buffer[i];
    }
    numbers[indexNumbers] = atof(num);
    indexNumbers++;
}

void read_numbers(char *input) {
    bool haveSpace = false;
    char buffer[32] = {'\0'};
    int index = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            buffer[index+1] = '\0';
            buffer[index] = input[i];
            
            if (i == (strlen(input) - 1)) {
                copy(buffer);
                buffer[0] = '\0';
                index = 0;
                haveSpace = false;
            } else {
                index++;
            }
        } else if ((input[i] == 32 && index > 0) || i == (strlen(input) - 1)) {
            copy(buffer);
            buffer[index] = '\0';
            index = 0;
            haveSpace = false;
        }
    }
    
}



int main() {
    char *input;
    double result = 0.0;

    printf("Insira sua expressão: \n");
    scanf("%[^\n]", input);

    read_numbers(input);

    if (indexNumbers > 0) {
        printf("Numbers: [");
        for(int i = 0; i < indexNumbers; i++) {
            if (i < (indexNumbers - 1)) {
                printf("%lf; ", numbers[i]);
            } else {
                printf("%lf", numbers[i]);
            }
            result += numbers[i];
        }
        printf("]\n");
    }

    return 0;
}
