#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include "lista.h"



int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, DontStop = 0;
    Lista *li;
    li = criaLista();
    while(DontStop == 0){
        printf("\tLista de contatos\n\n");
        printf("0- Sair e encerrar o programa.\n"
                "1- Inser��o de novo contato\n"
                "2- Gerar e exibir relat�rio de contatos em forma de lista total\n"
                "3- Gerar e exibir relat�rio individual com busca por identificador\n"
                "4- Gerar e exibir relat�rio com busca por nome\n"
                "5- Edi��o de dados do contato, escolhido por identificador\n"
                "6- Remover contato, escolhido por identificador\n"
                "Op��o:");
                scanf("%d", &opcao);
                criaLista();
                switch(opcao){
                    case 0:
                        //COM ESSA VARIAVEL RECEBENDO 1 VAI SAIR DO WHILE E ENCERRAR O PROGRAMA
                        DontStop = 1;
                        break;
                    case 1:
                        //ZARA ENT, VOU DEIXAR OS PARAMETROS VAZIOS MAS CONFORME A GENTE FOR VENDO O QUE PRECISA A GENTE VAI PREENCHENDO BLZ?
                        dados cliente;
                        printf("Digite o seu codigo: ");
                        scanf("%d", &cliente.codigo);
                        printf("Digite o seu nome: ");
                        fflush(stdi);
                        gets(cliente.nome);
                        printf("Digite o nome da empresa: ");
                        gets(cliente.empresa);
                        printf("Em qual departamento você trabalha?");
                        gets(cliente.departamento);
                        printf("Digite seu email: ");
                        gets(cliente.email);
                        printf("Telefone fixo para contato:")
                        scanf("%d", &cliente.telefone);
                        printf("Celular para contato:")
                        scanf("%d", &cliente.celular);
                        int x = insereContato(li, cliente);
                        if(x){
                            printf("Dados inseridos com sucesso");
                        }else{
                            printf("Erro ao inserir dados");
                        }
                        break;
                    case 2:
                        //apresentar todos os dados
                        int tamanho = tamanhoLista(li);//fiz isso aqui mas se não for precisar pode apagar
                        relatorioTotal();
                        break;
                    case 3:
                        //apresentar todos os dados
                        buscaPorId();//o Id aqui vai ser o codigo né? Sim é o cod
                        break;
                    case 4:
                        //apresentar todos os dados
                        buscaNome(li, nome/*, &cliente*/);//tirar duvida com ele de pq passou o endereço do aluno no exemplo
                        break;
                    case 5:
                        //aqui eu pensei em fazer uma função que leva pra uma 'pagina' onde a pessoa ve como tava
                        //e digita como quer que fique e seria legal tb se a gente perguntasse se o usuario tem ctz
                        editaContato();
                        break;
                    case 6:
                        //aqui tbm seria legal perguntar se tem ctz pq né... nao vai ter volta
                        //sim é melhor, 
                        removeContato();

               }

               //NÃO COLOCAR NADA DEPOIS DISSO
               destroiLista(li);
    }

    return 0;
}
