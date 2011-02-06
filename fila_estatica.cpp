#include "stdafx.h"
#include <stdio.h>;
#include <stdlib.h>;

#define N 50

typedef struct fila {
       float info[N]; //Vetor de elementos(float/reais) de tamanho maximo 50
       int n; //Quantidade de elementos na pilha
       int ini; //Posicao Inicial
}Fila;


//Fun��o para criar a Fila vazia
Fila *criar(){
      Fila *f = (Fila*)malloc(sizeof(Fila));
      f->n=0;
      f->ini=0; 
      return f;
} 

//Fun��o para verificar se a fila est� vazia
int vazia(Fila *f){
	if( f != NULL)
		return(f->ini==0 && f->n==0);
	else
		return 2;
}


//Fun��o para inserir no final
void  push(Fila *f, float v){
    if(f->n==N){ 
      printf("\nCapacidade da fila esgotada.\n");
      return;  
    }else{   
      f->info[f->n]=v;
      f->n++;
    } 
}

//Fun��o para excluir do in�cio
float pop(Fila *f){
     float v;
     if(vazia(f)){
         printf("\nFila vazia.\n");
     }else{   
        v = f->info[f->ini];
        f->ini++;
     }
     return v;
}

//Fun��o para liberar
void liberar(Fila *f){
     free(f);
} 

//Fun��o para imprimir
void imprimir(Fila *f){
     int i;
     for(i=f->ini;i<f->n;i++)
              printf("\n%.2f",f->info[i]);
     printf("\n");
}             

