#include <stdio.h>

/*
/ Napisz program wyświetlający znaki:
/ \n, \r, \t, \b, \a, \f, \\, \', \"
/ %c - print char
/ %s - print c-string
/ %d, %hd, %u - print integer (%i ???)
/ '_' - symbol
/ "_" - symbol list
*/

const char* symbol_list[] = {"\\n", "\\r", "\\t", "\\b", "\\a", "\\f", "\\\\", "\\'", "\\\""};
const char symbol_values[] = {'\n', '\r', '\t', '\b', '\a', '\f', '\\', '\'', '\"'};

int main(){
    for(int i=0; i<=8; i++){
        printf("symbol %s - ", symbol_list[i]);
        printf("wartosc %d\n", symbol_values[i]);
    };
    return 0;
};