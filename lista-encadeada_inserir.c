#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

int inserir (celula *elem, int x){
    no *novo = malloc (sizeof(no));
    if (novo == NULL) return 0;
    novo -> dado = x;
    novo -> prox = elem -> prox;
    elem -> prox = novo;
    return 1;
}


// inserção no início da lista
void inserir_inicio(celula *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;// (*novo).valor = valor

    if(lista->inicio == NULL){ // a lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else{ // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}