typedef struct despesa Despesa;
typedef struct desdin Desdin;
struct despesa
{
    char cpf[15];
    char descricao[100];
    float valor;
    char tipo;
    char data[11];
    char status;
    char sitacao;
    int id;
};

struct desdin
{
    char cpf[15];
    char descricao[100];
    float valor;
    char tipo;
    char data[11];
    char status;
    char sitacao;
    int id;
    Desdin *prox;
};


void preenche_despesa(void);
void mostrarDesepesa(Despesa *newdespesa);
void mostrarDesDin(Desdin *novo);
void gravarDesepesa(Despesa *newdespesa);
// void exibe_receita(Despesa* desp);

void buscar_despesa(void);
char menu_principal_dp(void);
void gerencia_menu_principal_dp(void);
char ler_dp(void);
void editar_dp(void);
void excluir_dp(void);
void checar_dp(void);
void sobre_dp(void);
void pagar_dp(void);
char tipos_despesa(void);
