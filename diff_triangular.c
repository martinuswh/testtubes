//DIFFERENTIATOR SIMULATOR FOR TRIANGULAR WAVES INPUT

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265359

double T,A, R, C, dt=0.001;

double derive(double (*f)(double t, double T, double A), double x0, double R, double C)
{
    const double delta = 1.0e-10; // or similar
    double x1 = x0;
    double x2 = x0 + delta;
    double y1 = f(x1,T,A);
    double y2 = f(x2,T,A);
    return R*C*((y2 - y1) / delta);
};

double triangluarFunc(double t, double T, double A)        //triangle
{
    int region;
    region=t/(T/2);

    if(t>=0 && t<=(T/2))
        return ((2*A/T)*t);
    else if(t>(T/2) && t<=T)
        return ((2*A/T)*(-(t-T)));
    else
    {
        if(region%2==0)
            return((2*A/T)*(t-(T/2)*region));
        else if(region%2==1)
            return (-(2*A/T)*(t-(T/2)*region) + A);
    };
};

void printToFile(FILE *fp, int x, double y)
{
    fprintf(fp, "%f,", (x*dt));
    fprintf(fp, "%f\n", y);
};

int main(int argc, char *argv[])
{
    int i;
    double Vi[20000], Vo[20000], t=0;

    char *eptr;
    A = strtod(argv[1], &eptr);
    T = strtod(argv[2], &eptr);
    R = strtod(argv[3], &eptr);
    C = strtod(argv[4], &eptr);

    FILE *fp1, *fp2;
    fp1 = fopen("input_voltage_triangular.csv", "w+");
    fp2 = fopen("output_voltage_triangular.csv", "w+");

    Vi[0]=0;
    fprintf(fp1, "%f,", 0);
    fprintf(fp1, "%f\n", Vi[0]);

    Vi[0]=0;
    fprintf(fp1, "%f,", 0);
    fprintf(fp1, "%f\n", Vi[0]);

    for(i=1;i<20000;i++)
    {
        t=t+dt;
        Vi[i] = triangluarFunc(t, T,A);
        printToFile(fp1, i, Vi[i]);
    };

    t=0;
    for(i=0;i<20000;i++)
    {
        Vo[i] = derive(triangluarFunc, t, R, C);
        printToFile(fp2, i, Vo[i]);
        t=t+dt;
    };

    fclose(fp1);
    fclose(fp2);

    return 0;
};
