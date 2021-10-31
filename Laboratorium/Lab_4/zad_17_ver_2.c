#include <stdio.h>

int main() {
    char znaki[256];
    for (int i=0; i<256; i++) {
        znaki[i] = 0;
    }
    printf("Podaj ciag znakow: ");
    int a;
    do {
        a = getchar();
        if (a > 0) {
            znaki[a]++;
        } else {
            znaki[a+256] += 1;
        }
    } while (a != '\n');
    for (int i=0; i<256; i++) {
        if (znaki[i] != 0) {
            printf("%c_%d\n", i, znaki[i]);
        }
    }
}