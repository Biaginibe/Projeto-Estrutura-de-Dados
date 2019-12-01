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

Lista *criaLista();

void destroiLista(Lista *li);

int insereContato(Lista *li, dados cliente);

//função tamanhoLista: encontra o total de elementos em uma lista
int tamanhoLista(Lista *li);

//função buscaPos: procura um determinado elemento da lista com base numa posição previamente mostrada
int buscaPos(Lista *li, int pos, dados *cliente);

//função relatorioGeral: executada dentro de um "for", busca todas as informações de um cliente
//funciona como uma consulta por posição, e o valor da posição em si é alteraldo dentro do switch do programa principal
int relatorioGeral(Lista *li, int pos, dados *cliente);

int buscaPorId(Lista *li, int cod, dados *cliente);

//função buscaNome: procura um cliente na lista de acordo com o nome digitado
//funciona por meio de strcmp, ao comparar o nome digitado com o nome na lista
//envia os dados encontrados para o programa principal e mostra o que for encontrado
int buscaNome(Lista *li, dados *cliente);

int lista_vazia(Lista *li);

int certeza();

int removeContato(Lista *li, int cod);

FILE *arq;

void salvaArq(Lista *li);

int leiaArq(Lista *li);
