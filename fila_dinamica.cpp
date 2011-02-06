#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura do nó
typedef struct nolista{
   float info; //Valor
   struct nolista* prox; //Aponta para o nó da frente
}Nolista;


// Estrutura da fila
struct Fila{
       Nolista* ini;//Ponteiro para o primeiro nó 
       Nolista* fim;//Ponteiro para o último nó 
};


// Função para criar a fila vazia
Fila* criarFila(void) {
  Fila *f= (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = NULL;
  return f;
}

// Função que insere um elemento v no final da fila f.
void inserir(Fila* f, float v) {
  Nolista* n = (Nolista*)malloc(sizeof(Nolista));
  n->info = v;
  n->prox = NULL;
  if(f->fim != NULL)   //verifica se a lista não estava vazia
      f->fim->prox = n;
  else
      f->ini = n;
  f->fim = n;           // fila aponta para o novo elemento
}

//Função que verifica se a fila vazia.
int estaVazia(Fila* f) {
  return (f->ini == NULL);
}

// Função que remove um elemento no início da fila.
float remover(Fila* f) {
  Nolista* t;
  float valor;
  if(estaVazia(f)){
     printf("Fila vazia!");
     exit(1);
  }
  t = f->ini;
  valor = t->info;
  f->ini = t->prox;
  if(f->ini == NULL)       //Verifica se a lista ficou vazia
    f->fim = NULL;
  free(t);
  return valor;
}



// Função que apresenta o primeiro elemento da fila
float verPrimeiroElemento (Fila* f) {
  return (f->ini->info);
}

// Função que libera memória alocada para a fila.
void liberarFila(Fila* f) {
  Nolista* q = f->ini;
  while(q != NULL){
     Nolista* t = q->prox;
     free(q);
     q = t;
  }
  free(f);
}

//Função que imprime todos os elementos da fila
void imprimeFila(Fila* f){
  Nolista* q;
  for(q = f->ini; q!= NULL; q = q->prox)
    printf("%.2f\n", q->info);
}
