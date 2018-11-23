#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int e = 1, d = 1;

void vetmax(int *v, int qtde){
  int soma = 0, aux = 0;

  for(int i = 0; i < qtde; i++){
    for(int j = i; j < qtde; j++){
      aux += v[j];
      if(aux > soma){
        soma = aux;
        e = i;
        d = j;
      }
    }
    aux = 0;
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
  int qtde = 5;

  v = (int *)malloc(sizeof(int) * qtde);

  openFile(v);

  vetmax(v, qtde);

  printf("Esquerda: %d, Direita: %d ", e, d);
}