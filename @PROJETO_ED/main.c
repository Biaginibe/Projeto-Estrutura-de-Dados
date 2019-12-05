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
    leiaArq(li);

    while(DontStop == 0){
        printf("\tLista de contatos\n\n");
        printf("0- Sair e encerrar o programa.\n"
                "1- Insere de novo contato\n"
                "2- Gerar e exibir relatorio de contatos em forma de lista total\n"
                "3- Gerar e exibir relatorio individual com busca por identificador\n"
                "4- Gerar e exibir relatorio com busca por nome\n"
                "5- Edicao de dados do contato, escolhido por identificador\n"
                "6- Remover contato, escolhido por identificador\n"
                "Opcao:");
                scanf("%d", &opcao);

                switch(opcao){
                    case 0:
                        //COM ESSA VARIAVEL RECEBENDO 1 VAI SAIR DO WHILE E ENCERRAR O PROGRAMA
                        DontStop = 1;
                        break;
                    case 1:
                        system("cls");
                        printf("\tINSERIR CONTATO\n\n");
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

                        int x = insereContato(li, cliente);
                        if(x){
                            printf("Dados inseridos com sucesso\n\n");
                        }else{
                            printf("Erro ao inserir dados\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        //apresentar todos os dados
                        system("cls");
                        printf("\tEXIBIR TODOS OS CONTATOS\n\n");
                        tamanho = tamanhoLista(li);
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
                        printf("\tEXIBIR CONTATO POR ID \n\n");
                        printf("Digite o codigo que deseja procurar: ");
                        scanf("%d", &codigo);
                        x = buscaPorId(li, codigo, &cliente);
                        if(x){
                            printf("\nDados encontrados na busca...\n\n");
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Nome do Cliente: %s\n", cliente.nome);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("Email do Cliente: %s\n", cliente.email);
                        }else{
                            printf("Erro na busca!!");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        //apresentar todos os dados de um ou mais caras (caso tenha o mesmo nome)
                        system("cls");
                        printf("\tEXIBIR CONTATO POR NOME \n\n");
                        x = buscaNome(li, &cliente);
                        if(x){
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Nome do Cliente: %s\n", cliente.nome);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("Email do Cliente: %s\n", cliente.email);
                        }else{
                            printf("Erro na busca!!");

                        }
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        system("cls");
                        printf("\tEDITAR CONTATO\n\n");
                        printf("Digite o codigo do cliente que você deseja editar: ");
                        scanf("%d", &codigo);
                        x = buscaPorId(li, codigo, &cliente);
                        if(x){
                            printf("Dados atuais do cliente:\n\n");
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Nome do Cliente: %s\n", cliente.nome);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("Email do Cliente: %s\n", cliente.email);
                        }else{
                            printf("Verifique se esse contato existe e tente novamente.\n");
                        }
                        x = editaContato(li, codigo);
                        if(x){
                            printf("\nInformacoes editadas com sucesso!!\n");
                        }else{
                            printf("\nA operacao foi cancelada.\n");
                        }

                        //editaContato();
                        break;
                    case 6:
                        system("cls");
                        printf("\tREMOVER CONTATO\n\n");
                        printf("Digite o codigo do cliente que você deseja remover: ");
                        scanf("%d", &codigo);
                        x = buscaPorId(li, codigo, &cliente);
                        if(x){
                            printf("Codigo: %d\n", cliente.codigo);
                            printf("Nome do Cliente\n: %s", cliente.nome);
                            printf("Empresa: %s\n", cliente.empresa);
                            printf("Departamento: %s\n", cliente.departamento);
                            printf("Telefone: %d\n", cliente.telefone);
                            printf("Celular: %d\n", cliente.celular);
                            printf("Email do Cliente: %s\n", cliente.email);
                            x = removeContato(li, codigo);
                                if(x){
                                    printf("Dados removidos com sucesso\n\n");
                                }else{
                                    printf("a operação foi cancelada!!n");
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
    salvaArq(li);
    destroiLista(li);

    return 0;

}
