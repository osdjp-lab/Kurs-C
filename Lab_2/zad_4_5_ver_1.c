#include <stdio.h>
#include <stdbool.h>

/*
/ Napisz program, który zlicza ilosc wyrazow podanych przez
/ uzytkownika. Nalezy uwzglednic, ze uzytkownik moze wpisywac
/ spacje przed zdaniem i uzywac wiekszej ilosci spacji pod rzad.
*/

/*
/ Przerob wczesniejszy program tak by wypisywal zdanie podane przez
/ uzytkownika usuwajac nadmiarowe spacje oraz piszac kazdy kolejny
/ wyraz z duzej litery.
*/

int main() {
    printf("Podaj lancuch znakow:\n");
    unsigned il_wyrazow = 0;
    char znak;
    bool czyspacja = true;
    do {
        znak = getchar();
        if (znak == ' ') {
            if (!czyspacja)
                putchar('_');
            czyspacja = true;
        } else {
            if (czyspacja) {
                if (znak <= 'z' && znak >= 'a')
                    znak += 'A'-'a';
                il_wyrazow++;
            }
            czyspacja = false;
            putchar(znak);
        }
    } while (znak != '\n');
    printf("Podano %u wyrazow", il_wyrazow);
}