#include <stdio.h>

int main() {
    int n;
    printf("Podaj wartosc n kwadratu zawierajacego spirale liczb zgodnie ze wskazowkami zegara: ");
    scanf("%d", &n);
    int spirala[n][n];
    int k = 0;
    for (int j=k; j<n-k; j++) {
        // wpisujemy do tablicy[k][j]
        spirala[k][j] = k++;
    }
    if (k == n*n) {
        goto end;
    }
    for (int i=k+1; i<n-k; i++) {
        // wpisujemy do tablicy[i][n-1-k]
        spirala[i][n-1-k] = k++;
    }
    if (k == n*n) {
        goto end;
    }
    for (int j=n-2-k; j>=k; j--) {
        // wpisujemy do tablicy[n-k][j]
        spirala[n-k][j] = k++;
    }
    if (k == n*n) {
        goto end;
    }
    for (int i=n-2-k; i>k; i--) {
        // wpisujemy do tablicy[i][k]
        spirala[i][k] = k++;
    }
    if (k == n*n) {
        goto end;
    }
    end:
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", spirala[i][j]);
        }
        printf("\n");
    }
    return 0;
}