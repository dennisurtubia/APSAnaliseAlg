#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double tempo = 0;
long int instrucoes = 0;

void bubbleSort(int *v, long int qtde) {
  int aux = 0;
  clock_t inicio = clock();

  for(int i = 0; i < qtde; i++){
    for(int j = 0; j < qtde; j++){
      instrucoes += 1;
      if(v[j] > v[j+1]) {
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
	}
  clock_t fim = clock();
  tempo = (((double) fim - inicio) / CLOCKS_PER_SEC);
}

int openFile(int *v, int q) {
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
