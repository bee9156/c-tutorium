// 1. Include Schutz
#ifndef _TEMPLATE_H
#define _TEMPLATE_H
/*
Der include Schutz dient dazu das eine Headerdatei maximal einmal eingebunden wird.
Ein mehrmaliges einbinden verursacht den Fehler "multiple definitions of.....", da die Daten bereits vorhanden sind.

_TEMPLATE_H ist ein eindeutiger Name. Es handelt sich hier um eine globale Definierung mit entsprechendem Namen,
aber ohne Inhalt (der wird aber auch nicht benötigt).
*/



// 2. Include der in dieser Headerdatei benötigten Frameworkheader (z.B. Datentypen)
// Erklärung: siehe source_template.c
//#include <...>



// 3. Include der in dieser Headerdatei benötigten selbst geschriebenen Header (z.B.: typedefs, structs, etc)
// Erklärung: siehe source_template.c
//# include "..."



// 4. Globale defines
/*
Diese Defines sind global (von allen anderen externen Source und Headerdateien) sichtbar.
Anwendungsbeispiele:
* global benötigte Puffergrößen
* global benötigte Zählergrößen, etc

Da diese Defines überall sichtbar sind, könnten Probleme mit gleichnamigen internen defines entstehen.
Um dies zu vermeiden (und der besseren Lesbarkeit halber) bietet es sich an den Prefix "GLOBAL_" zu
verwenden. Global sichtbare defines müssen einen eindeutigen Namen besitzen und dürfen nur einmal erstellt werden!!!
Unbedingt sinnvolle und einzigartige Namen vergeben!
*/
#define GLOBAL_MODULNAME_DEFINE "ich bin überall Sichtbar"



// 5. Globale Variablen
/*
Da in Headerdateien Varaiablen eig nichts zu suchen haben machen wir hier nur unsere in der Sourcedatei
angelegten globalen Variablen für alle sichtbar
*/
extern int global_template_counter;



// 6. öffentliche Funktionen der .c Datei (können extern verwendet werden)
/*
Alle hier denklarierten Funktionen sind global sichtbar (Erklärung: siehe Sourcedatei)

Für eine gute Lesbarkeit bietet sich eine thematische Aufteilung an. Die Reihenfolge ist hier ziemlich
egal und kann sich von der Sourcedatei unterscheiden - auch wenn es sinnvoll ist die gleiche Reihenfolge
zu verwenden.

Beispiel einer Aufteilung: source_template.c
 
Die Name, Parameter und Rückgabewerte müssen identisch zu der Funktionsdefinition in der Sourcedatei sein,
sonst wird die hier angelegte Funktion als eigenständig betrachtet
*/
void template_normal_function1();
void template_normal_function2();

// Ende des Include Schutzes
#endif
