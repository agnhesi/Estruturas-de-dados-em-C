#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

//Definicao do N�
typedef struct noLista{
    float info; //Valor
    struct noLista* prox; //Aponta para o n� anterior
}NoLista;


//Pilha
typedef struct pilha{
    NoLista* prim; //Ponteiro para o �ltimo n� 
}Pilha;


//Fun��o para criar a pilha vazia
Pilha* criarPilha(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

//Fun��o para inserir no topo
void push(Pilha* p, float v){
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    if(novo != NULL){
        novo->info = v;
        novo->prox = p->prim;
        p->prim = novo;
    }else
        exit(1);
}

//Fun��o para verficar se a pilha est� vazia
int estaVazia(Pilha* p){
	return (p->prim==NULL);
}

//Fun��o para excluir do topo, retorna o valor do n� exclu�do
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

//Fun��o para liberar
void liberarPilha(Pilha* p){
    NoLista* q = p->prim;
    while(q!=NULL){
        NoLista* temp = q->prox;
        free(q);
        q = temp;
    }
    free(p);
}


//Fun��o para ver o elemento do topo
float verTopo(Pilha* p){
    float  v;
    if (p->prim==NULL)
        printf("\nPilha Vazia!");
    else
        v = p->prim->info;
    return v;
}

//Fun��o para imprimir
void imprimePilha(Pilha* p){
    NoLista* q;
    printf("\nElementos da Pilha:");
    for(q = p->prim; q != NULL; q = q->prox){
        printf("\n%.2f  ",q->info);
    }
    printf("\n");
}
