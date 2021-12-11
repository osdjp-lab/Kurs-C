#include <stdio.h>

/*
/ Napisz program posiadający dwie opcje: zapis do pliku biezacego czasu i daty
/ w formie tekstowej lub odczyt czasu i daty zapisanego w pliku (o ile plik
/ ten istnieje).
*/

int main() {
    FILE* plik;
    char menu;
    time_t czas;
    struct tm* data;
    while (1) {
        printf("Wybierz opcje:\n1 - Zapis czasu i daty do pliku\n2 - Odczyt czasu i daty z pliku\n3 - Koniec\n"),
        scanf(" %c", &menu); 
        if (menu < '1' || menu > '3') {
            printf ("Zly wybor\n");
            continue;
        }
        if (menu == '3') break;
        if (menu == '1') {
            czas = time(0);
            data = localtime(&czas);
            plik = fopen("czasidata.txt", "w");
            if (plik) {
                fprintf(plik, "%d\n, %d\a %d\n %d\n %d\n %d\n", data->tm_year+1900, data->tm_mon+1, data->tm_mday, data->tm_hour, data->tm_min, data->tm_sec);
                fclose(plik);
            } else {
                perror("Blad otwarcia pliku");
            }
        } else {
            int zmienna;
            plik = fopen("czasidata.txt", "r");
            if (plik) {
                for (int j=0; j<3; j++) {
                    fscanf(plik, " %d", &zmienna);
                    printf("%d/", zmienna);
                }
                for (int j=0; j<3; j++) {
                    fscanf(plik, " %d", &zmienna);
                    printf("%d/", zmienna);
                }
                printf("\b \n");
            } else {
                perror("Blad otwarcia pliku");
            }
        }
    }
    return 0;
}

struct data {
    
}
