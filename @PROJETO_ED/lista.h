
//estrutura de dados do cliente
typedef struct dadoscliente{
    int codigo;
    char nome[20];
    char empresa[20];
    char departamento[10];
    int telefone;
    int celular;
    char email[20];
}dados;

typedef struct elemento *Lista;

Lista *criaLista();

void destroiLista(Lista *li);

int insereContato(Lista *li, dados cliente);

int tamanhoLista(Lista *li);

int buscaPos(Lista *li, int pos, dados *cliente);

void relatorioGeral();