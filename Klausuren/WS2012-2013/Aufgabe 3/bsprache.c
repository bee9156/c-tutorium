#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool istVokal(char c)
{
    // Ueberpruefung ob c ein Vokal ist
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int zaehleVokale(char* s)
{
    // lokale Variablen deklarieren
    int i, matches = 0;

    // den String s durchlaufen
    for (i=0; i < strlen(s); i++){

        // Pruefung ob an Stelle "i" der Zeichenkette "s" ein Vokal vorhanden ist
        if (istVokal(s[i])) {
            // Falls ja, dann zaehle diesen
            matches++;
        }
    }

    // gebe Zaehlergebnis zurueck
    return matches;
}

char* nachB(char* orig){
    // Laenge der neuen Zeiechenkette berechnen
    int newLen = strlen(orig) + 2*zaehleVokale(orig) +1;

    // Speicherplatz reservieren
    char* newString = malloc(newLen * sizeof(char));

    // Inhalte kopieren
    int isource = 0, itarget = 0;
    for (;isource < strlen(orig); isource++){
        // kopieren des original Characters
        newString[itarget++] = orig[isource];

        // Falls Vokal kopiert wurde dann mache die b-Sprache
        if (istVokal(orig[isource])){
            // anfuegen von "b"
            newString[itarget++] = 'b';
            // anfuegen von Vokal
            newString[itarget++] = orig[isource];
        }
    }

    // terminieren der Zeichenkette
    newString[itarget] = '\0';

    // neue Zeichenkette zurueckgeben
    return newString;
}

int main(void)
{
    char* saetze[] = {
        "das ist die b-sprache.", "kannst du die auch?", "die kann doch jedes kind!", NULL,
    };

    int i = 0;
    while (saetze[i] != NULL) {
        char* trans;
        trans = nachB(saetze[i]);
        printf("%s\n", trans);
        free(trans);
        i++;
    }
    exit(EXIT_SUCCESS);
}
