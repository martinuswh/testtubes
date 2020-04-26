//DIFFERENTIATOR SIMULATOR FOR COSINUSOIDAL WAVES INPUT

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265359

double T,A, R, C, angular_freq, dt=0.001;

double deriveTrig(double (*f)(double t), double x0)
{
    const double delta = 1.0e-10;
    double x1 = x0;
    double x2 = x0 +delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return R*C*((y2 - y1) / delta);
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

    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("input_voltage_cosinus.csv", "w+");
    fp2 = fopen("output_voltage_cosinus.csv", "w+");
    fp3 = fopen("output_current_cosinus.csv", "w+");

    Vi[0]=0;
    angular_freq= 2.0*pi/T;
    fprintf(fp1, "%f,", 0);
    fprintf(fp1, "%f\n", Vi[0]);

    for(i=1;i<20000;i++)
    {
        t=t+dt;
        Vi[i] = A*cos(angular_freq*t);
        printToFile(fp1, i, Vi[i]);
    };

    t=0;
    for(i=0;i<20000;i++)
    {
        Vo[i] = A*deriveTrig(cos, angular_freq*t);
        printToFile(fp2, i, Vo[i]);
        printToFile(fp3, i, (Vo[i]/R));
        t=t+dt;
    };

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
};
