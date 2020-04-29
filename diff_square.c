//DIFFERENTIATOR SIMULATOR FOR SQUARE WAVES INPUT
/*
    Program akan menerima input berupa command line argument yang diinvoke oleh file top_simulator.py
    Output program adalh file input_voltage_square.csv, output_voltage_square.csv, dan output_current_square.csv
*/

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
    return -R*C*((y2 - y1) / delta);
};

double squareFunc(double t, double T, double A)        //kotak
{
    int region;
    region=t/(T/2);

    if(t>=0 && t<=(T/2))
        return A;
    else if(t>(T/2) && t<=T)
        return -A;
    else
    {
        if(region%2==0)
            return A;
        else if(region%2==1)
            return -A;
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

    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("input_voltage_square.csv", "w+");
    fp2 = fopen("output_voltage_square.csv", "w+");
    fp3 = fopen("output_current_square.csv", "w+");

    Vi[0]=A;
    fprintf(fp1, "%f,", 0);
    fprintf(fp1, "%f\n", Vi[0]);

    for(i=1;i<20000;i++)
    {
        t=t+dt;
        Vi[i] = squareFunc(t, T,A);
        printToFile(fp1, i, Vi[i]);
    };

    t=0;
    for(i=0;i<20000;i++)
    {
        Vo[i] = derive(squareFunc, t, R, C);
        printToFile(fp2, i, Vo[i]);
        printToFile(fp3, i, (Vo[i]/R));
        t=t+dt;
    };

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
};

