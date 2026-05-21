// Importa a própria interface pública
#include "partidas.h"

// Importa interfaces públicas
#include "bd_times.h"

// importa as bibliotecas padrões do C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Remove , e lixos
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

