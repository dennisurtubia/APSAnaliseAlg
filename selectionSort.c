#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double selectionSort(int* v, int tam){
    int aux = 0;
    long int instrucoes = 0;
    double tempo;
    clock_t inicio = clock();
    for(int i=tam; i > 0; i--){
        int m = i;
        for(int j=0; j<i; j++){
            if(v[j] > v[m])
                m = j;
        }
        instrucoes += 1;
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
    long int qtde = 1000;
    double tempo;

    v = (int*) malloc (sizeof(int) * qtde);

    openFile(v);
    
    tempo = selectionSort(v, qtde);
}