/*
 * Dieses Programm ist nicht kompilierbar!
 */

#include <stdio.h>

typedef struct wort {
    char *text;
    struct wort *next;
} wort;

char f1 (wort* woerter, char* string);
char* f2 (wort** ptowort, wort* awort);
wort* f3 (char* atext, wort** ptowort);
wort* f4 (wort w, char* ptotext);
wort* f5 (wort* nextwort, char atext);

int main(void)
{
    wort w = {"Wort", NULL}, *woerter = &w;
    w.text[0] = f1(woerter, "@");
    w.text = f2(&woerter, w.next);
    w.next = f3(woerter->text, &(woerter->next));
    woerter = f4(w, woerter->text +1);
    *woerter = *f5((*woerter).next, *(w.text));
    return 0;
}
