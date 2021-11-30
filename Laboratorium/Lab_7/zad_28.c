#include <stdio.h>
#include <stdarg.h>

/*
/ Napisz program wykorzystujacy funkcje o zmiennej liczbie argumentow
/ do napisania uproszczonej wersji printf, ktora potrafi wyswietlic:
/ znak, lancuch znakow, liczbe typu int uzywajac takiej samej skladni
/ jak printf - %c, %s, %d (mozna uzyc tylko putchar do wyswietlania).
*/

char *intdochar(int n) {
	static char tekst[12];
	char czyujemna = 0;
	if (n < 0) {
		czyujemna = 1;
		n = -n;
	}
	tekst[n] = 0;
	int i=10;
	do {
		tekst[i] = '0' + (n % 10);
		n /= 10;
		i--;
	} while (n != 0);
	if (czyujemna)
		tekst[i] = '-';
	else
		i++;
	return (tekst+i);
}

void print(char *lancuch, ...) {
	va_list argumenty;
	va_start(argumenty, lancuch);
	char c;
	while (1) {
		c = lancuch[0];
		if (c == '0') break;
		if (c != '%') putchar(c);
		else {
			lancuch++;
			switch (lancuch[0]) {
				case '%':
					putchar('%');
					break;
				case 'c':
					c = va_arg(argumenty, int);
					putchar(c);
					break;
				case 's': {
					char *wsk = va_arg(argumenty, char*);
					while (*wsk != 0) {
						putchar(*wsk);
						wsk++;
					}
					break;
                }
				case 'd': {
					int n = va_arg(argumenty, int);
					char *wsk = intdochar(n);
					while (*wsk != 0) {
						putchar(*wsk);
						wsk++;
					}
					break;
                }
			} // koniec switch
		} // koniec else
	} // koniec while
} // koniec print


int main() {
    // print("%c", 'i');
    print("%s0", "hello");
    // print("%d", 15);
    return 0;
}
