#include "bd_partidas.h"
#include "partidas.h"
#include "bd_times.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoPartida {
    Partidas partidas;
    struct NoPartida *proximo;
} NoPartida;

struct bd_partidas {
    Partidas* jogos[MAX_PARTIDAS]; 
    int quantidade;           
    NoPartida *inicio;  
};

BDPartidas* bd_partidas_criar() 
{
    BDPartidas* bdp = (BDPartidas*) malloc(sizeof(BDPartidas));
    if (bdp != NULL) {
        bdp->quantidade = 0;
        bdp->inicio = NULL;
    }
    return bdp;
}

void destruir_bd_partidas(BDPartidas *bd)
{
    if (bd == NULL) return;

    NoPartida *atual = bd->inicio;
    while (atual != NULL) {
        NoPartida *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    
    free(bd);
}

void inserir_partida(BDPartidas *bd, Partidas p)
{
    NoPartida *novo = malloc(sizeof(NoPartida));
    novo->partidas = p;
    novo->proximo = bd->inicio;
    bd->inicio = novo;
}

void imprimir_cabecalho_partidas(void)
{
    printf("%-3s  %-20s  %-12s\n", "ID", "Time1", "Time2");
}

void bd_carregar_partidas_csv(BDPartidas *bd, const char *caminho_arquivo)
{
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", caminho_arquivo);
        return;
    }

    char linha[100];
    fgets(linha, sizeof(linha), arquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        Partidas p = analisa_partidas(linha);
        inserir_partida(bd, p);
    }
    fclose(arquivo);
}

void imprimir_todas_partidas(BDPartidas *bd_p, BDTime *bd_t, int paginacao)
{
    NoPartida *atual = bd_p->inicio;
    int cont = 0;

    imprimir_cabecalho_partidas();

    while (atual) {
        imprimir_partidas(atual->partidas, bd_t);
        atual = atual->proximo;
        cont++;

        if (cont % paginacao == 0) {
            char op;
            printf("\n-- Página %d -- ENTER p/ continuar, Q p/ sair: ", cont / paginacao);
            op = getchar();
            if (op == 'Q' || op == 'q') break;
            imprimir_cabecalho_partidas();
        }
    }
}

void buscar_por_mandante(BDPartidas *bd_p, BDTime *bd_t, int paginacao)
{
    printf("Digite o nome:\n");
    char prefixo[100];
    scanf("%99s", prefixo);
    getchar();

    NoPartida *atual = bd_p->inicio;
    int cont = 0;
    int encontrou = 0;
    int tamanho_prefixo = strlen(prefixo);

    while (atual) {
        Partidas p = atual->partidas;
        
        void *mandante = buscar_por_id(bd_t, p.id_time1);

        const char *nome_m = mandante ? time_get_nome(mandante) : "";

        int verifica_mandante = (strncasecmp(nome_m, prefixo, tamanho_prefixo) == 0);

        if (verifica_mandante) {
            if (encontrou == 0) {
                imprimir_cabecalho_partidas();
                encontrou = 1;
            }

            imprimir_partidas(p, bd_t);
            cont++;

            if (cont % paginacao == 0) {
                char op;
                printf("\n-- Página %d -- ENTER p/ continuar, Q p/ sair: ", cont / paginacao);
                op = getchar();
                if (op == 'Q' || op == 'q') break;
                imprimir_cabecalho_partidas();
            }
        }
        atual = atual->proximo;
    }

    if (!encontrou) {
        printf("Nenhuma partida encontrada envolvendo o time com o prefixo informado.\n");
    }
}

void buscar_por_visitante(BDPartidas *bd_p, BDTime *bd_t, int paginacao)
{
    printf("Digite o nome:\n");
    char prefixo[100];
    scanf("%99s", prefixo);
    getchar();

    NoPartida *atual = bd_p->inicio;
    int cont = 0;
    int encontrou = 0;
    int tamanho_prefixo = strlen(prefixo);

    while (atual) {
        Partidas p = atual->partidas;
        
        void *visitante = buscar_por_id(bd_t, p.id_time2);

        const char *nome_v = visitante ? time_get_nome(visitante) : "";

        int verifica_visitante = (strncasecmp(nome_v, prefixo, tamanho_prefixo) == 0);

        if (verifica_visitante) {
            if (encontrou == 0) {
                imprimir_cabecalho_partidas();
                encontrou = 1;
            }

            imprimir_partidas(p, bd_t);
            cont++;

            if (cont % paginacao == 0) {
                char op;
                printf("\n-- Página %d -- ENTER p/ continuar, Q p/ sair: ", cont / paginacao);
                op = getchar();
                if (op == 'Q' || op == 'q') break;
                imprimir_cabecalho_partidas();
            }
        }
        atual = atual->proximo;
    }

    if (!encontrou) {
        printf("Nenhuma partida encontrada envolvendo o time com o prefixo informado.\n");
    }
}

void buscar_por_m_ou_v(BDPartidas *bd_p, BDTime *bd_t, int paginacao)
{
    printf("Digite o nome:\n");
    char prefixo[100];
    scanf("%99s", prefixo);
    getchar();

    NoPartida *atual = bd_p->inicio;
    int cont = 0;
    int encontrou = 0;
    int tamanho_prefixo = strlen(prefixo);

    while (atual) {
        Partidas p = atual->partidas;
        
        void *mandante = buscar_por_id(bd_t, p.id_time1);
        void *visitante = buscar_por_id(bd_t, p.id_time2);

        const char *nome_m = mandante ? time_get_nome(mandante) : "";
        const char *nome_v = visitante ? time_get_nome(visitante) : "";

        int verifica_mandante = (strncasecmp(nome_m, prefixo, tamanho_prefixo) == 0);
        int verifica_visitante = (strncasecmp(nome_v, prefixo, tamanho_prefixo) == 0);

        if (verifica_mandante || verifica_visitante) {
            if (encontrou == 0) {
                imprimir_cabecalho_partidas();
                encontrou = 1;
            }

            imprimir_partidas(p, bd_t);
            cont++;

            if (cont % paginacao == 0) {
                char op;
                printf("\n-- Página %d -- ENTER p/ continuar, Q p/ sair: ", cont / paginacao);
                op = getchar();
                if (op == 'Q' || op == 'q') break;
                imprimir_cabecalho_partidas();
            }
        }
        atual = atual->proximo;
    }

    if (!encontrou) {
        printf("Nenhuma partida encontrada envolvendo o time com o prefixo informado.\n");
    }
}

