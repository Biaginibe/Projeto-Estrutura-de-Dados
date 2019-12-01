#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//função tamanhoLista: encontra o total de elementos em uma lista
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

//função buscaPos: procura um determinado elemento da lista com base numa posição previamente mostrada
int buscaPos(Lista *li, int pos, dados *cliente){
    if(li == NULL || pos <= 0){//ta dando erro por causa do 'pos <= 0'
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
        *cliente = no->infos;
        return 1;
    }
}
//função relatorioGeral: executada dentro de um "for", busca todas as informações de um cliente
//funciona como uma consulta por posição, e o valor da posição em si é alteraldo dentro do switch do programa principal
int relatorioGeral(Lista *li, int pos, dados *cliente){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    int i = 0;
    while(no!=NULL && i<pos){
        no = no->prox;
        i++;
    }
    if(no==NULL){
        return 0;
    }else{
        *cliente = no->infos;
        return 1;
    }
}
int buscaPorId(Lista *li, int cod, dados *cliente){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    int i = 0;
    while(no != NULL && no->infos.codigo != cod){
        no = no->prox;
        printf("%d", i++);
    }
    if(no == NULL){
        return 0;
    }else{
        *cliente = no->infos;
        return 1;
    }
}

int buscaNome(Lista *li, dados *cliente){//a função em si funciona de modo semelhante a busca por ID
    if(li == NULL){
        return 0;
        printf("Erro na Lista!");
   }
    char nome[50];
    printf("Digite o Nome que deseja buscar: ");
    fflush(stdin);
    gets(nome);

    Elem *no = *li;
    int i = 0;
    int n = 0;
    while(no != NULL){
        n = strcmp(nome, no->infos.nome);// comparação do nome
        if(n == 0){
            break;
        }else{
        no = no->prox;
        }
    }
    if(no == NULL){
        return 0;
    }else{
        *cliente = no->infos;
        return 1;
    }
}

int lista_vazia(Lista *li){
    if(li == NULL){//Não existe lista
        return 1;
    }
    if(*li == NULL){//Não tem nada na lista
        return 1;
    }
    return 0;
}

int certeza(){
    int option;
    printf("Tem certeza que deseja remover o cliente acima?\n1-Sim\n2-Nao\nOpcao: ");
    scanf("%d", &option);
    if(option == 1){
        return 1;
    }else{
        return 0;
    }
}

int removeContato(Lista *li, int cod){
    //int x;
    printf("AAAAAAAAAAAAAAAAAAAA");
    //x = certeza();
    //printf("AAAAAAAAAAAAAAAAAAAA");

            if(li == NULL){
                printf("vai toma no cu");
                return 0;
                printf("If 1 passou");
            }
            Elem *no = *li;
            while (no != NULL && no->infos.codigo != cod){
                no = no->prox;
            }
            if(no == NULL){
                return 0;
                printf("If 2 passou");
            }
            if(no->ant = NULL){
                *li = no->prox;
            }else{
                no->ant->prox = no->prox;
            }
            if(no->prox != NULL){
                no->prox->ant = no->ant;
            }
            free(no);
            return 1;
}
int leiaArq(Lista *li){
    dados aux;
    arq = fopen("arquivo.txt", "rb");
    if(arq == NULL){
        return 0;
    }
    while(1){
        fread(&aux, sizeof(dados), 1, arq);
        if(feof(arq)){
            break;
        }
        insereContato(li, aux);
    }
    fclose(arq);
    return 0;
}

void salvaArq(Lista *li){
    dados *aux2;
    aux2 = (dados*) calloc(tamanhoLista(li), sizeof(dados));
    Elem *no = *li;
    int i = 0;
    arq = fopen("arquivo.txt", "wb");
    while(no != NULL){
        aux2[i] = no->infos;
        fwrite(&aux2[i], sizeof(dados), 1, arq);
        no = no->prox;
        i++;
    }
    fclose(arq);
}
