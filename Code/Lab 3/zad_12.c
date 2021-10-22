#include <stdio.h>

int funkcja_kwadratowa(int x);

int main() {
    printf("Parameter : Value\n");
    for (int i=1; i<11; i++) {
        printf("%-9d : %5d\n", i, funkcja_kwadratowa(i));
    }
    return 0;
}

int funkcja_kwadratowa(int x){
    return 2*x*x - 30*x + 10;
}