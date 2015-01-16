#include <stdio.h>

// macros
#define EXIT_SUCCESS 0
#define ZEILEN 20   // erfunden, bze. aus Angabe gelesen
#define SPALTEN 15  // erfunden, bzw. aus Angabe gelesen
#define arrayAccess(array,Spalten,z,s) (*((array) + (z)*(Spalten) + (s)))


// Teilaufgabe b
void arm(char* einFeld, int zeilen, int spalten, int z, int s, int zdir, int sdir){
    if (z == 0 || z == zeilen -1 || s == 0 || s == spalten -1) return;
    
    arrayAccess(einFeld, spalten, z, s) = '*';
    // Hinweis: Zugriff muss vor rekursivem Aufruf erfolgen, damit auch die Sternmitte ein * bekommt
    arm(einFeld, zeilen, spalten, z + zdir, s + sdir, zdir, sdir);
}
// Teilaufgabe b ende

void stern(char* einFeld, int zeilen, int spalten, int z0, int s0) {
    // Zeichne die Arme des Sterns
    arm(einFeld, zeilen, spalten, z0, s0, -1, 0);   // noch oben
    arm(einFeld, zeilen, spalten, z0, s0, +1, 0);   // noch unten
    arm(einFeld, zeilen, spalten, z0, s0, 0, +1);   // noch rechts
    arm(einFeld, zeilen, spalten, z0, s0, 0, -1);   // noch links
    arm(einFeld, zeilen, spalten, z0, s0, -1, -1);   // noch links oben
    arm(einFeld, zeilen, spalten, z0, s0, +1, +1);   // noch rechts unten
    arm(einFeld, zeilen, spalten, z0, s0, -1, +1);   // noch rechts oben
    arm(einFeld, zeilen, spalten, z0, s0, +1, -1);   // noch links unten
}

// Teilaufgabe a
void ausgabe(char* einFeld, int zeilen, int spalten){
    int z = 0;
    int s = 0;
    
    for ( z = 0; z < zeilen; z++){
        for (s = 0; s < spalten; s++){
            printf("%c", arrayAccess(einFeld, spalten, z, s));
        }
        
        printf("\n");
    }
}

// Teilaufgabe c
void rahmen(char* einFeld, int zeilen, int spalten){
    int z = 0;
    int s = 0;
    
    for (z = 0; z < zeilen; z++){
        for(s = 0; s < spalten; s++) {
            if ( (z == 0 || z == zeilen -1) && (s == 0 || s == spalten - 1)){
                arrayAccess(einFeld, spalten, z , s) = '+';
            } else if (z == 0 || z == zeilen -1){
                arrayAccess(einFeld, spalten, z , s) = '-';
            } else if (s == 0 || s == spalten -1){
                arrayAccess(einFeld, spalten, z , s) = '|';
            } else {
                arrayAccess(einFeld, spalten, z , s) = ' ';
            }
        }
    }
}

int main(){
    // statisches Array lokal definieren
    char feld[ZEILEN][SPALTEN];
    
    // Ursprung des Sterns im Inneren der Figur
    int z0 = 7, s0 = 4;
    
    // Typinformation über Array vergessen, Zuweisung an void-Pointer
    void* vp_feld = feld;
    
    // Nun Array per void Pointer übergeben
    rahmen(vp_feld, ZEILEN, SPALTEN);
    stern(vp_feld, ZEILEN, SPALTEN, z0, s0);
    ausgabe(vp_feld, ZEILEN, SPALTEN);
    
    return EXIT_SUCCESS;
}