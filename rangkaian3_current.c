//RANGKAIAN 3 - CURRENT

#include <stdio.h>
#include <stdlib.h>

void rangkaian2b (double vin,double r1,double r2,double c){
    double i,vc,t;
    double dt = 0.00001;
    FILE *fp;
    char *filename = "rangkaian3_current.csv";
    fp = fopen(filename,"w");
    vc = 0;
    t = 0;
    i = vin/r1;
    fprintf(fp, "%lf,", t);
    fprintf(fp, "%lf\n", i);
    while (vin - vc >= dt){
        t += dt;
        vc += i * dt / c;
        i = (vin - vc) / r1;
        fprintf(fp, "%lf,", t);
        fprintf(fp, "%lf\n", i);
    }
   fclose(fp);
}

int main(int argc,char* argv[])
{
    double vi, r1, r2, c;
    char *eptr;
    vi = strtod(argv[1], &eptr);
    r1 = strtod(argv[2], &eptr);
    r2 = strtod(argv[3], &eptr);
    c = strtod(argv[4], &eptr);

    rangkaian2b(vi, r1, r2, c);

    return 0;
}
