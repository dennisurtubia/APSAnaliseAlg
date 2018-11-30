#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double tempo = 0;
long int instrucoes = 0;

void bubbleSort(int *v, long int qtde) {
    int aux = 0;
    clock_t inicio = clock();

    for(int i = 0; i < qtde - 1; i++) {
        for(int j = i+1; j < qtde; j++){
            instrucoes += 1;
            if(v[i] > v[j]){
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
    clock_t fim = clock();
    tempo = (((double) fim - inicio) / CLOCKS_PER_SEC);
}

int openFile(int *v) {
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

int main() {
    int *v;
    long int qtde = 100000;

    v = (int*) malloc (sizeof(int) * qtde);

    openFile(v);
    
    bubbleSort(v, qtde);
    printf("bubbleSort com melhorias\nTempo: %lf\nNúmero de instruções: %lu", tempo, instrucoes);
}