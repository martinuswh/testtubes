//RANGKAIAN 2 - CURRENT

#include <stdio.h>
#include <stdlib.h>


void rangkaian2 (double vin,double r1,double r2,double c){
    double t,i,vc;
    int j;
    double dt = 0.001;
    FILE *fp;
    char *filename = "rangkaian2_current.csv";
    fp = fopen(filename,"w+");
    vc = 0;
    t = 0 ;
    i = vin/r1;
    fprintf(fp, "%f,", t);
    fprintf(fp, "%f\n", vc);
    for (j=0;j<1000;j++){
        t += dt;
        fprintf(fp, "%f,", t);
        fprintf(fp, "%f\n", vc);
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

    rangkaian2(vi, r1, r2, c);

    return 0;
}
