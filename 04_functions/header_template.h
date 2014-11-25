// 1. Include Schutz
#ifndef _TEMPLATE_H
#define _TEMPLATE_H
/*
Der include Schutz dient dazu das eine Headerdatei maximal einmal eingebunden wird.
Ein mehrmaliges einbinden verursacht den Fehler "multiple definitions of.....", da die Daten bereits vorhanden sind.

_TEMPLATE_H ist ein eindeutiger Name. Es handelt sich hier um eine globale Definierung mit entsprechendem Namen,
aber ohne Inhalt (der wird aber auch nicht benötigt).
*/

// 2. Include der in dieser Datei benötigten Frameworkheader (z.B. Datentypen)
// Erklärung: siehe source_template.c
//#include <...>

// 3. Include der in dieser Datei benötigten selbst geschriebenen Header (z.B.: typedefs, structs, etc)
// Erklärung: siehe source_template.c
//# include "..."

// 4. Globale defines
/*
Diese Defines sind global (von allen anderen externen Source und Headerdateien) sichtbar.
Anwendungsbeispiele:
* global benötigte Puffergrößen
* global benötigte Konstanten anderer Art

Da diese Defines überall sichtbar sind, könnten Probleme mit gleichnamigen internen defines entstehen.
Um dies zu vermeiden (und der besseren Lesbarkeit halber) bietet es sich an den Prefix "GLOBAL_" zu
verwenden. Global sichtbare defines müssen einen eindeutigen Namen besitzen und dürfen nur einmal erstellt werden!!!
Unbedingt sinnvolle und einzigartige Namen vergeben!
*/
#define GLOBAL_DEFINE "ich bin überall Sichtbar"

// 5. Globale Variablen
/*
Diese Variablen sind global sicht und müssen daher einen eindeutigen Namen besitzen.
Sie können von extern verändert werden.

Um einen besser lesbaren Code zu schreiben, sollten diese mit dem Prefix "global_" versehen werden.
*/
int global_counter;

// 6. Globale Bekanntmachung von Variablen, welche in der eigenen Sourcedatei angelegt wurden.
// Erklärung: source_template.c
// Hinweis: sehr unsauberes Coding, dies sollte vermieden werden!!!
extern int internal_counter;

// 7. öffentliche Funktionen der .c Datei (können extern verwendet werden)
/*
Alle hier beschriebenen Funktionen sind global sichtbar, daher muss auch hier ein eindeutiger
Name vergeben werden.

Für eine gute Lesbarkeit bietet sich eine thematische Aufteilung an. Die Reihenfolge ist hier ziemlich
egal und kann sich von der Sourcedatei unterscheiden - auch wenn es sinnvoll ist die gleiche Reihenfolge
zu verwenden.

Beispiel einer Aufteilung: source_template.c
*/
void normal_function1();
void normal_function2();

// Ende des Include Schutzes
#endif
