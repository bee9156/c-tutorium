#include <stdio.h>

#define TAGE 5
#define STUNDEN 10

typedef struct {
    char* name;
    int anzahl;
    int belegt[TAGE][STUNDEN];
} Laborplaner;

enum Wochentag {MO, DI, MI, DO, FR};

void belege(Laborplaner* lab, enum Wochentag tag, int zeit, int angefragt){
    lab->belegt[tag][zeit-8] += angefragt;
    
    if (lab->belegt[tag][zeit-8] > lab->anzahl){
        lab->belegt[tag][zeit-8] = lab->anzahl;
    }
}

void drucke(Laborplaner lab) {
    int i = 0;
    int j = 0;
    
    for (i = 0; i<5 && lab.name[i] != '\0'; i++){
        printf("%c", lab.name[i]);
    }
    
    for (; i < 5; i++) {
        printf(" ");
    }

    printf("  MO DI MI DO FR\n");
    
    for (i = 8; i < 18; i++) {
        printf("%02d:00  ", i);
        
        for (j = 0; j < TAGE; j++) {
            printf("%2d ", lab.belegt[j][i-8]);
        }
        
        // hier komplette zeile fertig
        printf("\n");
    }
    
}

int main() {
    Laborplaner lab = {"Mechatronik", 18, {}};
    belege(&lab, DO, 9, 6);
    belege(&lab, DO, 9, 14);
    belege(&lab, FR, 14, 15);
    
    drucke(lab);

    return 0;
}