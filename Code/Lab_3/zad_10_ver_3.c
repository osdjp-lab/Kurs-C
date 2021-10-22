#include <stdio.h>
#include <string.h>

char zdanie[] = "Hello world this is a simple program for initial tests.\n";

// try to compress both iterators into one for loop

int main() {
    int i = 0;
    while (i<=strlen(zdanie)) {
        int j=0;
        while (j < 8) {
            printf("%c", zdanie[i]);
            j++;
            i++;
        }
        printf("\n");
    }
    return 0;
}