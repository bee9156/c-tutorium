/*
Diese Datei enthält Aufgaben zum rekusriven arbeiten mit Strings
*/

// includes
#include <stdio.h>

/*
allgemein:
Für alle Aufgaben ist, falls nötig, eine entsprechende Vorwärtsdeklaration anzulegen
Es dürfen nur die über den vorgegebenen Include verfügbaren Funktionen genutzt werden.

Aufgabe a)
Schreibe die rekursive Funktion rec_string_laenge.

Die Funktion soll eine Ganzzahl mit der entsprechenden Länge der Zeichenkette zurückgeben.
Es darf angenommen werden das die Zeichenkette korrekt terminiert wurde.


Aufgabe b)
Schreibe die rekursive Funktion rec_zaehle_umlaute.

Wie durch den name bereits zu erahnen ist, soll die Funktion die Umlaute eines Stringszählen
(a, e, i, o, u) und als Ganzzahl zurückgeben.


Aufgabe c)

Schreibe die Funktion rec_zaehle_buchstaben.

Diese Funktion soll die einzelnen Buchstaben zählen und in ein Array speichern, welches
ebenfalls als Parameter übergeben wird.


Ausgabe:
Bei korrekter Programmierung erhält man folgende Ausgabe:

Aufgabe a)
Die Länge des Strings "Ich bin ein String" beträgt 18.

Aufgabe b)
Der String "Ich bin ein String" beinhaltet 5 Umlaute.

Aufgabe c)
Der Buchstabe "a" kommt 0 mal vor.
Der Buchstabe "b" kommt 1 mal vor.
Der Buchstabe "c" kommt 1 mal vor.
Der Buchstabe "d" kommt 0 mal vor.
Der Buchstabe "e" kommt 1 mal vor.
Der Buchstabe "f" kommt 0 mal vor.
Der Buchstabe "g" kommt 1 mal vor.
Der Buchstabe "h" kommt 1 mal vor.
Der Buchstabe "i" kommt 4 mal vor.
Der Buchstabe "j" kommt 0 mal vor.
Der Buchstabe "k" kommt 0 mal vor.
Der Buchstabe "l" kommt 0 mal vor.
Der Buchstabe "m" kommt 0 mal vor.
Der Buchstabe "n" kommt 3 mal vor.
Der Buchstabe "o" kommt 0 mal vor.
Der Buchstabe "p" kommt 0 mal vor.
Der Buchstabe "q" kommt 0 mal vor.
Der Buchstabe "r" kommt 1 mal vor.
Der Buchstabe "s" kommt 1 mal vor.
Der Buchstabe "t" kommt 1 mal vor.
Der Buchstabe "u" kommt 0 mal vor.
Der Buchstabe "v" kommt 0 mal vor.
Der Buchstabe "w" kommt 0 mal vor.
Der Buchstabe "x" kommt 0 mal vor.
Der Buchstabe "y" kommt 0 mal vor.
Der Buchstabe "z" kommt 0 mal vor.



*/

// Vorwärsdeklarationen
int rec_string_laenge(char* string, int i){
    if (string[i] == '\0'){
        return 0;
    } else {
        return 1 + rec_string_laenge(string, i + 1);
    }
}

int is_umlaut(char c){
    return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}

int rec_zaehle_umlaute(char* string, int i){
    if (string[i] == '\0'){
        return 0;
    } else if (is_umlaut(string[i])) {
        return 1 + rec_zaehle_umlaute(string, i +1);
    } else {
        return rec_zaehle_umlaute(string, i + 1);
    }
}

void rec_zaehle_buchstaben(int* arr, char* string, int i){
    if ( string[i] == '\0') {
        return;
    } else {
        if (string[i] >= 'a' && string[i] <= 'z') {
            arr[string[i] - 'a']++;
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            arr[string[i] - 'A']++;
        }
    
        rec_zaehle_buchstaben(arr, string, i + 1);
    }
}

// Main
int main(){
    int i = 0;
    int result;
    char string1[] = "Ich bin ein String";
    int alphabet[26] = {};
    
    // Aufgabe a)
    puts("\nAufgabe a)");
    result = rec_string_laenge(string1, 0);
    printf("Die Länge des Strings \"%s\" beträgt %d.\n", string1, result);
    
    // Aufgabe b)
    puts("\nAufgabe b)");
    result = rec_zaehle_umlaute(string1, 0);
    printf("Der String \"%s\" beinhaltet %d Umlaute.\n", string1, result);
    
    // Aufgabe c)
    puts("\nAufgabe c)");
    rec_zaehle_buchstaben(alphabet, string1, 0);
    
    for (i = 0; i < 26; i++){
        printf("Der Buchstabe \"%c\" kommt %d mal vor.\n", 'a' + i, alphabet[i]);
    }
    

    return 0;
}