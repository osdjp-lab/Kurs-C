#include <stdio.h>

/*
/ Napisz program, ktory poprzez menu pozwala na zapisanie tekstu
/ podanego przez uzytkownika do pliku albo wyswietlenie zawartosci
/ tego pliku tekstowego.
*/

int main() {
    FILE * plik;
    char nazwa_pliku [64];
    char c, menu;
    do {
        printf("Wybierz opcje:\n1 - Wyswietl zawartosc pliku\n2 - Zapisz tekst do pliku\n3 - Koniec\n");
        scanf(" %c", &menu);
        if (menu == '1') {
            printf("Podaj nazwe pliku:");
            scanf(" %[^\n]s", nazwa_pliku);
            plik = fopen(nazwa_pliku, "r");
            if (plik) {
                while(1) {
                    c = fgetc(plik);
                    if (c != EOF) putchar(c);
                    else break;
                }
            fclose(plik);
            } else perror("Problem z otwarciem pliku");
        } else if (menu == '2') {
            printf("Podaj nazwe pliku:");
            scanf(" %[^\n]s", nazwa_pliku);
            plik = fopen(nazwa_pliku, "w");
            if (plik) {
                printf("Podaj tekst do zapisania:");
                while(1) {
                    c = getchar();
                    if (c != '\n') fputc(c, plik);
                    else break;
                }
            fclose(plik);
            } else perror("Problem z otwarciem pliku");
        } else printf("Nieprawidlowy wybor");
    } while(menu != '3');
    return 0;
}
