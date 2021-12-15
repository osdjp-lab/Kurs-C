#include <ctype.h>
#include <stdio.h>
#include <string.h>

//Fixed-mixed

int main(void) 
{
  
int key;
int ch;
int output;
char choose;

while(choose != 'N')
    {
    printf ("Wybierz:\n1) Szyfrowanie teksu. (wpisz T)\n2) Zakonczenie programu. (wpisz N)\n");
    scanf (" %c", &choose);
    if(choose == 'T'){
        printf ("Podaj przesuniecie: ");
        scanf (" %d", &key);
        key %= 26;
  
        if (key < 0){
           key += 26;}
  
        printf ("Podaj wiadomość: ");
        scanf (" %d", &ch);
        while((ch=getchar())!=10)
        {
            
        if (isupper (ch)){
            putchar('A'+(ch-'A'+key)%26);
        }
         else if (islower (ch)){
            putchar ('a' + (ch - 'a' + key) % 26);}
  
        else{
            //printf("\n %d", ch);
            putchar (ch);}
            continue;
        }
        printf("\n");
    }
    }
    
}

