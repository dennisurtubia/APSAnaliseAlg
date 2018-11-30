#include <stdlib.h>

int openFile(int *v, int q) {
  FILE *arq;
  arq = fopen("arquivo.txt", "r");
  char str[7];
  int i = 0;

  fscanf(arq, "%s", str);
  while(i < q){
    v[i] = atoi(str);
    fscanf(arq, "%s", str);
    i++;
  }
  fclose(arq);
}