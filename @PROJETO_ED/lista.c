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
    //Aloca memoria
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    //retorna a lista criada para o main
    return li;
}

void destroiLista(Lista *li){
    //se a lista não estiver vazia o no vai rodar elemento por elemento liberando a memoria que eles ocupam, ou seja, apagando o elemento
    //e ao terminar a cabeça da lista tb terá sua memoria liberada
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
    //verifica se a lista esta vazia
    if(li == NULL ){
        return 0;
    }
    //aloca memoria para o no
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    //joga as informações recolhidas no main para a variavel no no campo infos
    no->infos = cliente;
    if(lista_vazia(li)){//insere no inicio ja que vai ser o primeiro elemento da lista
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        //aloca memoria para novos ponteiros
        Elem *anterior, *atual = *li;
        //anda na lista
        while(atual != NULL && atual->infos.codigo < cliente.codigo){
            anterior = atual;
            atual = atual->prox;
        }
        //insere o contato no inicio
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
            //insere o contato no meio ou no fim
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
    //verifica se a lista esta vazia
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    //aloca memoria pro no, depois ele anda na lista contando cada elemento q passar
    Elem *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    //reorna o numero de elementos da lista pro main
    return acum;
}

//função buscaPos: procura um determinado elemento da lista com base numa posição previamente mostrada
int buscaPos(Lista *li, int pos, dados *cliente){
    //verifica se a lista ta vazia ou se a posição é negativa
    if(li == NULL || pos <= 0){
        return 0;
    }
    //aloca memoria para o no
    Elem *no = *li;
    int i = 1;
    //enquanto não encontrar o codigo que ta sendo buscado o no continuara percorrendo a lista
    while(no!=NULL && i<pos){
        no = no->prox;
        i++;
    }
    //se entrar nesse if significa que percorreu a lista toda e não encontrou
    if(no==NULL){
        return 0;
    }else{//caso isso não aconteça devolve para cliente as informações de onde o no parou
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

//O ERRO DE ENDERECO ESTA DANDO NO ELSE ALI...
int removeContato(Lista *li, int cod){
    //int x;
    printf("AAAAAAAAAAAAAAAAAAAA");
    //x = certeza();
    //printf("AAAAAAAAAAAAAAAAAAAA");

            if(li == NULL){
                printf("vai toma no cu");
                return 0;
            }
            printf("If 1 passou");
            Elem *no = *li;
            printf("Criou o nó");
            while (no != NULL && no->infos.codigo != cod){
                no = no->prox;
            }
            printf("\n\nSAIU DO WHILE");
            //VERIFICA PASSOU PELA LISTA TODA E NÃO ENCONTROU O ELEMENTO
            if(no == NULL){
                return 0;
            }
            printf("\n\nIF 2 PASSOU");
            //IF 3
            if(no->ant = NULL){//VERIFICA SE É O PRIMEIRO ELEMENTO DA LISTA
                printf("\n\nENTROU NO IF 3");
                *li = no->prox;
            }else{
                printf("\n\nENTROU NO ELSE 3");
                no->ant->prox = no->prox;
            }
            printf("\n\nIF 3 PASSOU");
            if(no->prox != NULL){//REMOVE NO ULTIMO
                printf("\n\nENTROU NO IF 4");
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

int editaContato(Lista *li, int cod){
    //verifica se a lista ta vazia
    if(li == NULL){
        return 0;
    }
    //cria o nó
    Elem *no = *li;
    //com o nó anda pela lista até encontrar o codigo desejado
    while (no != NULL && no->infos.codigo != cod){
        no = no->prox;
    }
    //pede os dados novos e guarda tudo dentro da variavel local cliente
    dados cliente;

    printf("Agora digite como os novos dados desse cliente: \n\n");
    printf("Digite o codigo do cliente: ");
    scanf("%d", &cliente.codigo);
    printf("Digite o nome do cliente: ");
    fflush(stdin);
    gets(cliente.nome);
    printf("Digite o nome da empresa: ");
    gets(cliente.empresa);
    printf("Em qual departamento que ele trabalha?");
    gets(cliente.departamento);
    printf("Digite o email do cliente: ");
    gets(cliente.email);
    printf("Telefone fixo para contato:");
    scanf("%d", &cliente.telefone);
    printf("Celular para contato:");
    scanf("%d", &cliente.celular);
    int ctz;
    printf("Tem certeza que deseja editar essas informações?\n1-sim\n2-nao\nOpcao: ");
    scanf("%d", &ctz);
    //se o usuario confirmar que deseja alterar os dados substitui os dados da lista pelos que guardamos nas variaveis locais
    if(ctz==1){
        no->infos.codigo = cliente.codigo;
        strcpy(no->infos.nome, cliente.nome);
        strcpy(no->infos.empresa, cliente.empresa);
        strcpy(no->infos.departamento, cliente.departamento);
        strcpy(no->infos.email, cliente.email);
        no->infos.telefone = cliente.telefone;
        no->infos.celular = cliente.celular;
        return 1;
    }else{
        return 0;
    }
}
