#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int e = 0, d = 0, maiorSoma = 0, soma = 0;

void vetmax(int *v, int qtde){
  maiorSoma = v[0];
  for(int i = 0; i < qtde; i++){
    for(int j = i; j < qtde; j++){
      soma += v[j];
      if(soma > maiorSoma){
        maiorSoma = soma;
        printf("esquerda: %d - direita: %d\n", i, j);
        e = i;
        d = j;
      }
    }
    soma = 0;
  }
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

int main(){

  int *v;
  int qtde = 8;

  v = (int *)malloc(sizeof(int) * qtde);

  openFile(v);

  vetmax(v, qtde);

  printf("Esquerda: %d, Direita: %d, Maior Soma: %d\n ", e, d, maiorSoma);
}