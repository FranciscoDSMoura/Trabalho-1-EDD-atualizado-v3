#ifndef UI_H
#define UI_H

#include "bd_times.h"
#include "bd_partidas.h"

int imprimir_menu(BDPartidas *bd_p, BDTime *bd);

void consultar_time(BDTime *bd);

void consultar_partidas(BDPartidas *bd_p, BDTime *bd_t);

int imprimir_tabela();

#endif