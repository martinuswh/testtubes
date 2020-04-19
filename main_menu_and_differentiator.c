#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265359

double T,A, R, C, angular_freq;

double derive(double (*f)(double t, double T, double A), double x0, double R, double C)
{
    const double delta = 1.0e-10; // or similar
    double x1 = x0;
    double x2 = x0 + delta;
    double y1 = f(x1,T,A);
    double y2 = f(x2,T,A);
    return R*C*((y2 - y1) / delta);
};

double deriveTrig(double (*f)(double t), double x0)
{
    const double delta = 1.0e-10;
    double x1 = x0;
    double x2 = x0 +delta;
    double y1 = f(x1);
    double y2 = f(x2);
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

int main(void)
{
    int quit=0, choice, i;
    double Vi[1000], Vo[1000], t=0, dt=0.01;

    FILE *fp1, *fp2;
    fp1 = fopen("input_voltage.csv", "w+");
    fp2 = fopen("output_voltage.csv", "w+");

    printf("-----PROGRAM SIMULASI RANGKAIAN OP-AMP DIFFERENSIATOR OLEH KELOMPOK 2-----\n");
    printf("Program merupakan program simulasi rangkaian op-amp differentiator orde 1\n");
    printf("yang terdiri dari resistor dan kapasitor. User akan diminta untuk menginput\n");
    printf("nilai masing-masing komponen serta jenis gelombang tegangan input. Terdapat\n");
    printf("empat jenis gelombang input yaitu gelombang sinus, cosinus, segitiga, dan persegi.\n");
    printf("User juga akan diminta untuk menginput amplitudo dan periode masing-masing gelombang.\n");
    printf("Sebagai output, program akan menampilkan grafik tegangan input dan output.\n\n");

    while(quit==0)
    {
        printf("Silakan masukkan nilai resistansi resistor (dalam ohm): "); scanf("%lf", &R);
        printf("Silakan masukkan nilai kapasitansi kapasitor (dalam Farrat): "); scanf("%lf", &C);
        printf("Silakan masukkan periode gelombang: "); scanf("%lf", &T);
        printf("Silakan masukkan amplitudo gelombang: "); scanf("%lf", &A);

        printf("\nPilih jenis gelombang input:\n");
        printf("1. Sinus\n");
        printf("2. Cosinus\n");
        printf("3. Segitiga\n");
        printf("4. Kotak\n");
        printf("5. Keluar dari program\n");         //not implemented

        printf("\nSilakan masukkan jenis gelombang tegangan input: "); scanf("%d", &choice);

        if(choice==5)
        {
            quit=1;
        };

        while((choice!=5) && (quit!=1))
        {
            if(choice==1)               //sinus
            {
                printf("Gelombang yang dipilih merupakan gelombang sinus, tegangan input dan output akan muncul pada file.csv\n");
                Vi[0]=0;
                angular_freq= 2.0*pi/T;
                fprintf(fp1, "%f,", 0);
                fprintf(fp1, "%f\n", Vi[0]);

                for(i=1;i<1000;i++)
                {
                    t=t+dt;
                    Vi[i] = A*sin(angular_freq*t);
                    printToFile(fp1, i, Vi[i]);
                };

                t=0;
                for(i=0;i<1000;i++)
                {
                    Vo[i] = A*deriveTrig(sin, angular_freq*t);
                    printToFile(fp2, i, Vo[i]);
                    t=t+dt;
                };
            }
            else if(choice==2)          //cosinus
            {
                printf("Gelombang yang dipilih merupakan gelombang cosinus, tegangan input dan output akan muncul pada file.csv\n");
                Vi[0]=0;
                angular_freq= 2.0*pi/T;
                fprintf(fp1, "%f,", 0);
                fprintf(fp1, "%f\n", Vi[0]);

                for(i=1;i<1000;i++)
                {
                    t=t+dt;
                    Vi[i] = A*cos(angular_freq*t);
                    printToFile(fp1, i, Vi[i]);
                };

                t=0;
                for(i=0;i<1000;i++)
                {
                    Vo[i] = A*deriveTrig(cos, angular_freq*t);
                    printToFile(fp2, i, Vo[i]);
                    t=t+dt;
                };
            }
            else if(choice==3)          //segitiga
            {
                printf("Gelombang yang dipilih merupakan gelombang segitiga, tegangan input dan output akan muncul pada file.csv\n");
                Vi[0]=0;
                fprintf(fp1, "%f,", 0);
                fprintf(fp1, "%f\n", Vi[0]);

                for(i=1;i<1000;i++)
                {
                    t=t+dt;
                    Vi[i] = triangluarFunc(t, T,A);
                    printToFile(fp1, i, Vi[i]);
                };

                t=0;
                for(i=0;i<1000;i++)
                {
                    Vo[i] = derive(triangluarFunc, t, R, C);
                    printToFile(fp2, i, Vo[i]);
                    t=t+dt;
                };
            }
            else if(choice==4)          //kotak
            {
                printf("Gelombang yang dipilih merupakan gelombang kotak, tegangan input dan output akan muncul pada file.csv\n");
                Vi[0]=A;
                fprintf(fp1, "%f,", 0);
                fprintf(fp1, "%f\n", Vi[0]);

                for(i=1;i<1000;i++)
                {
                    t=t+dt;
                    Vi[i] = squareFunc(t, T,A);
                    printToFile(fp1, i, Vi[i]);
                };

                t=0;
                for(i=0;i<1000;i++)
                {
                    Vo[i] = derive(squareFunc, t, R, C);
                    printToFile(fp2, i, Vo[i]);
                    t=t+dt;
                };
            }
            else        //input choice ulang
            {
                printf("Input salah silakan input ulang.\n");
            };
            printf("\nSilakan masukkan jenis gelombang tegangan input: "); scanf("%d", &choice);
        };

        printf("Apakah user ingin keluar dari program atau melakukan simulasi dengan nilai komponen lain? (1/0): "); scanf("%d", &quit);




        fclose(fp1);
        fclose(fp2);
    };

    return 0;
};
