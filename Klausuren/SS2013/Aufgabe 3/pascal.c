#include <stdio.h>      // für printf

int pascal(int z, int s)
{
    if (z == 1 || s == 1) return 1;
    else return (pascal(z, s - 1) + pascal(z - 1, s));
}

void dreieck(int n)
{
    int rows, cols;
    for (rows = 1; rows <= n; rows++){
        for(cols = 1; cols <= n - rows + 1; cols++){
            printf(" %2d", pascal(rows, cols));
        }
        printf("\n");
    }
}


int main(void){
    dreieck(7);

    return 0;
}
