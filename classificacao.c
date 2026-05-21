// Importa a própria interface pública
#include "classificacao.h"

// importa as bibliotecas padrões do C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Importa interfaces públicas
#include "bd_times.h"
#include "bd_partidas.h"

void calcula_pontuacoes_time(Time *t, Partidas p){
    // Calcula as pontuações que o time fez em casa
    if (t->id == p.id_time1){
        if(p.gols_time1 > p.gols_time2){
            t->vitorias += 1;
        } else if(p.gols_time1 < p.gols_time2){
            t->derrotas += 1;
        } else {
            t->empates += 1;
        }
        t->gols_m += p.gols_time1;
        t->gols_s += p.gols_time2;

    // Calcula as pontuações que o time fez fora de casa
    } else if (t->id == p.id_time2){
        if(p.gols_time1 < p.gols_time2){
            t->vitorias += 1;
        } else if(p.gols_time1 > p.gols_time2){
            t->derrotas += 1;
        } else {
            t->empates += 1;
        }
        t->gols_m += p.gols_time2;
        t->gols_s += p.gols_time1;
    }

    t->pontos_ganhos = t->vitorias * 3 + t->empates; // Calucla os pontos ganhos do time em todo o campeonato (V * 3 + E)
    t->saldo_gols = t->gols_m - t->gols_s; // Calcula o saldo final de gols
}

void classificacao_completa(void *bd_t, BDPartidas *bd_p)
{
    BDTime *bd = (BDTime *)bd_t;
    NoTime *atual_time = bd->inicio;

    // Percorre enqunto ainda tiver informações a obter de um único time
    while (atual_time) {
        atual_time->time.vitorias = 0;
        atual_time->time.empates = 0;
        atual_time->time.derrotas = 0;
        atual_time->time.gols_m = 0;
        atual_time->time.gols_s = 0;
        atual_time->time.saldo_gols = 0;
        atual_time->time.pontos_ganhos = 0;

        NoPartida *atual_partida = bd_p->inicio; 
        // Calcula as informações de um time por partida
        while (atual_partida) {
            calcula_pontuacoes_time(&(atual_time->time), atual_partida->partidas); 
            atual_partida = atual_partida->proximo;
        }

        atual_time = atual_time->proximo;
    }
}

void bd_salvar_arquivo_classificacao(void *bd_t, BDPartidas *bd_p, const char *caminho_arquivo) 
{
    FILE *arquivo = fopen(caminho_arquivo, "w"); // Abre arquivo para escrita
    if (!arquivo) {
        printf("Erro ao salvar em %s\n", caminho_arquivo); // Mensagem de erro
        return;
    }
    BDTime *bd = (BDTime *)bd_t;
    classificacao_completa(bd_t, bd_p);

    fprintf(arquivo, "%-3s  %-10s  %-3s  %-3s  %-3s  %-3s  %-3s  %-3s  %-3s\n",
           "ID", "Time", "V", "E", "D", "GM", "GS", "S", "PG"); // Cabeçalho classificacao CSV
    NoTime *atual = bd->inicio;
    while (atual) {
        Time t = atual->time;
        fprintf(arquivo, "%-3d  %-10s  %-3d  %-3d  %-3d  %-3d  %-3d  %-3d  %-3d\n", // Escreve as informaçõoes do time
                t.id, t.nome, t.vitorias, t.empates, t.derrotas, t.gols_m, t.gols_s, t.saldo_gols, t.pontos_ganhos);
        atual = atual->proximo;
    }
    fclose(arquivo); // Fecha arquivo
}

