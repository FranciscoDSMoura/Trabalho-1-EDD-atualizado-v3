#ifndef TIMES_H
#define TIMES_H
#include "time.h"

// Nó da linked list, contendo um time e o ponteiro para o próximo
typedef struct No{
    Time time;
    struct No *proximo;
} No;

// Aponta para o início da lista de times
typedef struct{
    No *inicio;
} BDTime;

// Cria uma lista vazia (banco de dados dos times)
BDTime *criar_bd_time(void);

// Libera toda a memória alocada pelo banco
void destruir_bd_time(BDTime *bd); 

void inserir_time(BDTime *bd, Time t);

// Carrega os times do arquivo times.csv
void bd_carregar_times_csv(BDTime *bd, const char *caminho_arquivo);

// Imprime as estatísticas dos times
void imprimir_cabecalho();

// Atualiza as estatísticas de um time
int atualizar_estatisticas_time(BDTime *bd, int id, Time novo);

// Busca o time pelo nome ou por seu prefixo
void buscar_por_nome(BDTime *bd, char *prefixo, int paginacao);

No* buscar_por_id(BDTime *bd, int id);

int remover_bd_times(BDTime *bd, int id);

const char* time_get_nome(No *n);

#endif