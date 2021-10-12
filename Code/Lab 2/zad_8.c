#include <stdio.h>

int main() {
    int n;
    printf("Podaj wielkosc choinki: ");
    scanf(" %u", n);
    printf("\n");
    int max_width = n + 1;  // 2*n + 3
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n+1; j++) {
            for (int k=0; k<=j; k=2*j+1) {
                for (int l=1; l<=max_width-j; l++) {
                    printf(" ");
                }
                for (int l=1; l<=k; l++) {
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}