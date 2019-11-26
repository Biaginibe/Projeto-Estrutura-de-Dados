#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    dados infos;
}Elem;

Lista *criaLista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void destroiLista(Lista *li){
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
    no->infos = cliente;
    if(lista_vazia(li)){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        Elem *anterior, *atual = *li;
        while(atual != NULL && atual->infos.codigo < cliente.codigo){
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

//Consulta baseado em uma determinada posição
int buscaPos(Lista *li, int pos, dados *cliente){
    if(li==NULL || pos<=0){
        return 0;
    }
    Elem *no = *li;
    int i = 1;
    while(no!=NULL && i<pos){
        no = no->prox;
        i++;
    }
    if(no==NULL){
        return 0;
    }else{
        *cliente = no->dados;
        return 1;
    }
}

void relatorioGeral(Lista *li){
    int pos = 0, i;
    int tamanho = tamanhoLista(li);
    for(i=0;i<tamanho;i++){
        int x = buscaPos(li, pos, &cliente);
        if(x){
            printf("\nCódigo do Cliente: %d", cliente.id);
            printf("\nNome do Cliente: %s", cliente.nome);
            printf("\nEmpresa do Cliente:%s" cliente.empresa);
            printf("\nDepartamento do Cliente: %s", cliente.departamento);
            printf("\nTelefone do Cliente:%d ", cliente.telefone);
            printf("\nCelular do Cliente:%d", cliente.celular);
            printf("\nEmail do Cliente: %s\n", cliente.email);
            pos++;
        }else{
            printf("Erro na consulta\n");
        }
    }

}


