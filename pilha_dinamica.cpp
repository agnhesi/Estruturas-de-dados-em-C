#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{
    float info; 
    struct noLista* prox; 
}NoLista;


typedef struct pilha{
    NoLista* prim;  
}Pilha;


Pilha* criarPilha(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}


void push(Pilha* p, float v){
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    if(novo != NULL){
        novo->info = v;
        novo->prox = p->prim;
        p->prim = novo;
    }else
        exit(1);
}


int estaVazia(Pilha* p){
	return (p->prim==NULL);
}


float pop(Pilha* p){
    if(estaVazia(p)){
        printf("\nPilha vazia\n");
        exit(1);
    }
    NoLista* temp = p->prim;
    float v = p->prim->info;
    p->prim = p->prim->prox;
    free(temp);
    return v;
}


void liberarPilha(Pilha* p){
    NoLista* q = p->prim;
    while(q!=NULL){
        NoLista* temp = q->prox;
        free(q);
        q = temp;
    }
    free(p);
}


float verTopo(Pilha* p){
    float  v;
    if (p->prim==NULL)
        printf("\nPilha Vazia!");
    else
        v = p->prim->info;
    return v;
}


void imprimePilha(Pilha* p){
    NoLista* q;
    printf("\nElementos da Pilha:");
    for(q = p->prim; q != NULL; q = q->prox){
        printf("\n%.2f  ",q->info);
    }
    printf("\n");
}
