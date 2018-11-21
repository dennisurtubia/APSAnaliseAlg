#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int instrucoes = 0;
double tempo;

int particiona(int* v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo)
            esq++;
        while(v[dir] > pivo)
            dir--;
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int* v, int inicio, int fim){
    int pivo;
    clock_t i = clock();
    if(fim > inicio){
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
    clock_t f = clock();
    tempo += (((double) f - i) / CLOCKS_PER_SEC);
}

void openFile(int *v) {
    FILE *arq;
    arq = fopen("arquivo.txt", "r");
    char str[7];
    int i = 0;

    fscanf(arq, "%s", str);
    while(!feof(arq)){
        v[i] = atoi(str);
        fscanf(arq, "%s", str);
        i++;
    }
    fclose(arq);
}

void main(){
    int *v;
    
    int qtde = 100000;

    v = (int*) malloc (sizeof(int) * qtde);

    openFile(v);
    
    quickSort(v, 0, qtde);
    printf("quickSort\nTempo: %lf\nNúmero de instruções %lu\n", tempo, instrucoes);
}