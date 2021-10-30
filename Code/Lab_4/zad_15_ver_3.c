#include <stdio.h>

void print_table(int **table, int n);

int main() {
    int n;
    printf("Podaj wartosc n kwadratu zawierajacego spirale liczb zgodnie ze wskazowkami zegara: ");
    scanf("%d", &n);
    int spirala[n][n];
    int k = 0;
    while (k <= n*n) {
        for (int j=k; j<n-k; j++) {
            // wpisujemy do tablicy[k][j]
            spirala[k][j] = k++;
        }
        print_table(spirala, n);
        if (k > n*n) {
            break;
        }
        for (int i=k+1; i<n-k; i++) {
            // wpisujemy do tablicy[i][n-1-k]
            spirala[i][n-1-k] = k++;
        }
        print_table(spirala, n);
        if (k > n*n) {
            break;
        }
        for (int j=n-2-k; j>=k; j--) {
            // wpisujemy do tablicy[n-k][j]
            spirala[n-k][j] = k++;
        }
        print_table(spirala, n);

        if (k > n*n) {
            break;
        }
        for (int i=n-2-k; i>k; i--) {
            // wpisujemy do tablicy[i][k]
            spirala[i][k] = k++;
        }
        print_table(spirala, n);
    }
    print_table(spirala, n);
    return 0;
}

void print_table(int *table, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}