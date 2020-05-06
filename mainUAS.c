#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct penduduk
{
    int No;
    char NIK[20];
    char NamaLengkap[50];
    char TempatLahir[20];
    char TanggalLahir[20];
    int Umur;
    char JenisKelamin[20];
    char GolonganDarah[20];
    char Status[20];
    char Pekerjaan[20];
}dataP[1000], buffer_dataP[1000], dataPB;
int i, j, quit=0;

FILE *fp, *fpmerge;
struct penduduk dataP[1000];
char buf[1024], *field, filename[30], filename_merge[30], buff_year[10], buff_string[50], buffer[1024];
int value, data_length, data_length_buffer, choice, current_year, born_year, buff_int, n;

void assignExternalToArray(FILE *fp);
void printData(struct penduduk dataP[1000], int data_length);
void updateUmur(struct penduduk dataP[1000], int current_year);
void create(struct penduduk dataP[1000]);
void printData2(struct penduduk dataP[30], int i);
void search(struct penduduk dataP[1000]);
void update(struct penduduk dataP[1000]);
void deleteData(struct penduduk dataP[1000]);
void importMerge(struct penduduk dataP[1000]);
void sort(struct penduduk dataP[1000]);

int main(void)
{
    printf("--------------------------------------------------PROGRAM PENCATATAN DATA KEPENDUDUKAN--------------------------------------------------\n");
    printf("----------------------------------Dirancang sebagai kode program UAS EL2008 Pemecahan Masalah dengan C----------------------------------\n");
    printf("----------------------------------------------Oleh Martinus William Hartono/13218044/PMC 02---------------------------------------------\n\n");
    printf("Program ini merupakan program yang digunakan untuk melakukan pencatatan kependudukan. Secara umum, pada data seluruh penduduk akan disimpan\n");
    printf("dalam bentuk Comma Seperated Value (.csv). Terdapat beberapa komponen yang akan dicatat pada database, yaitu Nomor Induk Kependudukan (NIK),\n");
    printf("Nama Lengkap, Tempat Lahir, Tanggal Lahir, Umur, Jenis Kelamin (L/P), Golongan Darah, Status Perkawinan, dan Pekerjaan. Program ini mempunyai\n");
    printf("beberapa fitur yang dapat digunakan oleh user, yaitu create, update, delete, import (merge), searching, dan sorting data.\n\n");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Tanggal hari ini: %02d-%02d-%d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    current_year = tm.tm_year + 1900;

    while(quit==0)
    {
        printf("\nSilakan Masukkan File Data Penduduk (.csv) : ");scanf(" %[^\n]s", &filename);
        fp = fopen(filename, "r");
        printf("\n\n");

        assignExternalToArray(fp);
        fclose(fp);

        printData(dataP, data_length);

        printf("\n\nFile Data Penduduk telah berhasil di-load dan di-assign ke dalam array.\n");
        printf("Pilih operasi yang akan dilakukan pada data:\n");
        printf("1. Create (Menambahkan data pada database penduduk)\n");
        printf("2. Update (Mengganti datum yang sudah ada dengan datum baru)\n");
        printf("3. Delete (Menghapus satu baris data)\n");
        printf("4. Import (Melakukan append data dengan data dari file .csv lain)\n");
        printf("5. Search (Mencari data dengan parameter variabel yang diinginkan)\n");
        printf("6. Sorting (Mengurutkan data secara membesar atau mengecil)\n");
        printf("7. Show (Menampilkan data pada array)\n");
        printf("99. Quit atau Masukkan File Lain (Keluar dari program)\n");

        printf("\nMasukkan pilihan: ");scanf("%d", &choice);

        if(choice == 99)
            quit=1;

        while((choice!=99) && (quit!=1))
        {
            if(choice==1)
            {
                create(dataP);
                printData(dataP, data_length);
            }
            else if(choice==2)
            {
                update(dataP);
            }
            else if(choice==3)
            {
                deleteData(dataP);
            }
            else if(choice==4)
            {
                importMerge(dataP);
            }
            else if(choice==5)
            {
                search(dataP);
            }
            else if(choice==6)
            {
                sort(dataP);
            }
            else if(choice==7)
            {
                printData(dataP, data_length);
            }
            else
            {
                printf("Input salah, silakan input ulang.\n");
            };
            printf("\n\nMasukkan pilihan: "); scanf("%d", &choice);
        };
        fp = fopen(filename, "w+");
        for(i=0;i<data_length;i++)
        {
            fprintf(fp, "%d;%s;%s;%s;%s;%d;%s;%s;%s;%s\n", i+1, dataP[i].NIK, dataP[i].NamaLengkap, dataP[i].TempatLahir, dataP[i].TanggalLahir, dataP[i].Umur, dataP[i].JenisKelamin, dataP[i].GolonganDarah, dataP[i].Status, dataP[i].Pekerjaan);
        }
        fclose(fp);
        printf("Progress tersimpan. Apakah Anda mau keluar atau pilih filename lain? (1/0):");scanf("%d", &quit);
    };
    return 0;
};

void assignExternalToArray(FILE *fp)
{
    i=0;
    i=j-1;
    char buffer[1000];
    while(fgets(buf, 1024, fp))
    {
        if(j=0)
        {
            continue;
        }
        else
        {
            strcpy(buffer, strtok(buf, ";"));
            dataP[i].No = atoi(buffer);
            strcpy(dataP[i].NIK, strtok(NULL, ";"));
            strcpy(dataP[i].NamaLengkap, strtok(NULL, ";"));
            strcpy(dataP[i].TempatLahir, strtok(NULL, ";"));
            strcpy(dataP[i].TanggalLahir, strtok(NULL, ";"));
            strcpy(buffer, strtok(NULL, ";"));
            dataP[i].Umur = atoi(buffer);
            strcpy(dataP[i].JenisKelamin, strtok(NULL, ";"));
            strcpy(dataP[i].GolonganDarah, strtok(NULL, ";"));
            strcpy(dataP[i].Status, strtok(NULL, ";"));
            strcpy(dataP[i].Pekerjaan, strtok(NULL, ";"));
        }
        i++;
    }
    data_length = i;
}

void updateUmur(struct penduduk dataP[1000], int current_year)
{
    for(i=0;i<data_length;i++)
    {
        strcpy(buff_year, "");
        strncat(buff_year, &dataP[i].TanggalLahir[4],1);
        strncat(buff_year, &dataP[i].TanggalLahir[5],1);
        strncat(buff_year, &dataP[i].TanggalLahir[6],1);
        strncat(buff_year, &dataP[i].TanggalLahir[7],1);
        born_year = atoi(buff_year);
        dataP[i].Umur = current_year - born_year;
    };
}

void printData(struct penduduk dataP[30], int data_length)
{
    updateUmur(dataP, current_year);
    printf("No\tNIK\t\tNama Lengkap\tTempat Lahir\t\tTanggal Lahir\tUmur\tJK\tGol.\tStatus\t\tPekerjaan\n");
    for(i=0;i<data_length;i++)
    {
        printf("%d\t", i+1);
        printf("%s\t", dataP[i].NIK);
        printf("%s\t", dataP[i].NamaLengkap);
        if(strlen(dataP[i].TempatLahir)>=16)
            printf("%s\t", dataP[i].TempatLahir);
        else if(strlen(dataP[i].TempatLahir)>=8)
            printf("%s\t\t", dataP[i].TempatLahir);
        else
            printf("%s\t\t\t", dataP[i].TempatLahir);
        printf("%s\t", dataP[i].TanggalLahir);
        printf("%d\t", dataP[i].Umur);
        printf("%s\t", dataP[i].JenisKelamin);
        printf("%s\t", dataP[i].GolonganDarah);
        if(strlen(dataP[i].Status)>=10)
            printf("%s\t", dataP[i].Status);
        else
            printf("%s\t\t", dataP[i].Status);
        printf("%s\n", dataP[i].Pekerjaan);
    }
}

void printData2(struct penduduk dataP[30], int i)
{
    printf("%d\t", i+1);
    printf("%s\t", dataP[i].NIK);
    printf("%s\t", dataP[i].NamaLengkap);
    if(strlen(dataP[i].TempatLahir)>=16)
        printf("%s\t", dataP[i].TempatLahir);
    else if(strlen(dataP[i].TempatLahir)>=8)
        printf("%s\t\t", dataP[i].TempatLahir);
    else
        printf("%s\t\t\t", dataP[i].TempatLahir);
    printf("%s\t", dataP[i].TanggalLahir);
    printf("%d\t", dataP[i].Umur);
    printf("%s\t", dataP[i].JenisKelamin);
    printf("%s\t", dataP[i].GolonganDarah);
    if(strlen(dataP[i].Status)>=10)
        printf("%s\t", dataP[i].Status);
    else
        printf("%s\t\t", dataP[i].Status);
    printf("%s\n", dataP[i].Pekerjaan);
}

void create(struct penduduk dataP[1000])
{
    printf("\nAnda telah memilih opsi create (Menambahkan data pada database)\n");
    printf("Masukkan jumlah data yang ingin ditambah:"); scanf("%d", &n);
    j=data_length;
    for(i=j;i<(j+n);i++)
    {
        printf("\nSilakan isi form di bawah ini untuk menambahkan data menjadi data ke-%d:\n", j+1);
        dataP[data_length].No=j+1;
        printf("NIK             : ");scanf(" %[^\n]s", &dataP[data_length].NIK);
        printf("Nama Lengkap    : ");scanf(" %[^\n]s", &dataP[data_length].NamaLengkap);
        printf("Tempat Lahir    : ");scanf(" %[^\n]s", &dataP[data_length].TempatLahir);
        printf("Tanggal Lahir   : ");scanf(" %[^\n]s", &dataP[data_length].TanggalLahir);
        printf("Umur            : ");scanf("%d", &dataP[data_length].Umur);
        printf("Jenis Kelamin   : ");scanf(" %[^\n]s", &dataP[data_length].JenisKelamin);
        printf("Golongan Darah  : ");scanf(" %[^\n]s", &dataP[data_length].GolonganDarah);
        printf("Status          : ");scanf(" %[^\n]s", &dataP[data_length].Status);
        printf("Pekerjaan       : ");scanf(" %[^\n]s", &dataP[data_length].Pekerjaan);

        data_length++;
    }
}

void search(struct penduduk dataP[1000])
{
    printf("\nAnda telah memilih opsi search (Mencari data)\n");
    printf("\nSilakan input kategori yang ingin dicari:\n");
    printf("   1. NIK\n");
    printf("   2. Nama Lengkap\n");
    printf("   3. Tempat Lahir\n");
    printf("   4. Tanggal Lahir\n");
    printf("   5. Umur\n");
    printf("   6. Jenis Kelamin\n");
    printf("   7. Golongan Darah\n");
    printf("   8. Status\n");
    printf("   9. Pekerjaan\n\n");
    printf("Masukkan jenis data yang ingin dicari: ");scanf("%d", &n);
    while (!(n>=1 && n<=9))
    {
        printf("Input salah silakan input ulang\n");
        printf("\nMasukkan jenis data yang ingin dicari: ");scanf("%d", &n);
    }
    printf("\n");
    if(n==1)
    {
        printf("Masukkan NIK yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].NIK, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==2)
    {
        printf("Masukkan Nama Lengkap yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].NamaLengkap, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==3)
    {
        printf("Masukkan Tempat Lahir yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].TempatLahir, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==4)
    {
        printf("Masukkan Tanggal Lahir yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].TanggalLahir, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==5)
    {
        printf("Masukkan Umur yang ingin dicari: "); scanf("%d", &buff_int);
        for(i=0;i<data_length;i++)
        {
            if(dataP[i].Umur == buff_int)
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==6)
    {
        printf("Masukkan Jenis Kelamin yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].JenisKelamin, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==7)
    {
        printf("Masukkan Golongan Darah yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].GolonganDarah, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==8)
    {
        printf("Masukkan Status yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].Status, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
    else if(n==9)
    {
        printf("Masukkan Pekerjaan yang ingin dicari: "); scanf(" %[^\n]s", &buff_string);
        for(i=0;i<data_length;i++)
        {
            if((strcmp(dataP[i].Pekerjaan, buff_string) == 0))
            {
                printData2(dataP,i);
            };
        };
    }
}

void update(struct penduduk dataP[1000])
{
    printf("\nAnda telah memilih opsi update (Mengganti datum yang sudah ada dengan datum baru)\n");
    printf("Masukkan Nomor datum (No) yang ingin di-update: ");scanf("%d", &buff_int);
    printf("\nSilakan isi form di bawah ini untuk memperbarui data:\n");
    printf("Nama Lengkap    : ");scanf(" %[^\n]s", &dataP[buff_int-1].NamaLengkap);
    printf("Tempat Lahir    : ");scanf(" %[^\n]s", &dataP[buff_int-1].TempatLahir);
    printf("Tanggal Lahir   : ");scanf(" %[^\n]s", &dataP[buff_int-1].TanggalLahir);
    printf("Umur            : ");scanf("%d", &dataP[buff_int-1].Umur);
    printf("Jenis Kelamin   : ");scanf(" %[^\n]s", &dataP[buff_int-1].JenisKelamin);
    printf("Golongan Darah  : ");scanf(" %[^\n]s", &dataP[buff_int-1].GolonganDarah);
    printf("Status          : ");scanf(" %[^\n]s", &dataP[buff_int-1].Status);
    printf("Pekerjaan       : ");scanf(" %[^\n]s", &dataP[buff_int-1].Pekerjaan);
}

void deleteData(struct penduduk dataP[1000])
{
    printf("\nAnda telah memilih opsi delete (Menghapus satu baris data)\n");
    printf("Masukkan Nomor datum (No) yang ingin di-delete: ");scanf("%d", &buff_int);
    for(i=buff_int-1;i<data_length;i++)
    {
        dataP[i]=dataP[i+1];
    }
    data_length=data_length-1;
    strcpy(dataP[data_length].NIK, "");
    strcpy(dataP[data_length].NamaLengkap, "");
    strcpy(dataP[data_length].TempatLahir, "");
    strcpy(dataP[data_length].TanggalLahir, "");
    dataP[data_length].Umur = 0;
    strcpy(dataP[data_length].JenisKelamin, "");
    strcpy(dataP[data_length].GolonganDarah, "");
    strcpy(dataP[data_length].Status, "");
    strcpy(dataP[data_length].Pekerjaan, "");
}

void importMerge(struct penduduk dataP[1000])
{
    printf("\nAnda telah memilih opsi import (Merging data dari file .csv lain)\n");
    printf("Masukkan nama file yang akan di-merge: ");scanf(" %[^\n]s", &filename_merge);
    fpmerge = fopen(filename_merge, "r+");
    i=0;
    while(fgets(buf, 1024, fpmerge))
    {
        strcpy(buffer, strtok(buf, ";"));
        buffer_dataP[i].No = atoi(buffer);
        strcpy(buffer_dataP[i].NIK, strtok(NULL, ";"));
        strcpy(buffer_dataP[i].NamaLengkap, strtok(NULL, ";"));
        strcpy(buffer_dataP[i].TempatLahir, strtok(NULL, ";"));
        strcpy(buffer_dataP[i].TanggalLahir, strtok(NULL, ";"));
        strcpy(buffer, strtok(NULL, ";"));
        buffer_dataP[i].Umur = atoi(buffer);
        strcpy(buffer_dataP[i].JenisKelamin, strtok(NULL, ";"));
        strcpy(buffer_dataP[i].GolonganDarah, strtok(NULL, ";"));
        strcpy(buffer_dataP[i].Status, strtok(NULL, ";"));
        strcpy(buffer_dataP[i].Pekerjaan, strtok(NULL, ";"));
        i++;
    }
    fclose(fpmerge);
    data_length_buffer = i;
    for(i=data_length;i<(data_length+data_length_buffer);i++)
    {
        strcpy(dataP[i].NIK, buffer_dataP[i-data_length].NIK);
        strcpy(dataP[i].NamaLengkap, buffer_dataP[i-data_length].NamaLengkap);
        strcpy(dataP[i].TempatLahir, buffer_dataP[i-data_length].TempatLahir);
        strcpy(dataP[i].TanggalLahir, buffer_dataP[i-data_length].TanggalLahir);
        dataP[i].Umur = buffer_dataP[i-data_length].Umur;
        strcpy(dataP[i].JenisKelamin, buffer_dataP[i-data_length].JenisKelamin);
        strcpy(dataP[i].GolonganDarah, buffer_dataP[i-data_length].GolonganDarah);
        strcpy(dataP[i].Status, buffer_dataP[i-data_length].Status);
        strcpy(dataP[i].Pekerjaan, buffer_dataP[i-data_length].Pekerjaan);
    }
    data_length=data_length+data_length_buffer;
}

void sort(struct penduduk dataP[1000])
{
    printf("   1. NIK\n");
    printf("   2. Nama Lengkap\n");
    printf("   3. Tempat Lahir\n");
    printf("   4. Tanggal Lahir\n");
    printf("   5. Umur\n");
    printf("   6. Jenis Kelamin\n");
    printf("   7. Golongan Darah\n");
    printf("   8. Status\n");
    printf("   9. Pekerjaan\n\n");
    printf("\nMasukkan parameter yang ingin diurutkan: "); scanf("%d", &n);
    while (!(n>=1 && n<=9))
    {
        printf("Input salah silakan input ulang\n");
        printf("\nMasukkan parameter yang ingin diurutkan: "); scanf("%d", &n);
    }
    for(i=0;i<data_length-1;i++)
    {
        for(j=0;j<data_length-i-1;j++)
        {
            if(n==1)
            {
                value = strcmp(dataP[j].NIK, dataP[j+1].NIK);
            }
            else if(n==2)
            {
                value = strcmp(dataP[j].NamaLengkap, dataP[j+1].NamaLengkap);
            }
            else if(n==3)
            {
                value = strcmp(dataP[j].TempatLahir, dataP[j+1].TempatLahir);
            }
            else if(n==4)
            {
                value = strcmp(dataP[j].TanggalLahir, dataP[j+1].TanggalLahir);
            }
            else if(n==5)
            {
                if (dataP[j].Umur > dataP[j+1].Umur)
                {
                    dataPB = dataP[j];
                    dataP[j] = dataP[j+1];
                    dataP[j+1]=dataPB;
                };
            }
            else if(n==6)
            {
                value = strcmp(dataP[j].JenisKelamin, dataP[j+1].JenisKelamin);
            }
            else if(n==7)
            {
                value = strcmp(dataP[j].GolonganDarah, dataP[j+1].GolonganDarah);
            }
            else if(n==8)
            {
                value = strcmp(dataP[j].Status, dataP[j+1].Status);
            }
            else if(n==9)
            {
                value = strcmp(dataP[j].Pekerjaan, dataP[j+1].Pekerjaan);
            }
            if(value>0 && n!=5)
            {
                dataPB = dataP[j];
                dataP[j] = dataP[j+1];
                dataP[j+1]=dataPB;
            }
        }
    }
}
