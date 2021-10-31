#include <stdio.h>
#include <string.h>

char zdanie[] = "Hello world this is a simple program for initial tests.\n";

int main() {
    for (int i=0; i<=strlen(zdanie); i+=8) {
        for (int j=0; j<=8; i++) {
            printf("%c", zdanie[i+j]);
        }
        printf("/n");
    }
    return 0;
}