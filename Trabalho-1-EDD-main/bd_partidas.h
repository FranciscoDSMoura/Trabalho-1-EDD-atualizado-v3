#ifndef BD_PARTIDAS_H
#define BD_PARTIDAS_H
#include "partidas.h"
#include "bd_times.h"

#define MAX_PARTIDAS 100

typedef struct bd_partidas BDPartidas;

BDPartidas* bd_partidas_criar();

void destruir_bd_partidas(BDPartidas *bd);

//int bd_partidas_carregar(BDPartidas* bd_p, const char* caminho_arquivo);
void bd_carregar_partidas_csv(BDPartidas *bd, const char *caminho_arquivo);

void inserir_partida(BDPartidas *bd, Partidas p);

// Imprime o cabeçalho das partidas
void imprimir_cabecalho();

// Busca e imprime as partidas do time mandante escolhido
void buscar_por_mandante(BDPartidas *bd_p, BDTime *bd_t, int paginacao);

// Busca e imprime as partidas do time visitante escolhido
void buscar_por_visitante(BDPartidas *bd_p, BDTime *bd_t, int paginacao);

// Busca e imprime as partidas do time escolhido, seja ele mandante ou visitante
void buscar_por_m_ou_v(BDPartidas *bd_p, BDTime *bd_t, int paginacao);

#endif
