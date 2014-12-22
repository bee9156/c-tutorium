#include <stdio.h>
#include <stdlib.h>

struct name {
    int id;
    char* name;
    double wert;
};

struct s2 {
    int id2;
    struct name n;
    int i2;
};

struct s3 {
    struct name* x;
   };

int main () {
    struct name a;
    struct name* b = malloc(1 * sizeof(struct name));
    struct s3 c;
    
    struct name e; 
    
    c.x =  &e;
    
    struct name* d;
    
    printf("%p\n", &a);
    
    d = &a;
    
    printf("%p\n", d);
    
    a.id = 1;

    b->id = 2;
    
    c.x->id = 3;
    
    printf("%d\n", a.id);
    printf("%d\n", b->id);
    printf("%d\n", c.x->id);
    printf("%d\n", d->id);
    printf("%d\n", e.id);

return 0;
}