#include <stdio.h>
#include <string.h>

int main() {
    printf("Podaj znak: ");
    char znak;
    scanf(" %c", &znak);
    printf("Podaj zdanie: ");
    char zdanie[256];
    scanf(" %[^\n]s", zdanie);
    printf("\n");
    int r_wzg = 0;
    int r_bwzg = 0;
    char shift;
    if (('A' <= znak) && (znak <= 'Z')) {
        shift = 'a'-'A';
    } else {
        shift = 'A'-'a';
    }
    for (int i=0; i<strlen(zdanie); i++) {
        if (zdanie[i] == znak) {
            r_wzg += 1;
            r_bwzg += 1;
        } else {
            if (zdanie[i] == znak+shift) {
                r_bwzg += 1;
            }
        }
    }
    printf("Wzgledna liczba wystapien litery: %d\n", r_wzg);
    printf("Bezwzgledna liczba wystapien litery: %d\n", r_bwzg);
    return 0;
}