#include <stdlib.h>
#include <stdio.h>

unsigned rozmiar_bufora = 0;
unsigned znakow_w_buforze = 0;
char* bufor = 0;
char znak;

int main() {
    // uzytkownik podaje zdanie
    // wczytujemy go znak po znaku (getchar)
    printf("Podaj zdanie:\n");
    do {
        znak = getchar();
        if (znak == '\n')
            znak = 0;
        // sprawdzamy czy bufor jest wystarczajaco duzy,
        // jezeli nie, realokujemy pamiec
        if (znakow_w_buforze < rozmiar_bufora) {
            bufor[znakow_w_buforze] = znak;
            znakow_w_buforze++;
        } else if (bufor) {
            char* tmp = realloc(bufor, rozmiar_bufora+16);
        } else {
            bufor = malloc(16);
            if (tmp) {
                bufor = tmp;
                rozmiar_bufora = 16;
                bufor[znakow_w_buforze] = znak;
                znakow_w_buforze++;
            } else {
                printf("Za malo pamieci!\n");
                break;
            }
        }
    } while (znak != 0);
    return 0;
}