#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* string = strdup("abc");
    string[0] = 's';
    printf("%s\n", string);

    return 0;
}