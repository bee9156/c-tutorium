#include <stdlib.h>
struct elem {
    char* s;
    struct elem *next;
};

int* f1(char* c);
struct elem f2(char* c);
struct elem* f3(struct elem* nextelem);
void f4(char c, struct elem** nextelem);
char* f5(char** c, int* c2);

int main(void) {
    char c;
    int *s = f1(&c);
    struct elem n[] = {{"xyz", NULL}, f2("def"), {"abc", NULL}};
    n[1].next = &n[0];
    char *p = f3(n[1].next)->s;
    f4(*p, &(n[2].next));
    n[0].s = f5(&(n[0].s), s);
    return 0;
}
