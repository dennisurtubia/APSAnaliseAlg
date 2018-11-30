#include <time.h>

int e = 0, d = 0, maiorSoma = 0, soma = 0;

long int instrSub = 0;
double tempoSub = 0;

void vetmax(int *v, int qtde){
  maiorSoma = v[0];
  for(int i = 0; i < qtde; i++){
    for(int j = i; j < qtde; j++){
      soma += v[j];
      if(soma > maiorSoma){
        maiorSoma = soma;
        e = i;
        d = j;
      }
    }
    soma = 0;
  }
}