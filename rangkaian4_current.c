//RANGKAIAN 4 - CURRENT

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void rangkaian4(double vi,double r1,double r2,double c)
{
    double t, vo[1000], dt=0.001, timeconstant=r1*r2*c/(r1+r2);
    int i;
    FILE *fp;
    char *filename = "rangkaian4_current.csv";
    fp = fopen(filename, "w+");
    vo[0]=0;
    t=0;
    fprintf(fp, "%f,", t);
    fprintf(fp, "%f\n", (vi-vo[0])/((r1*r2)/(r1+r2)));
    for(i=1;i<1000;i++)
    {
        t+=dt;
        vo[i] = (vi*dt + vo[i-1]*timeconstant)/(dt+timeconstant);
        fprintf(fp, "%f,", t);
        fprintf(fp, "%f\n", (vi-vo[i])/((r1*r2)/(r1+r2)));
    }
}

int main(int argc,char* argv[])
{
    double vi, r1, r2, c;
    char *eptr;
    vi = strtod(argv[1], &eptr);
    r1 = strtod(argv[2], &eptr);
    r2 = strtod(argv[3], &eptr);
    c = strtod(argv[4], &eptr);

    rangkaian4(vi, r1, r2, c);

    return 0;
}
