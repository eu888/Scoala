#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int Anul; 
    int Luna; 
    int Ziua;
}Data;

typedef struct{
    char* Nume;
    char* Prenume;
    Data dataNasterii;
} Persoana;

int main(){
    time_t t;
    struct tm *timp;
    time(&t);
    timp = localtime(&t);
    int n, an, luna, zi, vAni, anC, lunaC, ziC, vaAni, vaLuni, vaZile;
    size_t vMarei = 0;
    anC = timp->tm_year + 1900;
    lunaC = timp->tm_mon + 1;   
    ziC = timp->tm_mday;
    Persoana buffMare, buffMic;
    printf("Introduceti numarul de persoane: ");
    scanf("%d", &n);
    Persoana *persoane = (Persoana*)malloc(n * sizeof(Persoana));
    Persoana *mareV = (Persoana*)malloc(n * sizeof(Persoana));
    for(size_t i = 0; i < n; i++){
        persoane[i].Nume = (char*)malloc(50 * sizeof(char));
        persoane[i].Prenume = (char*)malloc(50 * sizeof(char));
        printf("Introduceti numele persoanei %d: ", i + 1);
        scanf("%49s", persoane[i].Nume);
        printf("Introduceti prenumele persoanei %d: ", i + 1);
        scanf("%49s", persoane[i].Prenume);
        printf("Introduceti data nasterii (anul,luna,ziua) persoanei %d: ", i + 1);
        scanf("%d %d %d", &persoane[i].dataNasterii.Anul, &persoane[i].dataNasterii.Luna, &persoane[i].dataNasterii.Ziua);
    }
    printf("Introduceti un an: ");
    scanf("%d", &an);
    printf("Intr-o luna: ");
    scanf("%d", &luna);
    printf("Intr-o zi: ");
    scanf("%d", &zi);
    printf("Introduceti o varsta: ");
    scanf("%d", &vAni);
    for (size_t i = 0; i < n; i++){
        if(i == 0) buffMare = persoane[i];

        if(persoane[i].dataNasterii.Anul == an){
            printf("Persoana %s %s s-a nascut in anul dat.\n", persoane[i].Nume, persoane[i].Prenume);
        } else if(persoane[i].dataNasterii.Luna == luna){
            printf("Persoana %s %s s-a nascut in luna data.\n", persoane[i].Nume, persoane[i].Prenume);
        } else if(persoane[i].dataNasterii.Ziua == zi){
            printf("Persoana %s %s s-a nascut in ziua data.\n", persoane[i].Nume, persoane[i].Prenume);
        } else if(persoane[i].dataNasterii.Anul == an && persoane[i].dataNasterii.Luna == luna  && persoane[i].dataNasterii.Ziua == zi){
            printf("Persoana %s %s s-a nascut in data completa data.\n", persoane[i].Nume, persoane[i].Prenume);
        } else if (persoane[i].dataNasterii.Anul > buffMare.dataNasterii.Anul || persoane[i].dataNasterii.Luna > buffMare.dataNasterii.Luna || persoane[i].dataNasterii.Ziua > buffMare.dataNasterii.Ziua){
            buffMare = persoane[i];
        } else if (persoane[i].dataNasterii.Anul < buffMic.dataNasterii.Anul || persoane[i].dataNasterii.Luna < buffMic.dataNasterii.Luna || persoane[i].dataNasterii.Ziua < buffMic.dataNasterii.Ziua){
            buffMic = persoane[i];
        }

        vaAni = anC - persoane[i].dataNasterii.Anul;
        vaLuni = lunaC - persoane[i].dataNasterii.Luna;
        vaZile = ziC - persoane[i].dataNasterii.Ziua;
        if(vaZile < 0){
            vaLuni--;
            vaZile += 30;
        }
        if(vaLuni < 0){
            vaAni--;
            vaLuni += 12;
        }
        if(vaAni > vAni){
            mareV[vMarei] = persoane[i];
            vMarei++;
        }
        
        
        
        printf("Persoana %s %s are varsta de %d ani, %d luni si %d zile.\n", persoane[i].Nume, persoane[i].Prenume, vaAni, vaLuni, vaZile);

        
    }
    printf("Cea mai tanara persoana este %s %s, nascuta la data de %d/%d/%d.\n", buffMare.Nume, buffMare.Prenume, buffMare.dataNasterii.Anul, buffMare.dataNasterii.Luna, buffMare.dataNasterii.Ziua);
    printf("Cea mai varstnica persoana este %s %s, nascuta la data de %d/%d/%d.\n", buffMic.Nume, buffMic.Prenume, buffMic.dataNasterii.Anul, buffMic.dataNasterii.Luna, buffMic.dataNasterii.Ziua);
    for (size_t i = 0; i < n; i++){
        free(persoane[i].Nume);
        free(persoane[i].Prenume);
    }
    for (size_t i = 0; i < n; i++){
        free(mareV[i].Nume);
        free(mareV[i].Prenume);
    }
    free(persoane);
    free(mareV);


    return 0;
}