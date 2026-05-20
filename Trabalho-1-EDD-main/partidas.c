#include "partidas.h"
#include "bd_times.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Partidas analisa_partidas(char *linha_csv){
    Partidas p;
    char *token;

    token = strtok(linha_csv, ",");
    p.id = token ? atoi(token) : 0; // ID da partida

    token = strtok(NULL, ",");
    p.id_time1 = token ? atoi(token) : 0; // ID do time1

    token = strtok(NULL, ",");
    p.id_time2 = token ? atoi(token) : 0; // ID do time2

    token = strtok(NULL, ",");
    p.gols_time1 = token ? atoi(token) : 0; // Qtd de gols do time1

    token = strtok(NULL, ",\n\r");
    p.gols_time2 = token ? atoi(token) : 0; // Qtd de gols do time2

    return p;
}

void imprimir_partidas(Partidas p, BDTime *bd_times)
{
    No *mandante = buscar_por_id(bd_times, p.id_time1);
    No *visitante = buscar_por_id(bd_times, p.id_time2);

    const char *nome_m = mandante ? time_get_nome(&(mandante->time)) : "Desconhecido";
    const char *nome_v = visitante ? time_get_nome(&(visitante->time)) : "Desconhecido";

    printf("%-3d  %-10s  %-1d  x  %-2d  %-10s\n",
           p.id, nome_m, p.gols_time1, p.gols_time2, nome_v);
}

