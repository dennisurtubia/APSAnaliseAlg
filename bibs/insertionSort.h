#include <time.h>

double tempoInsertion = 0;
long int instrInsertion = 0;

double insertionSort(int* v, int tam){
  int aux = 0;
  clock_t inicio = clock();
  for(int i=1; i<tam; i++){
    int elem = v[i];
      for(int j = i; j>0; j--){
        instrInsertion += 1;
          if(elem < v[j-1]){
            elem = v[j];
            v[j] = v[j-1];
            v[j-1] = elem;
          }
      }
  }
  clock_t fim = clock();
  tempoInsertion = (((double) fim - inicio) / CLOCKS_PER_SEC);
}   