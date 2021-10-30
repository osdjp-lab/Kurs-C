#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    char symbol;
    int count;
} char_count;

int main() {
    char str[256]; 
    printf("Podaj ciag znakow: ");
    scanf("%s", &str);
    char_count char_table[128];
    int i;
    for (i=0; i<128; i++) {
        char_table[i].count = 0;
        char_table[i].symbol = '\n';
    }
    int j=0;
    for (i=0; i<strlen(str); i++) {
        char_table[j].symbol = str[i];
        char_table[j].count += 1;
        j++;
    }
    i = 0;
    // while (i < 128) {
    while(char_table[i].symbol != '\n') {
        printf("%c_%d\n", char_table[i].symbol, char_table[i].count);
        i++;
    }
}