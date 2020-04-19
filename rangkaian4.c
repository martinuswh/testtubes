//rangkaian 4 martin

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void rangkaian4(double vi,double r1,double r2,double c)
{
    double t, vo[1000], dt=0.001;
    int i;
    FILE *fp;
    char *filename = "Rangkaian4.csv";
    fp = fopen(filename, "w+");
    vo[0]=0;
    t=0;
    fprintf(fp, "%f", t);
    fprintf(fp, "%f\n", vo[0]);
    for(i=1;i<1000;i++)
    {
        t+=dt;
        vo[i] = (c*vo[i-1]/dt + vi/r1)/(1/r1 + 1/r2 + c/dt);
        fprintf(fp, "%f,", t);
        fprintf(fp, "%f\n", vo[i]);
    }


}

int main(void)
{
    rangkaian4(5, 10000, 10000, 0.000001);

    return 0;
}
