#include <time.h>

double tempoBubble2 = 0;
long int instrBubble2 = 0;

void bubbleSort2(int *v, long int qtde) {
    int aux = 0;
    clock_t inicio = clock();

    for(int i = 0; i < qtde - 1; i++) {
        for(int j = i+1; j < qtde; j++){
            instrBubble2 += 1;
            if(v[i] > v[j]){
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
    clock_t fim = clock();
    tempoBubble2 = (((double) fim - inicio) / CLOCKS_PER_SEC);
}