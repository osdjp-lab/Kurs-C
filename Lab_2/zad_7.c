#include <stdio.h>
#include <math.h>

// zakres liczb 1...128

unsigned min_val = 1;
unsigned n;
unsigned max_val = 128;
char tmp;

int main() {
    for(int i=0; i<8; i++) {
        n = (min_val + max_val) / 2;
        printf("Zgadnieta liczba: %u.\n", n);
        printf("Czy twoja liczba jest rowna (r), wieksza (w) czy mniejsza (m): ");
        tmp = getchar();
        int c;
        while ((c = getchar()) != '\n') { };
        printf("\n");
        if (tmp == 'r')
            break;
        if (tmp == 'w')
            min_val = n;
        else 
            max_val = n;
    }
    printf("Twoja liczba to: %u", n);
    return 0;
}