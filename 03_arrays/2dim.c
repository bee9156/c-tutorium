#include <stdio.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10


int main(){
int zeile = 0;
int spalte = 0;

char arr[MAX_HEIGHT][MAX_WIDTH];

for (zeile = 0; zeile < MAX_HEIGHT; zeile++) {
    for( spalte = 0; spalte < MAX_WIDTH; spalte++) {
        arr[zeile][spalte] = ' ';
    }
}


for (zeile = 0; zeile < MAX_HEIGHT; zeile++) {

    if ( zeile == 0 || zeile == MAX_HEIGHT -1){
        for (spalte = 1; spalte < MAX_WIDTH -1; spalte++){
            arr[zeile][spalte] = '*';
        }
    } else {
        arr[zeile][0] = '*';
        arr[zeile][MAX_WIDTH-1] = '*';
        arr[zeile][MAX_WIDTH-1-zeile] = '*';
    }
}


for (zeile = 0; zeile < MAX_HEIGHT; zeile++) {
    for( spalte = 0; spalte < MAX_WIDTH; spalte++) {
        printf("%c", arr[zeile][spalte]);
    }
    
    printf("\n");
}


return 0;
}