#ifndef TIME_H
#define TIME_H

// Estrutura que armazena as informações dos times
typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_m;
    int gols_s;
    int saldo_gols;
    int pontos_ganhos;
} Time;

// Remove , ao ler o arquivo times.csv
Time analisa_time(char *linha_csv);

// Imprime as informações do time (ID, nome, vitórias, ...)
void imprimir_time(Time t);

#endif