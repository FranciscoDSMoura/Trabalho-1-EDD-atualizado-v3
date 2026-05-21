#ifndef TIMES_H
#define TIMES_H

// Importa uma interface pública
#include "time.h"

// Nó da linked list, contendo um time e o ponteiro para o próximo
typedef struct NoTime{
    Time time;
    struct NoTime *proximo;
} NoTime;

// Aponta para o início da lista de times
typedef struct{
    NoTime *inicio;
} BDTime;

// Cria uma lista vazia (banco de dados dos times)
BDTime *criar_bd_time(void);

// Libera toda a memória alocada pelo banco
void destruir_bd_time(BDTime *bd); 

// Insere as informações de um time no banco de dados
void inserir_time(BDTime *bd, Time t);

// Carrega os times do arquivo times.csv
void bd_carregar_times_csv(BDTime *bd, const char *caminho_arquivo);

// Imprime o cabeçalho de time
void imprimir_cabecalho();

// Busca o time pelo nome ou por seu prefixo
void buscar_por_nome(BDTime *bd_t, void *bd_p, char *prefixo, int paginacao);

// Encontra um time através de seu ID
NoTime* buscar_por_id(BDTime *bd, int id);

// Busca o nome do time
const char* time_get_nome(NoTime *n);

// Salva todas as partidas em um arquivo
void bd_salvar_arquivo(BDTime *bd, const char *caminho_arquivo)

// Atualiza as estatísticas de um time no banco de dados
//int atualizar_estatisticas_time(BDTime *bd, int id, Time novo);

// Remove um time do banco de dados
//int remover_bd_times(BDTime *bd, int id);

#endif