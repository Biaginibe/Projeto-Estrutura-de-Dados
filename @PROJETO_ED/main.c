#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include "lista.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, DontStop = 0;
    while(DontStop == 0){
        printf("\tLista de contatos\n\n");
        printf("0- Sair e encerrar o programa.\n"
                "1- Inserção de novo contato\n"
                "2- Gerar e exibir relatório de contatos em forma de lista total\n"
                "3- Gerar e exibir relatório individual com busca por identificador\n"
                "4- Gerar e exibir relatório com busca por nome\n"
                "5- Edição de dados do contato, escolhido por identificador\n"
                "6- Remover contato, escolhido por identificador\n"
                "Opção:");
                scanf("%d", &opcao);
                criaLista();
                switch(opcao){
                    case 0:
                        //COM ESSA VARIAVEL RECEBENDO 1 VAI SAIR DO WHILE E ENCERRAR O PROGRAMA
                        DontStop = 1;
                        break;
                    case 1:
                        //ZARA ENT, VOU DEIXAR OS PARAMETROS VAZIOS MAS CONFORME A GENTE FOR VENDO O QUE PRECISA A GENTE VAI PREENCHENDO BLZ?
                        insercaoContato();
                        break;
                    case 2:
                        //apresentar todos os dados
                        relatorioTotal();
                        break;
                    case 3:
                        //apresentar todos os dados
                        buscaPorId();
                        break;
                    case 4:
                        //apresentar todos os dados
                        buscaNome();
                        break;
                    case 5:
                        //aqui eu pensei em fazer uma função que leva pra uma 'pagina' onde a pessoa ve como tava
                        //e digita como quer que fique e seria legal tb se a gente perguntasse se o usuario tem ctz
                        editaContato();
                        break;
                    case 6:
                        //aqui tbm seria legal perguntar se tem ctz pq né... não vai ter volta
                        removeContato();

               }
    }

    return 0;
}
