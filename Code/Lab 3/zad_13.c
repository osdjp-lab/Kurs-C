#include <stdio.h>

int main() {
    printf("Wybierz dzialanie [1(+), 2(-), 3(*), 4(/)]: ");
    int select;
    scanf(" %d", &select);
    printf("Podaj pierwsza wartosc: ");
    int a, b;
    scanf(" %d", &a);
    printf("Podaj druga wartosc: ");
    scanf(" %d", &b);
    switch (select) {
        case 1:
            printf("Wynik dzialania: %d", a+b);
            break;
        case 2:
            printf("Wynik dzialania: %d", a-b);
            break;
        case 3:
            printf("Wynik dzialania: %d", a*b);
            break;
        case 4:
            printf("Wynik dzialania: %d", a/b);
            break;
        default:
            printf("Failure.\n");
    }
    return 0;
}