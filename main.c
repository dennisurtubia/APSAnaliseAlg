#include <stdlib.h>
#include <stdio.h>

#include "algoritmos.h"
#include "openFile.h"



int main() {
    int *v;
    long int qtde = 100000;

    v = (int*) malloc (sizeof(int) * qtde);

    openFile(v, qtde);  
    bubbleSort(v, qtde);
    printf("***BubbleSort (Simples)***\tTempo: %lf \tNum. de Instr: %lu\n", tempoBubble, instrBubble); 

    // bubbleSort2(v, qtde);
    // printf("***BubbleSort (Melhorado)***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoBubble2, instrBubble2);

    // insertionSort(v, qtde);
    // printf("***InsertionSort***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoInsertion, instrInsertion);

    // selectionSort(v, qtde);
    // printf("***SelectionSort***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoSelection, instrSelection);

    // mergeSort(v, 0, qtde);
    // printf("***MergeSort***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoMerge, instrMerge);  

    // quickSort(v, 0, qtde);
    // printf("***QuickSort***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoQuick, instrQuick);

    // vetmax(v, qtde);
    // printf("***Subvetor Max***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoSub, instrSub);

    // heapSort(v, qtde);
    // printf("***HeapSort***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoHeap, instrHeap);

    // binarySearchCallFunction(v, 0, qtde-1, 10);
    // printf("***BinarySearch***\nTempo: %lf\nNum. de Instr: %lu\n----------\n", tempoBinary, instrBinary);

}