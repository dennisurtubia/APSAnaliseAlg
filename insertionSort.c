#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double insertionSort(int* v, int tam){
    int aux = 0;
    long int instrucoes = 0;
    double tempo;
    clock_t inicio = clock();
    for(int i=1; i<tam; i++){
        int elem = v[i];
        for(int j = i; j>0; j--){
            instrucoes += 1;
            if(elem < v[j-1]){
                elem = v[j];
                v[j] = v[j-1];
                v[j-1] = elem;
            }
        }
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
    
    tempo = insertionSort(v, qtde);
    printf("insertionSort - Tempo: %lf\n", tempo);
}