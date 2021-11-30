#include <stdio.h>

/*
/ Za pomoca wskaznikow na funkcje napisz program, ktory prosi uzytkownika
/ o podanie jednej z operacji +, *, a nastepnie odpowiedni wskaznik zostaje
/ przypisany zmiennej wskazujacej na funkcje wykonujaca dana operacje
/ i wywolany poprzez ta zmienna.
*/

double dodaj(double x, double y) {
	return x + y;
}

double mnoz(double x, double y) {
	return x * y;
}

int main() {
	double (*wsk_na_funkcje)(double, double);
	printf("Podaj dwie liczby: ");
	double x, y;
	char c;
	scanf(" %lf %lf", &x, &y);
	printf("Podaj operacje (+, *): ");
	scanf(" %c", &c);
	switch(c) {
		case '+':
			wsk_na_funkcje = dodaj;
			break;
		case '*':
			wsk_na_funkcje = mnoz;
			break;
		default:
			wsk_na_funkcje = 0;
	}
	if (wsk_na_funkcje)
		printf("Wynik = %f\n", wsk_na_funkcje(x, y));
	else
		printf("Nieprawidlowe dzialanie\n");
	return 0;
}

