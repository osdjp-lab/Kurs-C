#include <stdlib.h>
#include <stdio.h>


int main() {
    int* tab = 0;
    unsigned rozmiar;
    int x, y;
    x += y;
    printf("Adres x: %p\n", &x);
    printf("Adres y: %p\n", &y);
    printf("Podaj rozmair tablicy: ");
    scanf(" %u", &rozmiar);
    tab = (int*) malloc(rozmiar * sizeof(int));
    printf("Adres tablicy dynamicznej: %p\n", tab);
    int tab2[rozmiar];
    printf("Adres tablicy statycznej: %p\n", tab2);
    return 0;
}