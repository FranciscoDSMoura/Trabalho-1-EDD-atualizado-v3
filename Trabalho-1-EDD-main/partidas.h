#ifndef PARTIDAS_H
#define PARTIDAS_H

#include "bd_times.h"

typedef struct {
    int id;           
    int id_time1;     
    int id_time2;     
    int gols_time1;   
    int gols_time2;   
} Partidas;

Partidas analisa_partidas(char *linha_csv);

void imprimir_partidas(Partidas p, BDTime *bd_times);

#endif