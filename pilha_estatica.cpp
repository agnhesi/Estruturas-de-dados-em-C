#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct pilha{
       float info[N]; 
       int n; 
}Pilha;


Pilha*  criarPilha(){
       Pilha *p = (Pilha*) malloc(sizeof(Pilha));
       p->n = 0;
       return p;
}

void push(Pilha* p, float v){
     if(p->n == N){
             printf("\nCapacidade da pilha estourou!\n");
             exit(1);
     }
     p->info[p->n] = v;
     p->n++;
}


int estaVazia(Pilha* p){	
	return (p->n==0);
}


float pop(Pilha* p){
      if(estaVazia(p)){
          printf("Pilha vazia");
          exit(1);
      }
      float v = p->info[p->n - 1];
      p->n--;
      return v;
}


void liberarPilha(Pilha* p){
     free(p);
}


int estaCheia(Pilha* p){
   return(p->n == N); 
}


void imprimePilha(Pilha* p){
    int quantElementos = p->n;
    int i;
    for(i=0;i<quantElementos;i++){
        printf("\n %0.2f \n", p->info[i]);              
    }
}


float verTopo(Pilha* p){
     int quantElementos = p->n;
     quantElementos = quantElementos- 1;
     return p->info[quantElementos]; 
}
