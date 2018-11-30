#include <time.h>


double tempoBubble = 0;
long int instrBubble = 0;

void bubbleSort(int *v, long int qtde) {
  int aux = 0;
  clock_t inicio = clock();
  tempoBubble = 0;
  instrBubble = 0;

  for(int i = 0; i < qtde; i++){
    for(int j = 0; j < qtde; j++){
      instrBubble += 1;
      if(v[j] > v[j+1]) {
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
	}
  clock_t fim = clock();
  tempoBubble = (((double) fim - inicio) / CLOCKS_PER_SEC);
}
