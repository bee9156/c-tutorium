#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 10

void drucke(...)
{

}

void freigabe(...)
{

}

void add(...)
{

}

int main(void)
{
    char* helden[MAX_NUM+1];

    helden[0] = NULL;

    add(helden, "Frodo Beutlin", MAX_NUM+1);
    add(helden, "Luke Skywalker", MAX_NUM+1);
    add(helden, "Harry Potter", MAX_NUM+1);
    add(helden, "Eragon", MAX_NUM+1);

    drucke(helden);
    freigabe(helden);

    return 0;
}