/*  Arvore Binária */
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int tipochave;

typedef struct aux{
    tipochave chave;
    /* Dados armazenados vão aqui */
    struct aux *esq, *dir;
}NO;
typedef NO* pont;

 /* Inserção */

pont adiciona(pont raiz, pont x){
    if(raiz == NULL) return (x);
    if(x->chave< raiz->chave)
        raiz->esq=adiciona(raiz->esq,x);
    else
        raiz->dir = adiciona(raiz->dir, x);
    /*ignore equal keys */
    return(raiz);        
}
pont inicializa(){
    return (NULL);
}
pont criaNovoNo(tipochave ch){
    pont novoNo = (pont)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return(novoNo);
}
int main(){
    pont r = inicializa();
    pont x = criaNovoNo(23);
    r = adiciona(r,x); 
    x = criaNovoNo(12);
    r = adiciona(r,x);
}
/*Fim inserção*/