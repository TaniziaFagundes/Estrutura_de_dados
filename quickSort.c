#include <stdio.h>
#include <stdlib.h>
#define TAM 20

 
void imprimeVetor(int vetor[]){
    int i=0;
    printf("\n");
    while(i < TAM){
        printf("%d | ", (vetor[i]) );
        i++;
    }
   
}
 
void quick_sort(int vetor[TAM], int inicio, int fim){
 
    int pivo, esquerda, direita, meio, aux;

    esquerda = inicio;
    direita = fim;
    meio =  (int) ((esquerda + direita) / 2);
    pivo = vetor[meio];
   
    while(direita > esquerda){
        
        while(vetor[esquerda] < pivo){
            esquerda = esquerda + 1;
        }
 
        while(vetor[direita] > pivo){
            direita = direita - 1;
        }
 
        if(esquerda <= direita){
 
            //Realiza uma troca
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
 
            //Faz os limites laterais caminharem para o centro
            esquerda = esquerda + 1;
            direita = direita - 1;
        }
    }
    if(inicio < direita){
        quick_sort(vetor, inicio, direita); 
        
    }
    if(esquerda < fim){
         quick_sort(vetor, esquerda, fim);
    }
}
 
int main(){
 
    int vetor[TAM] = {18,1,8,4,15,16,3,5,19,2,6,17,12,13,7,14,20,11,9,10};
 
    quick_sort(vetor, 0, TAM);
 
    imprimeVetor(vetor);
 
    return 0;
}