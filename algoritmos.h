#include <time.h>


double tempoBubble = 0, tempoBubble2 = 0, tempoInsertion = 0, tempoMerge = 0, 
    tempoQuick = 0, tempoSelection = 0, tempoSub = 0, tempoHeap = 0, tempoBinary = 0;

long int instrBubble = 0, instrBubble2 = 0, instrInsertion = 0, instrMerge = 0, 
    instrQuick = 0,instrSelection = 0, instrSub = 0, instrHeap = 0, instrBinary = 0;


void bubbleSort(int *v, long int qtde) {
  int aux = 0;
  clock_t inicio = clock();

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

void insertionSort(int* v, int tam){
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

void merge(int *v, int esq, int meio, int dir) {
    int i, j, k; 
    int n1 = meio - esq + 1; 
    int n2 =  dir - meio; 

    int ESQ[n1], DIR[n2]; 

    for (i=0; i < n1; i++) {
        instrMerge++;
        ESQ[i] = v[esq + i]; 
    }
        
    for (j=0; j < n2; j++) {
        instrMerge++;
        DIR[j] = v[meio + 1+ j]; 
    }
        
    i = 0;
    j = 0;
    k = esq;
    while (i < n1 && j < n2) { 
        instrMerge++;
        if (ESQ[i] <= DIR[j]) { 
            v[k] = ESQ[i]; 
            i++; 
        } 
        else { 
            v[k] = DIR[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        instrMerge++;
        v[k] = ESQ[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        instrMerge++;
        v[k] = DIR[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int *v, int esq, int dir) {
    clock_t inicio = clock();

    if (esq < dir){ 

        int meio = esq+(dir-esq)/2; 
 
        mergeSort(v, esq, meio); 
        mergeSort(v, meio+1, dir); 
        merge(v, esq, meio, dir); 
    } 
    clock_t fim = clock();
    tempoMerge = (((double) fim - inicio) / CLOCKS_PER_SEC);
}

int particiona(int* v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo){
            instrQuick++;
            esq++;
        }
            
        while(v[dir] > pivo){
            instrQuick++;
            dir--;
        }
            
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
    clock_t i = clock();
    if(fim > inicio){
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
    clock_t f = clock();
    tempoQuick += (((double) f - i) / CLOCKS_PER_SEC);
}

void selectionSort(int* v, int tam){
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

void vetmax(int *v, int qtde){
    clock_t inicio = clock();
    int e = 0, d = 0, maiorSoma = 0, soma = 0;
    maiorSoma = v[0];
    for(int i = 0; i < qtde; i++){
        for(int j = i; j < qtde; j++){
            soma += v[j];
            instrSub++;
            if(soma > maiorSoma){
                maiorSoma = soma;
                e = i;
                d = j;
            }
        }
    soma = 0;
    }
    clock_t fim = clock();
    tempoSub = (((double) fim - inicio) / CLOCKS_PER_SEC);
}

void heapSort(int *v, int n) {
    clock_t inicio = clock();
    int i, pai, filho, t;

    i = n / 2;
    while(1 == 1) {
        if (i > 0) {
            i--;
            t = v[i];
        } else {
            n--;
            if (n == 0){
                break;
            }
            t = v[n];
            v[n] = v[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            instrHeap++;
            if ((filho + 1 < n)  &&  (v[filho + 1] > v[filho])){
                filho++;
            }
                
            if (v[filho] > t) {
                v[pai] = v[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        v[pai] = t;
    }
    clock_t fim = clock();
    tempoHeap = (((double) fim - inicio) / CLOCKS_PER_SEC);
}

int binarySearch(int *v, int esq, int dir, int x) {
    instrBinary++;
    if (dir >= esq) { 
        int meio = esq + (dir - esq)/2; 

        if (v[meio] == x) {
            return meio;
        }

        if (v[meio] > x){
            return binarySearch(v, esq, meio-1, x); 
        }

        return binarySearch(v, meio+1, dir, x); 
    }
    return -1; 
} 

void binarySearchCallFunction(int *v, int esq, int dir, int x){
    bubbleSort(v, dir+1);
    clock_t inicio = clock();
    binarySearch(v, esq, dir, x);
    clock_t fim = clock();
    tempoBinary = (((double) fim - inicio) / CLOCKS_PER_SEC);
}



