#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lista.h"



int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, DontStop = 0, codigo;
    Lista *li;
    li = criaLista();
    dados cliente;
    int pos = 0, i, tamanho;
    char nome[50];
    while(DontStop == 0){
        printf("\tLista de contatos\n\n");
        printf("0- Sair e encerrar o programa.\n"
                "1- Insere de novo contato\n"
                "2- Gerar e exibir relatório de contatos em forma de lista total\n"
                "3- Gerar e exibir relatório individual com busca por identificador\n"
                "4- Gerar e exibir relatório com busca por nome\n"
                "5- Edição de dados do contato, escolhido por identificador\n"
                "6- Remover contato, escolhido por identificador\n"
                "Opção:");
                scanf("%d", &opcao);

                switch(opcao){
                    case 0:
                        //COM ESSA VARIAVEL RECEBENDO 1 VAI SAIR DO WHILE E ENCERRAR O PROGRAMA
                        DontStop = 1;
                        break;
                    case 1:
                        //ZARA ENT, VOU DEIXAR OS PARAMETROS VAZIOS MAS CONFORME A GENTE FOR VENDO O QUE PRECISA A GENTE VAI PREENCHENDO BLZ?
                        system("cls");
                        printf("Digite o seu codigo: ");
                        scanf("%d", &cliente.codigo);
                        printf("Digite o seu nome: ");
                        fflush(stdin);
                        gets(cliente.nome);
                        printf("Digite o nome da empresa: ");
                        gets(cliente.empresa);
                        printf("Em qual departamento você trabalha?");
                        gets(cliente.departamento);
                        printf("Digite seu email: ");
                        gets(cliente.email);
                        printf("Telefone fixo para contato:");
                        scanf("%d", &cliente.telefone);
                        printf("Celular para contato:");
                        scanf("%d", &cliente.celular);

                        int x = insereContato(li, cliente);
                        if(x){
                            printf("Dados inseridos com sucesso\n\n");
                        }else{
                            printf("Erro ao inserir dados\n\n");
                        }

                        tamanho = tamanhoLista(li);
                        printf("o tamanho é %d", tamanho);
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        //apresentar todos os dados
                        //relatorioTotal(li, &cliente);
                        system("cls");
                        tamanho = tamanhoLista(li);
                        printf("o tamanho é %d\n", tamanho);
                        for(i=0;i<tamanho;i++){
                            int x = relatorioGeral(li, pos, &cliente);
                            if(x){
                                printf("\nCódigo do Cliente: %d", cliente.codigo);
                                printf("\nNome do Cliente: %s", cliente.nome);
                                printf("\nEmpresa do Cliente: %s", cliente.empresa);
                                printf("\nDepartamento do Cliente: %s", cliente.departamento);
                                printf("\nTelefone do Cliente: %d ", cliente.telefone);
                                printf("\nCelular do Cliente: %d", cliente.celular);
                                printf("\nEmail do Cliente: %s\n", cliente.email);
                                pos++;
                            }else{
                                printf("Erro na consulta\n");
                            }
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 3:

                        //apresentar todos os dados
                        system("cls");
                        printf("Digite o codigo que deseja procurar: ");
                        scanf("%d", &codigo);
                        x = buscaPorId(li, codigo, &cliente);//o Id aqui vai ser o codigo né? Sim é o cod
                        if(x){
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("\nEmail do Cliente: %s\n", cliente.email);
                        }else{
                            printf("Erro na busca!!");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        //apresentar todos os dados de um ou mais caras (caso tenha o mesmo nome)
                        system("cls");
                      
                        x = buscaNome(li, &cliente);//tirar duvida com ele de pq passou o endereço do aluno no exemplo
                        if(x){
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("\nEmail do Cliente: %s\n", cliente.email);
                        }else{
                            printf("Erro na busca!!");
                            
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        //aqui eu pensei em fazer uma função que leva pra uma 'pagina' onde a pessoa ve como tava
                        //e digita como quer que fique e seria legal tb se a gente perguntasse se o usuario tem ctz
                        //editaContato();
                        break;
                    case 6:
                        //aqui tbm seria legal perguntar se tem ctz pq né... nao vai ter volta
                        //sim é melhor
                        //blz ent
                        system("cls");
                        printf("Digite o codigo do cliente que você deseja remover: ");
                        scanf("%d", &codigo);
                        x = buscaPorId(li, codigo, &cliente);
                        if(x){
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("\nEmail do Cliente: %s\n", cliente.email);
                            //x = certeza();
                            //printf("Tem certeza que deseja remover o cliente acima?\n1-sim\n2-não");
                            //scanf("%d", meucu);
                            //if(meucu == 1)
                                x = removeContato(li, codigo);
                                if(x){
                                printf("Dados removidos com sucesso\n\n");
                                }else{
                                printf("Erro ao remover dados\n\n");
                                }

                        }else{
                            printf("Erro na busca!!");
                            printf("\n%s", nome);
                        }
                        system("pause");
                        system("cls");
                        break;

               }

               //NÃO COLOCAR NADA DEPOIS DISSO

    }
    destroiLista(li);
    return 0;
}
