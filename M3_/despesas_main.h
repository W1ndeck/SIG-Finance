typedef struct despesa Despesa;

struct despesa
{
    char morador[15];
    char descricao[100];
    char valor[11];
    char tipo;
    char status;
    char estrutura;
};

void preenche_despesa(void);
void mostrarDesepesa(Despesa *newdespesa);
void gravarDesepesa(Despesa *newdespesa);
// void exibe_receita(Despesa* desp);

char menu_principal_dp(void);
void gerencia_menu_principal_dp(void);
char ler_dp(void);
void editar_dp(void);
void excluir_dp(void);
void checar_dp(void);
void sobre_dp(void);
void pagar_dp(void);
char tipos_d(void);
