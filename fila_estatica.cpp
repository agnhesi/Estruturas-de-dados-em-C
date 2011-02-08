#include "stdafx.h"
#include <stdio.h>;
#include <stdlib.h>;

#define N 50

typedef struct fila {
       float info[N]; 
       int n; 
       int ini; 
}Fila;


Fila *criar(){
      Fila *f = (Fila*)malloc(sizeof(Fila));
      f->n=0;
      f->ini=0; 
      return f;
} 


int vazia(Fila *f){
	if( f != NULL)
		return(f->ini==0 && f->n==0);
	else
		return 2;
}


void  push(Fila *f, float v){
    if(f->n==N){ 
      printf("\nCapacidade da fila esgotada.\n");
      return;  
    }else{   
      f->info[f->n]=v;
      f->n++;
    } 
}


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


void liberar(Fila *f){
     free(f);
} 


void imprimir(Fila *f){
     int i;
     for(i=f->ini;i<f->n;i++)
              printf("\n%.2f",f->info[i]);
     printf("\n");
}             

