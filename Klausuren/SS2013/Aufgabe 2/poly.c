#include <stdio.h>

#define MAX 100
#define ENDE 99999999

void polyadd(double* r, double* p, double* q)
{
    int i;

    for (i = 0; i <= MAX - 1; i++){
        if (p[i] != ENDE){
            r[i] = p[i];
        } else {
            r[i] = ENDE;
        }
    }

    for (i = 0; i <= MAX -1 && q[i] != ENDE; i++) {
        if (r[i] != ENDE) {
            r[i] += q[i];
        } else {
            r[i] = q[i];
        }
    }
}

void polyprint(double* pol)
{
    int i;
    for (i = 0; i <= MAX -1 && pol[i] != ENDE; i++){
        printf("%.1f   ", pol[i]);
    }

    printf("\n");
}

double f(double* poly, int n)
{
    double result = poly[0];

    int i, j=1;
    for (i = 1; i <= MAX - 1 && poly[i] != ENDE; i++){
        j*=n;
        result += (poly[i] * j);
    }

    return result;
}

int main(void)
{
    double p[] = {1, 2, 0, -3, ENDE};
    double q[] = {2, -1 , ENDE};
    double r[MAX];

    polyadd (r, p, q);
    polyprint(r);
    printf("p(2) = %.1f\n", f(p, 2));
    return 0;
}
