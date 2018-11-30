#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double tempo = 0;
long int instrucoes = 0;

double selectionSort(int* v, int tam){
    clock_t inicio = clock();
    for(int i=tam; i > 0; i--){
        int m = i;
        for(int j=0; j<i; j++){
            instrucoes += 1;
            if(v[j] > v[m])
                m = j;
        }
        int temp = v[i];
        v[i] = v[m];
        v[m] = temp;
    }
    clock_t fim = clock();
    tempo = (((double) fim - inicio) / CLOCKS_PER_SEC);
    return tempo; 
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
    
    selectionSort(v, qtde);
    printf("selectionSort - Tempo: %lf\nNúmero de Instruções: %d", tempo, instrucoes);
}