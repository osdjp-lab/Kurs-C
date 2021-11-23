#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float* fill_tab(float *tab, int tab_size);

void print_tab(float *tab, int tab_size);

int zliczenie(float *tab, int tab_size, float liczba);

float* najblizsza(float *tab, int tab_size, float liczba);

int main() {
    printf("Podaj wielkosc tablicy: ");
    int tab_size;
    scanf(" %d", &tab_size);
    float *tab = (float*) malloc(tab_size*sizeof(float));
    if (tab != 0) {
        fill_tab(tab, tab_size);
        printf("Wygenerowana tablica: ");
        print_tab(tab, tab_size);
        printf("\nPodaj liczbe rzeczywista: ");
        float liczba;
        scanf(" %f", &liczba);
        printf("Wybierz jedno z nastepujacych dzialan:\n");
        printf("1 - zliczenie liczb w tablicy mniejszych od podanej.\n");
        printf("2 - wyznaczenie liczby z tablicy o wartosci najblizszej do podanej oraz jej adresu w pamieci.\n");
        printf("3 - zakonczenie programu.\n");
        printf("Kod dzialania: ");
        unsigned int select;
        scanf(" %d", &select);
        float *fp;
        switch (select) {
            case 1:
                printf("Liczb mniejszych od %f w tablicy jest %d.\n", liczba, zliczenie(tab, tab_size, liczba));
                break;
            case 2:
                fp = najblizsza(tab, tab_size, liczba);
                printf("Liczba najblizsza %f to %f o adresie %p.\n", liczba, *fp, fp);
                break;
            case 3:
                break;
            default:
                printf("Podano zly kod dzialania.\n");
        }
        printf("Konczenie programu.");
    } else {
        printf("Nie mozna bylo zaalokowac pamiec na tablice.");
    }
    free(tab);
    return 0;
}

inline float* fill_tab(float *tab, int tab_size) {
    for (int i=0; i<tab_size; i++) {
        tab[i] = (float) rand() / 32767.0;
    }
}

void print_tab(float *tab, int tab_size) {
    printf("[");
    for (int i=0; i<tab_size-1; i++) {
        printf("%f, ", tab[i]);
    }
    printf("%f]", tab[tab_size-1]);
}

inline int zliczenie(float *tab, int tab_size, float liczba) {
    int licznik = 0;
    for (int i=0; i<tab_size; i++) {
        if (tab[i] < liczba) {
            ++licznik;
        }
    }
    return licznik;
}

inline float* najblizsza(float *tab, int tab_size, float liczba) {
    float diff = 1.0;
    float tmp_diff;
    float *tmp;
    for (int i=0; i<tab_size; i++) {
        tmp_diff = fabs(tab[i] - liczba);
        if (diff > tmp_diff) {
            diff = tmp_diff;
            tmp = &tab[i];
        }
    }
    return tmp;
}