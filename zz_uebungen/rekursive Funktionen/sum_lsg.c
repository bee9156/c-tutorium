/*
Diese Übung dient dem rekursiven Berechnen von Summen
*/

// includes
#include <stdio.h>

/*
allgemein:
Für alle Aufgaben ist, falls nötig, eine entsprechende Vorwärtsdeklaration anzulegen
Es dürfen nur die über den vorgegebenen Include verfügbaren Funktionen genutzt werden.

Aufgabe a)
Schreibe die rekursive Funktion rec_sum.

Die Funktion rec_sum soll alle Ganzzahlen, inkl. der beiden als Parameter übergebenen, addieren.
Dabei ist darauf zu achten das es egal sein soll ob der 1. oder 2. Parameter der größere ist,
ebenso soll es möglich sein negative Zahlen zu übergeben.

Die benötigten Informationen sind aus dem Funktionsaufruf zu erkennen.


Aufgabe b)
Schreibe die rekursive Funktion rec_sum_array.

Die Funktion rec_sum_array soll alle im übergebenen Array enthaltenen Zahlen addieren.
Dabei ist darauf zu achten, dass die Funktion rec_sum_array unabhängig von der Arraygröße 
geschrieben werden soll.


Aufgabe c)
Schreibe die rekursive Funktion rec_sum_array2.

Die Funktion rec_sum_array2 soll alle im übergebenen Array enthaltenen Zahlen addieren.

Ausgabe:
Bei korrekter Programmierung erhält man folgende Ausgabe:

Aufgabe a)
Die Summe aller Zahlen zwischen 0 und 10 ist 55
Die Summe aller Zahlen zwischen 0 und -20 ist -210

Aufgabe b)
Die Summe aller Zahlen im Array arr beträgt 43

Aufgabe c)
Die Summe aller Zahlen im Array arr2 beträgt 43


*/

// defines
#define DEMO_ARRAY_LENGTH 15

// Vorwärtsdeklarationen
int rec_sum(int a, int b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return b + rec_sum(a, b + 1);
    } else {
        return b + rec_sum(a, b - 1);
    }
}

int rec_sum_array(int* arr, int i) {
    if (arr[i] == '\0'){
        return 0;
    } else {
        return arr[i] + rec_sum_array(arr, i + 1);
    }
}

void rec_sum_array2(int* result, int* arr, int i){
    if (arr[i] == '\0') {
        return;
    } else {
        *result++;
        rec_sum_array2(result, arr, i + 1);
    }
}

// Main
int main() {
    int a = 0;
    int b = 10;
    int c = -20;
    
    int arr[] = {2, 7, 3, 2, 5, -17, 34, -2, 9};
    int arr2[DEMO_ARRAY_LENGTH] = {5, 2, 77, 100};
    
    int result;
    
    // Aufgabe a)
    puts("\nAufgabe a)");
    result = rec_sum(a, b);
    printf("Die Summe aller Zahlen zwischen %d und %d ist %d\n", a, b, result);
    result = rec_sum(a, c);
    printf("Die Summe aller Zahlen zwischen %d und %d ist %d\n", a, c, result);
    
    // Aufgabe b)
    puts("\nAufgabe b)");
    result = rec_sum_array(arr, 0);
    printf("Die Summe aller Zahlen im Array arr beträgt %d\n", result);
    
    // Aufgabe c)
    puts("\nAufgabe c)");
    rec_sum_array2(&result, arr, 0);
    printf("Die Summe aller Zahlen im Array arr beträgt %d\n", result);
    

    return 0;
}