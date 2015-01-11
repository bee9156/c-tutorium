#include <stdio.h>
#include <stdlib.h>

struct board {int **cells;} bin;

int main()
{
    int c, i, j, num = 5;
    struct board *b = &bin;

    b->cells = malloc(sizeof(int*) * num);
    for(c = 0; c < num; c++){
        b->cells[c] = calloc(num, sizeof(int));
    }

    for (i=0; i < num; i++){
        for (j=0; j < i+1; j++) {
            if (j == 0 || j == i){
                b->cells[i][j] = 1;
            } else {
                b->cells[i][j] = b->cells[i-1][j-1] + b->cells[i-1][j];
            }
        }
    }

    for (i=0; i < num; i++){
        for (j=0; j < num; j++){
            printf("%3d", b->cells[i][j]);
        }
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}
