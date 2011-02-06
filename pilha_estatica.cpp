#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct pilha{
       float info[N]; //Vetor de elementos(float/reais) de tamanho máximo 50
       int n; //Quantidade de elementos na pilha
}Pilha;

//Função para criar a pilha vazia
Pilha*  criarPilha(){
       Pilha *p = (Pilha*) malloc(sizeof(Pilha));
       p->n = 0;
       return p;
}

//Função para inserir no final
void push(Pilha* p, float v){
     if(p->n == N){
             printf("\nCapacidade da pilha estourou!\n");
             exit(1);
     }
     p->info[p->n] = v;
     p->n++;
}

//Função para verficar se a pilha esta vazia, retorna 1(Verdadeiro) ou 0(Falso)
int estaVazia(Pilha* p){	
	return (p->n==0);
}

//Função para excluir do topo
float pop(Pilha* p){
      if(estaVazia(p)){
          printf("Pilha vazia");
          exit(1);
      }
      float v = p->info[p->n - 1];
      p->n--;
      return v;
}

//Função para liberar
void liberarPilha(Pilha* p){
     free(p);
}

//Função para verificar se esta cheia, retorna 1(Verdadeiro) ou 0(Falso)
int estaCheia(Pilha* p){
   return(p->n == N); 
}

//Função para imprimir
void imprimePilha(Pilha* p){
    int quantElementos = p->n;
    int i;
    for(i=0;i<quantElementos;i++){
        printf("\n %0.2f \n", p->info[i]);              
    }
}

//Função para ver o topo, retorna o valor do ultimo elemento
float verTopo(Pilha* p){
     int quantElementos = p->n;
     quantElementos = quantElementos- 1;
     return p->info[quantElementos]; 
}
