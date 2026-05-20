#ifndef TIME_H
#define TIME_H

/*
 * TAD Time
 * Representa os dados de um time no sistema.
 */

typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_m;
    int gols_s;
    int pontos_ganhos;
    int saldo_gols;
} Time;


// Calcula os pontos totais ganhos no campeonato (Vitórias + empates)
void calcula_ponto_ganho(Time *t);

// Calcula o total de gols marcados - gols sofridos
void calcula_saldo_gols(Time *t);

// Remove , e calcula a pontução dos times pré-campeonato
Time analisa_time(char *linha_csv);

// Imprime as informações do time (ID, nome, vitórias, ...)
void imprimir_time(Time t);

#endif