#include <stdio.h>

// Napisz program który wylicza i wyświetla zakresy liczb całkowitych.

int main(){
    unsigned ilosc_mnozen = 0;
    unsigned char x = 1;
    while (x != 0){
        x = x*2;
        ilosc_mnozen++;
    }
    printf("Ilosc mnozen (liczba bitow liczby typu char) wynosi %d", ilosc_mnozen);
    return 0;
};