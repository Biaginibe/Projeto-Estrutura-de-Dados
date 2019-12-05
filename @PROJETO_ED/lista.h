//estrutura de dados do cliente
typedef struct dadoscliente{
    int codigo;
    char nome[50];
    char empresa[50];
    char departamento[10];
    int telefone;
    int celular;
    char email[50];
}dados;

typedef struct elemento *Lista;

//Função criaLista: Cria a lista.
//Não recebe nada do main e retorna a lista criada.
Lista *criaLista();

//Função destroiLista: Destroi a lista.
//Recebe a variavel li do main, não retorna nada.
void destroiLista(Lista *li);

//Função insereContato: inserre um contato na lista.
//Recebe as variaveis li e cliente do main, retorna 0 caso não consiga inserir o contato na lista por algum motivo e 1 caso consiga.
int insereContato(Lista *li, dados cliente);

//Função tamanhoLista: encontra o total de elementos em uma lista.
//Recebe a variavel li do main, retorna a lista criada.
int tamanhoLista(Lista *li);

//Função buscaPos: procura um determinado elemento da lista com base numa posição previamente escolhida.
//Recebe as variaveis li, posicao e cliente do main, retorna 0 caso tenha problemas durante a busca e 1 caso consiga realizar a busca.
int buscaPos(Lista *li, int pos, dados *cliente);

//Função relatorioGeral: busca todas as informações de todos os clientes. 
//Recebe as variaveis li, posicao e cliente do main, retorna 0 caso tenha problemas durante a busca e 1 caso consiga realizar a busca.
int relatorioGeral(Lista *li, int pos, dados *cliente);

//Função buscaPorId: procura um cliente na lista de acordo com o codigo digitado.
//Recebe as variaveis li, codigo e cliente do main, retorna 0 caso tenha problemas durante a busca e 1 caso consiga realizar a busca.
int buscaPorId(Lista *li, int cod, dados *cliente);

//Função buscaNome: procura um cliente na lista de acordo com o nome digitado.
//Recebe as variaveis li e &cliente do main, retorna 0 caso tenha problemas durante a busca e 1 caso consiga realizar a busca.
int buscaNome(Lista *li, dados *cliente);

//Função lista_vazia: ao ser utilizada verifica se a lista esta vazia ou não.
//Recebe a variavel li do main, retorna 1 caso a lista esteja vazia e 0 caso não esteja.
int lista_vazia(Lista *li);

//Função removeContato: procura o cliente via codigo e deleta ele da lista.
//Recebe as variaveis li e codigo do main, retona 0 caso tenha problemas para deletar o cliente e 1 caso consiga concluir o procedimento.
int removeContato(Lista *li, int cod);

FILE *arq;

//Função salvaArq: salva o arquivo em modo binário.
//Recebe a variavel li do main e não retorna nada
void salvaArq(Lista *li);

//Função leiaArq: lê o arquivo. Cria um arquivo para leitura binária se não houver. Se ja existir um arquivo com dados, a função lê os dados pré-existentes como clientes e insere na lista
//Recebe a variavel li do main, retorna 0
int leiaArq(Lista *li);

//Função editaContato: procura o contato via codigo, exibe ele caso encontrado e permite que as informações do contato sejam alteradas.
//Recebe as variaveis li e codigo, retorna 0 caso a operação seja cancelada e 1 caso seja concluida.
int editaContato(Lista *li, int cod);
