#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    puts("podaj nieujemna dlugosc lancucha znakow: ");
    
    
    // char chrs[] = "qwerty"; // 
    char chrs[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBMN"; // 52 0-51
    
    
    int n;
    
    scanf(" %d", &n);
    
    while(n <= 0){
        printf("dlugosc n musi byc nieujemna!\n");
        scanf(" %d", &n);
    }
        
    
    char tab = (char) malloc(n * sizeof(char));
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        int index = (rand() % 52);
        tab[i] = chrs[index];
    }
    
    // for (int i = 0; i < n; i++) {
    //     tab[i] = 'a';
    // }
    
    
    //printf("%ld", sizeof(tab));
    
    // printf("%ld\n", sizeof(chrs));
    
    int choice;
    char symbol;
    
    printf("\n");
    
    do {
        printf("MENU\n\n");
        printf("1) Podaj litere\n2) Najczestszy\n3)zakoncz program\n");
        
        scanf( "%d", &choice);
        
        if(choice == 1){
            puts("Podaj litere: ");
            scanf(" %c", &symbol);
            
            if (!isalpha(symbol)){
                printf(" Podales nie litere");
            }
            else {
                int total = 0;
                if(tab != 0) {
                    for (int i = 0; i < n; i++) {
                        if(tolower(tab[i]) == tolower(symbol)) {
                            total++;
                        }
                    }
                    printf("razem zliczono wystapienie %c i %c %8d raz/y\n", tolower(symbol), toupper(symbol), total);
                }
                else{
                    printf("tablica jest pusta");
                }
            }
        }
        else if (choice == 2) {
            int occurences[52];
            
            for (int i = 0; i < 52; i++) {
                occurences[i] = 0;
            }
            
            for (int i = 0; i < n; i++) {
                char c = tab[i];
                // int index = -1;
                for (int j = 0; j < (sizeof(chrs) - 1); j++) {
                    if (chrs[j] == c){
                        // index = i;
                        occurences[j]++;
                    }
                        // break;
                }
                
            }
            
            // printf("\n");
            // for(int i = 0; i < 52; i++) {
            //     printf("%d\n", occurences[i]);
            // }

            
            int valueMax = 0;
            int indexMax = 0;
            
            
            for (int i = 0; i < 52; i++) {
                if (occurences[i] >= valueMax) {
                    valueMax = occurences[i];
                    indexMax = i;
                }
            }
            printf("Najczesciej wystepujaca litera to: %c\n", chrs[indexMax]);
            
            
        }
        
        else {
            if (choice != 3)
                printf("Nie ma takiej opcji w Menu!\n");
        }
        
    }while(choice != 3);
    
    free(tab);
    
    printf("KONIEC PROGRAMU");
    
    

    return 0;
}