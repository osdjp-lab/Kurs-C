#include <stdio.h>
#include <string.h>

/*
/ Napisz program wczytujacy podana przez uzytkownika ilosc slow
/ (o rozmiarze do 23 znakow) i wyswietlajace podane slowa
/ w porzadku leksykograficznym.
*/

// qsort i strcmp

int main() {
	unsigned n;
	printf("Podaj liczbe slow: ");
	scanf(" %n", &n);
	char *wsk = (char *) malloc(24*n);
	if (wsk) {
		for(int i=0; i<n; i++)
			scanf(" %23s", wsk+24*i);
		qsort(wsk, n, 24, strcmp);
		printf("Posortowano\n");
		for (int i=0; i<n; i++)
			printf("%s\n", wsk+24*i);
	} else
		printf("Blad alokacji pamieci\n");
    	return 0;
}
