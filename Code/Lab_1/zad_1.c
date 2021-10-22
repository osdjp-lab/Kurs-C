#include <stdio.h>

// Napisz program wyświetlający znaki:
// \n, \r, \t, \b, \a, \f, \\, \', \"
// %c - print symbol
// %d, %hd, %u - print integer (%i ???)
// '_' - symbol
// "_" - symbol list

const char symbol_n[] = "\\n";
const char symbol_r[] = "\\r";
const char symbol_t[] = "\\t";
const char symbol_b[] = "\\b";
const char symbol_a[] = "\\a";
const char symbol_f[] = "\\f";
const char symbol_dash[] = "\\\\";
const char symbol_q[] = "\\'";
const char symbol_qt[] = "\\\"";
const char* symbol_list[] = {symbol_n, symbol_r, symbol_t, symbol_b,
symbol_a, symbol_f, symbol_dash, symbol_q, symbol_qt};
// const char symbol_list[] = {"\n", "\\r", "\\t", "\\b", "\\a", "\\f", "\\\\", "\\'", "\\\""};
const char symbol_values[] = {'\n', '\r', '\t', '\b', '\a', '\f', '\\', '\'', '\"'};

int main(){
    for(int i=0; i<=8; i++){
        printf("symbol %c%c - ", symbol_list[i][0], symbol_list[i][1]);
        printf("wartosc %d\n", symbol_values[i]);
    };
    return 0;
};