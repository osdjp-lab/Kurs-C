#include <stdio.h>
#include <string.h>

char zdanie[] = "Hello world this is a simple program for initial tests.\n";

int main() {
    for (int i=0; i<=strlen(zdanie); ) {
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