#include <stdio.h>

int main() {
    printf("Podaj lancuch znakow:\n");
    int i = 0;
    while(getchar() != '\n') {
        i++;
    }
    printf("Podano %u znakow", i);
    return 0;
}