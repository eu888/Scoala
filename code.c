#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float note[3];
    char statut[8];
} Linie;

FILE *file,*file1,*backup;

int main(){
    int pos = 0;
    Linie linie[10];
    //------------------------------a si d si jumate de putin b si c------------------------------------------------------------
    file = fopen("file.txt", "r");
    if(!file){return 1;}
    while(fscanf(file, "%f %f %f %7s", &linie[pos].note[0], &linie[pos].note[1], &linie[pos].note[2], &linie[pos].statut) == 4){
       printf("%d: %.1f %.1f %.1f %s\n",pos+1, linie[pos].note[0], linie[pos].note[1], linie[pos].note[2], linie[pos].statut);
       pos++;
    }
    fclose(file);
    //------------------------------restul de b---------------------------------------------------------------------------------
    backup = fopen("backup.txt", "w");
    if(!backup){return 1;}
    for(size_t i = 0; i < pos;i++){
        fprintf(backup,"%.1f %.1f %.1f %s\n",linie[i].note[0], linie[i].note[1], linie[i].note[2], linie[i].statut);
    }
    //------------------------------restul de c---------------------------------------------------------------------------------
    file1 = fopen("output.txt", "w");
    if(!file1){return 1;}
    for(size_t i = 0; i < pos;i++){
        float med = (linie[i].note[0] + linie[i].note[1] + linie[i].note[2])/3;
        fprintf(file1, "%.2f\n", med);
    }
    return 0;
}