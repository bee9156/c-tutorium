#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void split(char** woerter, char* thestring)
{
    char buff[MAX];
    int charorig, chartarget = 0, wort = 0;
    for(charorig = 0; charorig < strlen(thestring); charorig++){
        if (isalpha(thestring[charorig])) {
            buff[chartarget] = thestring[charorig];
            chartarget++;
        } else {
            buff[chartarget] = '\0';
            woerter[wort] = strdup(buff);
            if (strlen (buff) > 0) wort++;
            chartarget = 0;
        }
    }
    woerter[wort +1] = NULL;
}

int main(void)
{
    char*woerter[MAX];
    int i;

    split(woerter, "Das ist ein (ganz) kleines, feines Beispiel!");

    for (i = 0; woerter[i] != NULL; i++){
        printf("%s\n", woerter[i]);
    }

    return 0;
}
