#include <stdio.h>
#include <stdlib.h>

void drucke(int n){
    // Variablendeklarationen
    int irow, icol, cols, col_center, rows;
    char** cells;

    // Berechnung des 2-dim. Arrays und der Mitte
    rows = n+3;
    cols = 7+2*n;
    col_center = (cols - 1)/2;

    // Initialisieren des 2-dim. Arrays
    cells = malloc(rows * sizeof(char*));

    for (irow=0; irow < rows; irow++){
        // reservieren der Spaltenarrays
        cells[irow]=malloc((cols+1) * sizeof(char)); // +1 wegen '\0'

        // initialisieren der Spaltenarrays
        for (icol=0; icol < cols; icol++){
            cells[irow][icol] = ' ';
        }

        // terminieren der Spaltenstrings
        cells[irow][cols] = '\0'; // für Ausgabe als String/Zeichenkette
    }


    // Zeichnen der Figur
    // 1. Zeile
    cells[0][col_center] = '*';

    // Beine
    for (irow = 1, icol = 1; irow < rows-1; irow++, icol++){
        // Zeichnen der beiden Beine
        cells[irow][col_center + icol] = '*';
        cells[irow][col_center - icol] = '*';
    }

    // Zeichnen der Fuesse
    for (icol = 0; icol < 3; icol++){
        cells[irow][0+icol] = '*';
        cells[irow][cols-1-icol] = '*';
    }


    // Ausgabe der Strings/Zeichenketten
    for (irow=0; irow < rows;irow++){
        printf("%s\n", cells[irow]);
    }
}



int main() {
    drucke (1);
    return 0;
}
