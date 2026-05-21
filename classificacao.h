#ifndef CLASSIFICACAO_H
#define CLASSIFICACAO_H

// Importa interfaces públicas
#include "time.h"
#include "bd_partidas.h"
#include "partidas.h"

// Calcula a pontuação de um time após todas as partidas
void calcula_pontuacoes_time(Time *t, Partidas p);

// Registra no banco de dados de time a pontuação completa de cada um dos times
void classificacao_completa(void *bd_t, BDPartidas *bd_p);

// Salva a pontuação completa dos times no arquivo bd_classificacao.csv
void bd_salvar_arquivo_classificacao(void *bd_t, BDPartidas *bd_p, const char *caminho_arquivo);

#endif