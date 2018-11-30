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

    if(fim > inicio){
      pivo = particiona(v, inicio, fim);
      quickSort(v, inicio, pivo-1);
      quickSort(v, pivo+1, fim);
    }
}

int binSearch(int* v, int elem, int inicio, int fim){
  if(inicio > fim) return -1;
  int metade;   
  metade = (inicio+fim)/2;
	if(v[metade] == elem)
    return metade;
  else if(elem < v[metade])
    return binSearch(v, elem, inicio, metade);
  else 
  	return binSearch(v, elem, metade+1, fim);
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

  binSearch(v, 0, 0, qtde);

  printf("Busca Binária\nTempo: %lf\nElemento buscado: 0\nNúmero de instruções %lu\n", tempo, instrucoes);
}