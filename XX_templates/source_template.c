// 1. includen des entsprechenden Headerfiles
#include "header_template.h"	// die "" werden benötigt da das headerfile von uns erstellt wurde



// 2. includen der benötigten framework header:
/*
Die <> Klammer werden bei Frameworkheadern verwendet. Diese zeigen dem Compiler, das die entsprechenden Header im
Bibliotheksverzeichnis des Betriebssystem liegen.
Damit Header auf diese Art aufgerufen werden können werden die Header normalerweise aus der
Betriebssystemsrepository (z.B.: durch apt-get / aptitude) installiert. Bei Windows ähnlich.

Includes werden immer in der Datei (Header/Source) durchgeführt, an der Sie als erstes tatsächlich verwendet
werden.
*/
//#include <stdio.h>



// 3. includen weiterer selbstgeschriebener header
//#include "weiterer_header.h"		// um es einfach zu halten: alle header- und sourcefiles sollten im gleichen ordner liegen



// 4. interne defines
/*
interne defines sind nur innerhalb der entsprechenden Sourcedatei sichtbar.
Falls ein anderes Modul (Source + Header) intern einen identischen (aber unterschiedliche Werte) define
bereitstellen, gibt es keine Probleme, sollte allerdings an irgend einer Stelle ausserhalb dieser Datei
ein globales define (in der Headerdatei) angelegt werden, so gibt es Probleme da der Compiler nicht weiss
welche Variante er benutzen soll.

Daher bietet sich ein Prefix mit dem Schema INTERNAL_<MODULNAME>_ an.
*/
#define INTERNAL_MODULNAME_DEFINE "Ich bin nur hier sichtbar"



// 5. globale Variablen - extern
/*
Diese Variablen sind für alle anderen Sourcedateien in unserem Programm sichtbar.
Da diese mit anderen Variablen in unserem Programm kollidieren können, muss ihnen zwingend ein einmaliger
Name gegeben werden.
Um diese Variablen ausserhalb bekannt zu machen müssen sie in unserer Headerdatei deklariert werden.

Um einen einzigartigen Namen zu gewährleisten biete sich hier das Prefix global_<modulname>_ an
*/
int global_template_counter;



// 6. globale variablen - intern
/*
Diese Variablen sind für alle in dieser Datei verwendeten Funktionen sichtbar, allerdings nicht für andere
Module unseres Programms. Da hier allerdings Probleme mit globalen Variablen entstehen können bietet sich
ein Prefix an ("internal_<modulname>_").
*/
int internal_template_counter;



// 7. Vorwärtsdeklaration interner Hilfsfunktionen:
/*
interne Vorwärsdeklarationen sind nur innerhalb der entsprechenden Sourcedatei sichtbar (können nicht von
ausserhalb verwendet werden).

WICHTIG:
Trotz dieser eingeschränkten Sichtbarkeit merkt sich der Compiler diese. Das führt dazu das er sich beim
compilieren nicht mehr auskennt welche Funktion er jetzt genau verwenden soll.

Hier bietet sich ein Prefix nach dem Schema h_<modulname>_ an. ( h = helper)
*/
void h_template_function_name1();
void h_template_function_name2();



// 8. gecodete Funktionen
/*
Diese Funktionen sollten in der Headerdatei deklariert werden. Dies führt dazu das diese Funktionen
in anderen Modulen, wie auch hier sichtbar werden.
 
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
void template_normal_function1(){
	// hier steht der Code
}

void template_normal_function2(){
	// hier steht der Code
}



// 9. gecodete Hilfsfunktionen
/*
hier coden wir die oben bereits deklarierten Hilfsfunktionen
*/
void h_template_function_name1(){
	// hier steht der Code
}

void h_template_function_name2(){
	// hier steht der Code
}
