#include <stdio.h>

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

const char sentence[] = "Hello world this is a simple program for initial tests.\n";

// 97 -> 65

typedef struct symbol {
    char character;
    symbol  *nextptr;
};

void add_char(symbol *head, char symbol) {
    symbol element = {symbol, NULL};
    symbol* current = head;
    while (current->nextptr != NULL) {
        current = current->nextptr;
    }
    head->nextptr = &element;
}

int main() {
    printf("Podaj lancuch znakow:\n");
    // Inicjalizacja lancucha znakow
    struct symbol *head = NULL;
    // Wczytanie lancucha znakow
    while(1) {
        char symbol = getchar();
        if (symbol != "\n") {
            add_char(head, symbol);
        } else {
            break;
        }
    }
    // Przetworzenie lancucha znakow



    printf("Przetworzony lancuch znakow: ");
    return 0;
}

