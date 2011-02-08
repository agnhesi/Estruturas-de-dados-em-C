#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct nolista{
   float info; 
   struct nolista* prox; 
}Nolista;


struct Fila{
       Nolista* ini; 
       Nolista* fim; 
};


Fila* criarFila(void) {
  Fila *f= (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = NULL;
  return f;
}


void inserir(Fila* f, float v) {
  Nolista* n = (Nolista*)malloc(sizeof(Nolista));
  n->info = v;
  n->prox = NULL;
  if(f->fim != NULL)  
      f->fim->prox = n;
  else
      f->ini = n;
  f->fim = n;         
}


int estaVazia(Fila* f) {
  return (f->ini == NULL);
}


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
  if(f->ini == NULL)    
    f->fim = NULL;
  free(t);
  return valor;
}


float verPrimeiroElemento (Fila* f) {
  return (f->ini->info);
}


void liberarFila(Fila* f) {
  Nolista* q = f->ini;
  while(q != NULL){
     Nolista* t = q->prox;
     free(q);
     q = t;
  }
  free(f);
}


void imprimeFila(Fila* f){
  Nolista* q;
  for(q = f->ini; q!= NULL; q = q->prox)
    printf("%.2f\n", q->info);
}
