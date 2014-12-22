#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substring(...) {

}

int main(void)
{
    char* sub = substring("Hamburger", 3, 7);

    if ( sub != NULL){
        printf("%s\n", sub);
        free(sub);
    } else {
        puts("sub = NULL");
    }

    return 0;
}