#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#define N 100

struct fila {
	int ini, fim;
	float vet[N];
}

Fila* criaFilaVazia(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = 0;
	return f;
}

int incremento(int i){
	return (i+1)%N;
}

void push(Fila* f, float v){
	if (incremento(f->fim) == f->ini) {
		printf("Capacidade da fila estourou.\n");
		exit(1);
	}

	f->vet[f->fim] = v;
	f->fim = incremento(f->fim);
}


float pop(Fila* f){
	float v;
	if (vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}
	v = f->vet[f->ini];
	f->ini = incr(f->ini);
	return v;
}

int vazia (Fila* f){
	return (f->ini == f->fim);
}

void libera (Fila* f){
	free(f);
}
