#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura do n�
typedef struct nolista{
   float info; //Valor
   struct nolista* prox; //Aponta para o n� da frente
}Nolista;


// Estrutura da fila
struct Fila{
       Nolista* ini;//Ponteiro para o primeiro n� 
       Nolista* fim;//Ponteiro para o �ltimo n� 
};


// Fun��o para criar a fila vazia
Fila* criarFila(void) {
  Fila *f= (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = NULL;
  return f;
}

// Fun��o que insere um elemento v no final da fila f.
void inserir(Fila* f, float v) {
  Nolista* n = (Nolista*)malloc(sizeof(Nolista));
  n->info = v;
  n->prox = NULL;
  if(f->fim != NULL)   //verifica se a lista n�o estava vazia
      f->fim->prox = n;
  else
      f->ini = n;
  f->fim = n;           // fila aponta para o novo elemento
}

//Fun��o que verifica se a fila vazia.
int estaVazia(Fila* f) {
  return (f->ini == NULL);
}

// Fun��o que remove um elemento no in�cio da fila.
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



// Fun��o que apresenta o primeiro elemento da fila
float verPrimeiroElemento (Fila* f) {
  return (f->ini->info);
}

// Fun��o que libera mem�ria alocada para a fila.
void liberarFila(Fila* f) {
  Nolista* q = f->ini;
  while(q != NULL){
     Nolista* t = q->prox;
     free(q);
     q = t;
  }
  free(f);
}

//Fun��o que imprime todos os elementos da fila
void imprimeFila(Fila* f){
  Nolista* q;
  for(q = f->ini; q!= NULL; q = q->prox)
    printf("%.2f\n", q->info);
}
