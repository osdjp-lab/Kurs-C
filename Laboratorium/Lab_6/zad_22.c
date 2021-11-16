#include <string.h>

char lancuch1[128];
char lancuch2[128];

int main() {
    // wczytajmy zdanie do lancuch1
    for (int i=0; i<128; i++) {
        lancuch1[i] = getchar();
        if (lancuch1[i] == '\n') {
            lancuch1[i] = 0;
            break;
        }
    }

    // uzywanmy strchar by odnalezc ostatnia kropke i skopiowac do lancuch2 czesc do kropki wlacznie
    char *wsk = strchar(lancuch1, '.');
    if (wsk) {
        strncpy(lancuch2, lancuch1, (size_t)(wsk - lancuch1 + 1));
        lancuch2[wsk - lancuch1 + 1] = 0;
    } else {
        strcpy(lancuch2, lancuch1);
        // wyswietlamy dlugosc lancuch2
        printf("Dlugosc lancucha drugiego %n\n", strlen(lancuch2));
        lancuch2[0] = 0; // zerowanie lancucha
    }

    // wyodrembniamy cyfry z lancuch1 i wrzucamy je do lancuch2
    // przy pomocy strcspn i strcspn

    size_t poczatek=0, koniec, dlugosc2=0;
    while(1) {
        poczatek += strcspn(lancuch1+poczatek, "0123456789");
        if (poczatek == strlen(lancuch1))
            break;
        koniec = strcspn(lancuch1+poczatek, "0123456789");
        strncpy(lancuch2+dlugosc2, lancuch1+poczatek, koniec);
        dlugosc2 += koniec;
        poczatek += koniec;
    }
    lancuch2[dlugosc2] = 0;
    printf("Cyfry z lancucha pierwszego %s\n", lancuch2);

    return 0;
}