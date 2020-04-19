#include <stdio.h>
#include <stdlib.h>




void rangkaian2b (double vin,double r1,double r2,double c){
    double i,vc,t;
    double dt = 0.00001;
    FILE *fp;
    char *filename = "Rangkaian2b.csv";
    fp = fopen(filename,"w");
    vc = 0;
    t = 0;
    i = vin/r1;
    fprintf(fp, "%lf,", t);
    fprintf(fp, "%lf\n", vc);
    while (vin - vc >= dt){
        t += dt;
        vc += i * dt / c;
        i = (vin - vc) / r1;
        printf("%lf\n",vc);
        fprintf(fp, "%lf,", t);
        fprintf(fp, "%lf\n", vc);
    }
   fclose(fp);
}

void rangkaian2a (double vin,double r1,double r2,double c){
    double t,i,vc;
    int j;
    double dt = 0.00001;
    FILE *fp;
    char *filename = "Rangkaian2a.csv";
    fp = fopen(filename,"w");
    vc = 0;
    t = 0 ;
    i = vin/r1;
    fprintf(fp, "%lf,", t);
    fprintf(fp, "%lf\n", vc);
    for (j=0;j<1000;j++){
        vc = 10;
        t += dt;
        printf("%lf\n",vc);
        fprintf(fp, "%lf\n", vc);
        fprintf(fp, "%lf,", t);
    }
   fclose(fp);
}

int main(){
    printf("Hasil Output rangkaian 2a\n");
    rangkaian2a(10,1000,1000,0.000001);
    printf(" \n");
    printf("Hasil Output rangkaian 2b\n");
    rangkaian2b(10,1000,1000,0.000001);

}
