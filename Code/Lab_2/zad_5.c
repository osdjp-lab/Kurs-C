#include <stdio.h>

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

