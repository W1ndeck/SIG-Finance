#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "relatorios.h"
#include "../auxiliares/funcoes_auxiliares.h"
#include "../M3_/despesas_main.h"
#include "../M2_/receitas_main.h"
#include "../M1_/cadastro_moradores_main.h"

void interacao_menu_relatorios(void)
{

    char op;
    op = menu_relatorios();
    while (op != '0')
    {

        if (op == '1')
        {
            checar_dp();
        }

        else if (op == '2')
        {
            checar_re();
        }

        else if (op == '4')
        {
            buscar_receita();
        }

        else if (op == '3')
        {
            buscar_despesa();
        }

        else if (op == '5')
        {
            buscarUm();
        }

        else if (op == '6')
        {
            RelatorioValorReceita(1);
            getchar();
        }
        else if (op == '7')
        {
            RelatorioValorReceita(2);
            getchar();
        }

        else
        {
            printf("\n\t Opção invalida. digite outra...");
            getchar();
        }

        op = menu_relatorios();
    }
}

char menu_relatorios(void)
{
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =          SIG - FINANCE         = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = =           Relatórios           = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Mostrar todas as Despesas                                 ///\n");
    printf("///            2. Mostrar todas as Recetias                                 ///\n");
    printf("///            3. Pesquisar Despesa por ID                                  ///\n");
    printf("///            4. Pesquisar Receita por ID                                  ///\n");
    printf("///            6. Pesquisar Receita em ordem de Maior valor                 ///\n");
    printf("///            7. Pesquisar Receita em ordem de Menor valor                 ///\n");
    printf("///            5. Pesquisar Morador por CPF                                 ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Selecione sua opção:");
    scanf("%c", &op);
    getchar();
    return op;
}

void RelatorioValorReceita(int num)
{
    FILE *fp;
    Receita *rec;
    RecDin *novo;
    RecDin *lista;

    if (access("cad-receita-m2.dat", F_OK) != -1)
    {
        /* code */
        fp = fopen("cad-receita-m2.dat", "rb");

        if (fp == NULL)
        {

            printf("Erro na abertura do arquivo");
            exit(1);
        }

        else
        {
            /* code */
            lista = NULL;

            rec = (Receita *)malloc(sizeof(Receita));

            while (fread(rec, sizeof(Receita), 1, fp))
            {
                /* code */
                if (rec->status == 'C')
                {
                    /* code */
                    novo = (RecDin*)malloc(sizeof(RecDin));

                    strcpy(novo->cpf, rec->cpf);
                    strcpy(novo->descricao, rec->descricao);
                    strcpy(novo->data, rec->data);
                    novo->valor = rec->valor;
                    novo->tipo = rec->tipo;
                    novo->status = rec->status;
                    novo->id = rec->id;

                    if (num == 1)
                    {
                        if (lista == NULL)
                        {
                            lista = novo;
                            novo->prox = NULL;
                        }

                        else if (novo->valor > lista->valor)
                        {
                            novo->prox = lista;
                            lista = novo;
                        }

                        else
                        {
                            RecDin *anter = lista;
                            RecDin *atual = lista->prox;

                            while ((atual != NULL) && atual->valor > novo->valor)
                            {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;
                        }
                    }

                    else
                    {
                        if (lista == NULL)
                        {
                            lista = novo;
                            novo->prox = NULL;
                        }

                        else if (novo->valor < lista->valor)
                        {
                            novo->prox = lista;
                            lista = novo;
                        }

                        else
                        {
                            RecDin *anter = lista;
                            RecDin *atual = lista->prox;

                            while ((atual != NULL) && atual->valor < novo->valor)
                            {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novo;
                            novo->prox = atual;
                        }
                    }
                }
            }

            free(rec);

            novo = lista;
            while (novo != NULL)
            {

                mostrarRecdin(novo);
                novo = novo->prox;
            }

            novo = lista;
            while (lista != NULL)
            {
                lista = lista->prox;
                // free(novo->nome);
                // free(novo->status);
                free(novo);
                novo = lista;
            }
        }

        fclose(fp);
    }
}