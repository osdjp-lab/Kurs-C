#include <stdio.h>
#include <math.h>

unsigned long long n;
unsigned pierw, p, k;

int main() {
    scanf(" %llu", &n);
    pierw = sqrt(n);
    if (n < 4)
        printf("%d", n);
    else {
        for (p = 2; p <= pierw; p++) {
            // sprawdzany czy p^k | n
            k = 0;
            while (n%p == 0) {
                k++;
                n/=p;
            }
            if (k > 0) {
                if (k > 1) {
                    printf("%u^%u*", p, k);
                } else {
                    printf("%u*", p);
                }
            }
        }
        if (n > 1) {
            printf("%llu", n);
        } else {
            printf("\b ");
        }
    }
    return 0;
}