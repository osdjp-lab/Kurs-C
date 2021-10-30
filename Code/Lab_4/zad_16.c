#include <stdio.h>
#include <math.h>

void sito_eratostenesa(int *table, int n);

int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf(" %d", &n);
    int table[n-3];
    for (int i=2; i<n; i++) {
        table[i] = i;
    }
    sito_eratostenesa(table, n);
    printf("Liczby pierwsze mniejsze niz %d:\n", n);
    for (int i=2; i<n; i++) {
        if (table[i] != 0) {
            printf("%d ",table[i]);
        }
    }
    printf("\n");
    return 0;
}

void sito_eratostenesa(int *table, int n) {
    for (int i=2; i<sqrt(n); i++) {
        for (int j=4; j<n; j++) {
            if (table[j] % i == 0) {
                table[j] = 0;
            }
        }
    }
}