// 1. includen des entsprechenden Headerfiles
#include "header_template.h"	// die "" werden benötigt da das headerfile von uns erstellt wurde

// 2. includen der benötigten framework header:
/*
Die <> Klammer werden bei Frameworkheadern verwendet. Diese zeigen dem Compiler, das die entsprechenden Header im Bibliotheksverzeichnis des Betriebssystem liegen.
Damit Header auf diese Art aufgerufen werden können werden die Header normalerweise aus der Betriebssystemsrepository (z.B.: durch apt-get / aptitude) installiert. Bei Windows ähnlich.

Includes werden immer in der Datei (Header/Source) durchgeführt, an der Sie als erstes tatsächlich verwendet werden.
*/
//#include <stdio.h>

// 3. includen weiterer selbstgeschriebener header
//#include "weiterer_header.h"		// um es einfach zu halten: alle header- und sourcefiles sollten im gleichen ordner liegen

// 4. interne defines
/*
interne defines sind nur innerhalb der entsprechenden Sourcedatei sichtbar. Da beim compilieren die Daten nur innerhalb verwendet werden, sollten!!!!!! keine Probleme bei einem erneuten define mit identischem Namen, aber unterschiedlichem Wert entstehen.
*/
#define INTERNAL_DEFINE "Ich bin nur hier sichtbar"

// 5. intern - globale variablen
/*
Diese Variablen sind für alle in dieser Datei verwendeten Funktionen sichtbar, bzw. können von diesen geändert
werden.
Da hier allerdings Probleme mit globalen Variablen entstehen können bietet sich ein Prefix an ("internal_")
Soll eine Variable komplett global zugänglich sein, so sollte diese in der Headerdatei anstelle hier
hinterlegt werden.
*/
int internal_counter;

// 6. Vorwärtsdeklaration interner Hilfsfunktionen:
/*
interne Vorwärsdeklarationen sind nur innerhalb der entsprechenden Sourcedatei sichtbar (kann nicht von ausserhalb verwendet werden).

WICHTIG:
Anders als bei internen Defines entstehen bei Mehrfachverwendung in verschiedenen Dateien Probleme beim Verlinkungsvorgang beim compilieren!!!

Ein möglicher Work-Around dafür ist die Nutzung eines Prefixes (z.b.: die Anfangsbuchstaben der Sourcedate - st_):
*/
void st_function_name1();
void st_function_name2();

// 7. gecodete Funktionen (aus headerdatei)
/*
Um die Lesbarkeit zu verbessern bietet es sich an die Funktionen thematisch auszuteilen.
Bsp.:
// initialisierung & Speicherkram;
void init_me();
void init_two();
void free_me();
void free_two();

// ausführende Funktionen
void do_something();
void do_something_else();

// andere Funktionen
.
.
.
 
*/
void normal_function1(){
	// hier steht der Code
}

void normal_function2(){
	// hier steht der Code
}

// 8. gecodete Hilfsfunktionen
void st_function_name1(){
	// hier steht der Code
}

void st_function_name2(){
	// hier steht der Code
}
