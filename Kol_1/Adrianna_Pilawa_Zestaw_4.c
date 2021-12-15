# include <stdio.h>
# include <stdlib.h>

int main()
{
    int rozmiar_tablicy;
    float rzeczywista;
    int numer;
    int suma = 0;
    int *wskaznik;
    // Prośba o podanie rozmiaru tablicy
    printf("Proszę o podanie rozmiaru tablicy: ");
    scanf("%d", &rozmiar_tablicy);
    int tablica[rozmiar_tablicy];
    
    // Dynamiczne tworzenie tablicy losowych liczb z zakresu [0, 1]
    for(int i = 0; i < rozmiar_tablicy; i++){
        tablica[i] = (int) rand()%2;
    }
    
    // Menu
    printf("Proszę o podanie liczby rzeczywistej: ");
    scanf("%f", &rzeczywista);
    POWROT:
    printf("\nProszę o wybór jednej z opcji: \n 1: Policzenie liczb w tablicy mniejszych od podanej. \n 2: Liczba z tablicy o wartości najbliższej od podanej oraz jej adres w pamięci. \n 3: Zakończenie programu.\n");
    printf("Opcja numer: ");
    scanf("%d", &numer);
    
    // Opcje do wyboru przez użytkownika
    switch(numer){
        case 1:
            for(int i = 0; i < rozmiar_tablicy; i++){
                if(tablica[i] < rzeczywista){
                    suma += 1;
                }
            }
            printf("\n Ilość liczb mniejszych od podanej liczby: %d \n", suma);
            goto POWROT;
        case 2:
            if(rzeczywista >= 0.5){
                for(int i = 0; i < rozmiar_tablicy; i++){
                    if(tablica[i] == 1){
                        printf("Liczba: %d oraz jej adres w pamięci: %d \n", tablica[i], &tablica[i]);
                    }
                }
            }else{
                for(int i = 0; i < rozmiar_tablicy; i++){
                    if(tablica[i] == 0){
                        printf("Liczba: %d oraz jej adres w pamięci: %d \n", tablica[i], &tablica[i]);
                    }
                }
            }
            goto POWROT;
        case 3:
            break; // Nie przechodzimy do menu, bo jest zakończenie programu.
        
    }
    return 0;
}