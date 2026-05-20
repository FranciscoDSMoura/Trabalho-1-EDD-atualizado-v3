#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void calcula_ponto_ganho(Time *t){
    t->pontos_ganhos = 0;
    
    if(t->vitorias != -90 || t->gols_s != -90){
        t->pontos_ganhos += t->empates;
        t->pontos_ganhos += t->vitorias * 3;
    }
}

void calcula_saldo_gols(Time *t){
    t->saldo_gols = 0;
    
    if(t->gols_m != -90 || t->gols_s != -90)
        t->saldo_gols += t->gols_m - t->gols_s;
}

// Converte uma linha CSV em um struct Time
Time analisa_time(char *linha_csv)
{
    Time t;
    char *token;

    token = strtok(linha_csv, ","); // ID
    t.id = token ? atoi(token) : 0;

    token = strtok(NULL, ","); // Nome
    strncpy(t.nome, token ? token : "", sizeof(t.nome));
    t.nome[sizeof(t.nome) - 1] = '\0';

    t.nome[strcspn(t.nome, "\r\n")] = '\0';

    t.vitorias = 0;
    t.empates = 0;
    t.derrotas = 0;
    t.gols_m = 0;
    t.gols_s = 0;
    calcula_saldo_gols(&t);
    calcula_ponto_ganho(&t);

    return t;
}

// Imprime dados do paciente formatado em tabela
void imprimir_time(Time t)
{
    
    printf("%-3d  %-10s  %-1d  %-1d  %-1d  %-2d  %-2d  %-2d  %-2d\n",
           t.id, t.nome, t.vitorias, t.empates, t.derrotas, t.gols_m, t.gols_s, t.saldo_gols, t.pontos_ganhos);
}
