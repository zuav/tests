#include <stdio.h>
#include <complex.h>

/* double complex global_var = 1.0 + 1.0*I; */
/* double complex global_res; */

int main()
{
    double complex localvar = 1.0 + 1.0*I;
    double complex localres;

    localres = cexp(localvar);
    printf("local cexp: %e + %ei\n", creal(localres), cimag(localres));

    /* global_res = csin(global_var); */
    /* printf("global csin: %e + %ei\n", creal(global_res), cimag(global_res)); */

    return 0;
}
