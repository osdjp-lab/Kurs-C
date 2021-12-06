/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
char znak;
int malpa = 0;
int duze = 0;
int male = 0;
int cyfry = 0;
int ready = 0;
int i;
int ile;
int k;
int zdanie[40];
while (ready == 0){
    for(i =0; i<40; i++){
        zdanie[i] = 0;
    }
    malpa = 0;
    duze = 0;
    male = 0;
    cyfry = 0;
    i = 1;
    ile = 0;
    do{
    
    znak = getchar();
    ile ++;
    if(znak <= 122 && znak >= 97){
        male ++;
    }
    if(znak <= 90 && znak >= 65){
        duze ++;
    }
    if(znak <= 57 && znak >= 48){
        cyfry ++;
    }
    if(znak == 64){
        malpa ++;
    }
    i ++;
    if(znak <= 122 && znak >= 97){
        znak -= 32;
    }
        zdanie[i] += znak;
    }
    while (znak != '\n');
    if (male > 0 && duze > 0 && cyfry > 0 && malpa == 1){
        ready = 1;
    }else{
        printf("Zly adres, podaj jeszcze raz!\n");
    }
}

    for(k=2;k<ile + 1;k++){
        printf("%c",zdanie[k]);
    }
    int m = 1;
    int n = 4;
    int liczba;
    liczba = m + (rand() % (n + 1 - m));
    char* tab = (char*)malloc(liczba * sizeof(int));
    printf("\nWpisz tekst wiadomosci\n");
    int ilosc_znakow = 0;
    do{
        znak = getchar();
        if(ilosc_znakow >= liczba * sizeof(int) ){
            printf("Tablica przepelniona");
            break;
        }else{
            tab[ilosc_znakow] = znak;
        }
        ilosc_znakow ++;
    }
    while(znak != '\n');
    return 0;
}
