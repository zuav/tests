#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int         num;
    int         order;
    const char *p[];
} List;

int main()
{
    int i       = 0;
    int num     = 100;
    int numptrs = 10;

    for (i=0; i<num; ++i) {
        int j = 0;
        List *l = malloc(sizeof(char *) * numptrs + sizeof(List));

        l->num = numptrs;
        l->order = i;

        l->p[0] = "0";
        l->p[1] = "1";
        l->p[2] = "2";
        l->p[3] = "3";
        l->p[4] = "4";
        l->p[5] = "5";
        l->p[6] = "6";
        l->p[7] = "7";
        l->p[8] = "8";
        l->p[9] = "9";

        printf ("%d, %d:", l->num, l->order);

        for (j=0; j<l->num; ++j)
            printf(" %s", l->p[j]);

        printf("\n");

        free(l);
    }

    return 0;
}
