#include <stdio.h>
#define bool _Bool
#define true 1
#define false 0

typedef struct{
    int h, min;
}Time;

typedef struct{
    Time t[2], dif;
    int nr;
    bool valid;
}Doctor;

void swappDoctor(Doctor *a, Doctor *b);
int mod(int a);

int n,d;
bool swapped;
FILE *fileIn, *fileOut;
Doctor temp;

int main(){
    fileIn = fopen("consult.txt", "r");
    if(!fileIn) return 1;
    fscanf(fileIn, "%d %d", &n, &d);
    Doctor listaDoctori[n];
    for(int i = 0;i < n;i++){
        fscanf(fileIn,"%d %d %d %d", &listaDoctori[i].t[0].h, &listaDoctori[i].t[0].min, &listaDoctori[i].t[1].h, &listaDoctori[i].t[1].min);
        listaDoctori[i].nr = i+1;
    }
    fclose(fileIn);

    for(int i = 0;i < n-1;i++){
        swapped = false;
        for(int j = 0;j < n-i-1;j++){
            if(listaDoctori[j].t[0].h >= listaDoctori[j+1].t[0].h){
                swappDoctor(&listaDoctori[j], &listaDoctori[j+1]);
                swapped = true;
            }
            
        }
        if(swapped == false) break;
    }

    for(int i = 0;i < n;i++){
        listaDoctori[i].dif.h = listaDoctori[i].t[1].h - listaDoctori[i].t[0].h;
        listaDoctori[i].valid = true;
        if(listaDoctori[i].t[1].min >= listaDoctori[i].t[0].min) listaDoctori[i].dif.min = listaDoctori[i].t[1].min - listaDoctori[i].t[0].min;
        if(listaDoctori[i].t[1].min < listaDoctori[i].t[0].min) listaDoctori[i].dif.min = listaDoctori[i].t[0].min - listaDoctori[i].t[1].min;
        if(listaDoctori[i].t[0].h > listaDoctori[i].t[1].h) listaDoctori[i].dif.h--;
        if(listaDoctori[i].dif.min < d && listaDoctori[i].dif.h < 1) listaDoctori[i].valid = false;
    }

    for(int i = 0;i < n;i++){
        if(listaDoctori[i].valid){
            if(listaDoctori[i].t[0].min+d >= 60){
                listaDoctori[i].t[1].min = (listaDoctori[i].t[0].min+d) - 60;
                listaDoctori[i].t[1].h = listaDoctori[i].t[0].h+1;
            }
            if(listaDoctori[i].t[0].min+d<60){
                listaDoctori[i].t[1].min=listaDoctori[i].t[0].min+d;
                listaDoctori[i].t[1].h=listaDoctori[i].t[0].h;
            }
            if(i > 0){
                if(listaDoctori[i].t[0].min <= listaDoctori[i-1].t[1].min && listaDoctori[i].t[0].h <= listaDoctori[i-1].t[1].h){
                    if(mod(listaDoctori[i-1].t[1].min-listaDoctori[i].t[1].min) >= d || listaDoctori[i-1].t[1].h - listaDoctori[i].t[1].h <= 0){
                        listaDoctori[i].t[0].min = listaDoctori[i-1].t[1].min;
                        listaDoctori[i].t[0].h = listaDoctori[i-1].t[1].h;
                        listaDoctori[i].t[1].min = listaDoctori[i].t[0].min+d;
                        if(listaDoctori[i].t[1].min >= 60){
                            listaDoctori[i].t[1].h++;
                            listaDoctori[i].t[1].min-=60;
                        }
                    }
                }
            }
        }
    }

    fileOut = fopen("result.txt","w");
    if(!fileOut) return 1;
    for(int i = 0;i < n;i++){
        if(listaDoctori[i].valid){
            fprintf(fileOut, "%d %d %d %d %d\n",listaDoctori[i].nr , listaDoctori[i].t[0].h, listaDoctori[i].t[0].min, listaDoctori[i].t[1].h, listaDoctori[i].t[1].min);
        }
    }
    fclose(fileOut);

    return 0;
}

void swappDoctor(Doctor *a, Doctor *b){
    temp = *a;
    *a = *b;
    *b = temp;
}

int mod(int a){
    if(a >= 0) return a;
    return -a;
}