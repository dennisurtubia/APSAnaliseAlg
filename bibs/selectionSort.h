#include <time.h>

double tempoSelection = 0;
long int instrSelection = 0;

double selectionSort(int* v, int tam){
    clock_t inicio = clock();
    for(int i=tam; i > 0; i--){
        int m = i;
        for(int j=0; j<i; j++){
            instrSelection += 1;
            if(v[j] > v[m])
                m = j;
        }
        int temp = v[i];
        v[i] = v[m];
        v[m] = temp;
    }
    clock_t fim = clock();
    tempoSelection = (((double) fim - inicio) / CLOCKS_PER_SEC);
}