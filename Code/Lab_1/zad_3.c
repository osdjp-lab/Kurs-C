#include <stdio.h>
#include <math.h>

/*
/ Napisz program który wyświetla rzutowanie typu rzeczywistego (double) na typ
/ całkowity (int) a następnie wyświetla część po przecinku tej liczby rzeczywistej.
/ Jeżeli liczba wykracza poza zakres int, to należy wyświetlić wartość maksymalną
/ dla int, analogicznie dla wartości minimalnej.
*/

int main(){
    double x;
    scanf("%lf", &x);
    // if x > int max return max else return (int) x
    int y;
    if (x > 2^32 - 1){  // x > 0x7FFFFFFF (2^32 - 1) [1024.0 * 1024 * 2048]
        y = 2^32 - 1;
    } else if (x < - (2^32)){  // x < 0x80000000 (- (2^32)) [-1024.0 * 1024 * 2048]
        y = - (2^32);
    } else{
        y = (int) x;
    }
    // Integer part of double
    printf("Integer: %d\n", &y);
    // Fraction part of double
    double z = fmod(x, 1.0);
    printf("Remainder: %f\n", &z);
    return 0;
};