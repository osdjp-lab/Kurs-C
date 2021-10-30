#include <stdio.h>

/*
Generuje kwadrat zawierajacy liczby wypełniające pola kwadratu
zgodnie ze wskazowkami zegara.
*/


int main() {
    int n;
    printf("Podaj dlugosc boku kwadratu: ");
    scanf("%d", &n);
    int spiral[n][n];
    int startx = 0;
    int endx = n-1;
    int starty = 0;
    int endy = n-1;
    int *circular_list[] = {&startx, &endx, &starty, &endy};
    int a = 0;
    while ((startx != endx) && (starty != endy)) {
        for (int i=startx; i<=endx; i++) {
            for (int j=starty; j<=endy; j++) {
                spiral[i][j] = a++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", spiral[i][j]);
        }
        printf("\n");
    }
    return 0;
}