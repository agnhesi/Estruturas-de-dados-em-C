void  push(Fila *f, float v){
    if(f->n==N){ 
      printf("\nCapacidade da fila esgotada.\n");
      return;  
    }else{      
      f->info[f->ini] = v;
      f->ini = (f->ini + 1) % f->n;
    } 
}

float pop(Fila *f){
     float v;
     if(vazia(f)){
         printf("\nFila vazia.\n");
     }else{  
         f->rem = (F->rem + 1) % F->n;
     }
     return v;
}
