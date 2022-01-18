#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Zestaw 3

typedef struct komorka komorka;
typedef struct info info;
typedef struct wymiary wymiary;

struct info {
    enum typ {
        brak = -1,
        liczba = 0,
        tekst = 1,
    }typ;
    komorka *wskaznik;
};

struct komorka {
    unsigned int filled;
    int wiersz;
    int kolumna;
    enum typ_danych{
        liczba = 0,
        tekst = 1,
    }typ_danych;
    union dane {
        double liczba;
        char tekst[56];
    }dane;
    komorka *next_komorka;
};

struct wymiary {
    int wierszy;
    int kolumn;
};

void init_lista(komorka *pierwsza, wymiary *tabela) {
    pierwsza = malloc(tabela->wierszy*tabela->kolumn*sizeof(komorka));
    for (int i=0; i<tabela->wierszy*tabela->kolumn-1; i++) {
        pierwsza[i].filled = 0;
        pierwsza[i].next_komorka = &pierwsza[i+1];
        pierwsza[i].wiersz = i%tabela->kolumn;
        pierwsza[i].kolumna = i%tabela->wierszy;
    }
}

void dodaj_komorke_liczba(komorka *pierwsza, wymiary *tabela, double n) {
    for (int i=0; i<tabela->wierszy*tabela->kolumn-1; i++) {
        if (pierwsza[i].filled == 0) {
            pierwsza[i].filled = 1;
            pierwsza[i].typ_danych = liczba;
            pierwsza[i].dane.liczba = n;
            break;
        }
    }
}

void dodaj_komorke_text(komorka *pierwsza, wymiary *tabela, char t[56]) {
    for (int i=0; i<tabela->wierszy*tabela->kolumn-1; i++) {
        if (pierwsza[i].filled == 0) {
            pierwsza[i].filled = 1;
            pierwsza[i].typ_danych = tekst;
            strcpy(pierwsza[i].dane.tekst, t);
            break;
        }
    }
}

void zmien_zawartosc_komorki_liczba(komorka *pierwsza, wymiary *tabela, int wiersz, int kolumna, double n) {
    for (int i=0; i<tabela->wierszy*tabela->kolumn-1; i++) {
        if (pierwsza[i].wiersz == wiersz && pierwsza[i].kolumna == kolumna) {
            pierwsza[i].filled = 1;
            pierwsza[i].typ_danych = liczba;
            pierwsza[i].dane.liczba = n;
            break;
        }
    }
}

void zmien_zawartosc_komorki_text(komorka *pierwsza, wymiary *tabela, int wiersz, int kolumna, char t[56]) {
    for (int i=0; i<tabela->wierszy*tabela->kolumn-1; i++) {
        if (pierwsza[i].wiersz == wiersz && pierwsza[i].kolumna == kolumna) {
            pierwsza[i].filled = 1;
            pierwsza[i].typ_danych = liczba;
            strcpy(pierwsza[i].dane.tekst, t);
            break;
        }
    }
}

void zapisz_do_pliku(komorka *pierwsza, wymiary *tabela) {
    // FILE *plik = fopen("arkusz.dat", "w");
}

void odczytaj_z_pliku(komorka *pierwsza, wymiary *tabela) {
    // FILE *plik = fopen("arkusz.dat", "r");
    // init_lista(pierwsza, tabela);
}

info wyswietl_zawartosc(komorka *pierwsza, wymiary *tabela, int wiersz, int kolumna) {
    info tmp;
    for (int i=0; i<tabela->wierszy*tabela->kolumn-1; i++) {
        if (pierwsza[i].wiersz == wiersz && pierwsza[i].kolumna == kolumna) {
            tmp.typ = pierwsza[i].typ_danych;
            tmp.wskaznik = &pierwsza[i];
            break;
        }
    }
    return tmp;
}

int main() {
    int state = 1;
    komorka *pierwsza;
    // Ustalenie wielkosci tabeli
    wymiary *tabela;
    while (state) {
        printf("Wybierz dzialanie:\n");
        printf("1 - utworz nowa tabele\n");
        printf("2 - odczytaj z pliku liste\n");
        scanf(" %d", &state);
        switch (state) {
            case 1:
                while (1) {
                    printf("Podaj wiersz:");
                    scanf(" %d", tabela->wierszy);
                    printf("\nPodaj kolume:");
                    scanf(" %d", tabela->kolumn);
                    if (tabela->wierszy < 1 || tabela->kolumn < 1) {
                        printf("Podano bledna wielkosc tabeli.");
                        printf("Podaj wlasciwe wymiary.");
                    } else {
                        init_lista(pierwsza, tabela);
                        break;
                    }
                }
                state = 0;
                break;
            case 2:
                odczytaj_z_pliku(pierwsza, tabela);
                state = 0;
                break;
            default:
                printf("Podano zly kod dzialania.");
        }
    }
    state = 1;
    while (state) {
        printf("Wybierz dzialanie:\n");
        printf("0 - exit\n");
        printf("1 - dodaj komorke\n");
        printf("2 - zmien zwartosc komorki\n");
        printf("3 - zapisz do pliku liste\n");
        printf("4 - wyswietl zawartosc komorki\n");
        scanf(" %d", &state);
        switch (state) {
            case 0:
                break;
            case 1:
                printf("Podaj typ zawartosci:\n");
                printf("0 - liczba\n");
                printf("1 - text");
                int type;
                scanf(" %d", &type);
                printf("Podaj zawartosc:\n");
                switch (type) {
                    case 0:
                        double n;
                        scanf(" %f", &n);
                        dodaj_komorke_liczba(pierwsza, tabela, n);
                    case 1:
                        char tmp[56];
                        scanf(" %s", &tmp);
                        dodaj_komorke_text(pierwsza, tabela, tmp);
                    default:
                        printf("Podano zly typ zawartosci.\n");
                }
                break;
            case 2:
                printf("Podaj wiersz:");
                int wiersz;
                scanf(" %d", &wiersz);
                printf("\nPodaj kolume:");
                int kolumna;
                scanf(" %d", &kolumna);
                printf("Podaj typ zawartosci:\n");
                printf("0 - liczba\n");
                printf("1 - text");
                int type;
                scanf(" %d", &type);
                printf("Podaj zawartosc:\n");
                switch (type) {
                    case 0:
                        double n;
                        scanf(" %f", &n);
                        zmien_zawartosc_komorki_liczba(pierwsza, tabela, wiersz, kolumna, n);
                    case 1:
                        char tmp[56];
                        scanf(" %s", &tmp);
                        zmien_zawartosc_komorki_text(pierwsza, tabela, wiersz, kolumna, tmp);
                    default:
                        printf("Podano zly typ zawartosci.\n");
                }
                break;
            case 3:
                zapisz_do_pliku(pierwsza, tabela);
                break;
            case 4:
                printf("Podaj wiersz:");
                int wiersz;
                scanf(" %d", &wiersz);
                printf("\nPodaj kolume:");
                int kolumna;
                scanf(" %d", &kolumna);
                info tmp = wyswietl_zawartosc(pierwsza, tabela, wiersz, kolumna);
                printf("Komorka (%d, %d)\n", wiersz, kolumna);
                if (tmp.typ == -1) {
                    printf("Komorka jest pusta.");
                } else if (tmp.typ == 0) {
                    printf("Komórka zawiera: %d", tmp.wskaznik->dane.liczba);
                } else {
                    printf("Komórka zawiera: %s", tmp.wskaznik->dane.tekst);
                }
                break;
            default:
                printf("Podano zly kod dzialania.\n");
        }
    }
    printf("Konczenie programu.");
    free(pierwsza);
    return 0;
}
