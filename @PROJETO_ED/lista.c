#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    dados infos;
}

typedef struct elemento Elem;

Lista *criaLista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void destroiLista(Lista li){
    if(li != NULL){
        Elem *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insereContato(Lista *li, dados cliente){
    if(li == NULL ){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = cliente;
    if(lista_vazia(li)){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        Elem *anterior, *atual = *li;
        while(atual != NULL && atual->dados.codigo < cliente.codigo){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
    }
    return 1;
}

int tamanhoLista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    Elem *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}


