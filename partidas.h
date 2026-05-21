#ifndef PARTIDAS_H
#define PARTIDAS_H

// Estrutura com as informações das partidas
typedef struct {
    int id;           
    int id_time1;     
    int id_time2;     
    int gols_time1;   
    int gols_time2;   
} Partidas;

// Remove , ao ler algum dos arquivos de partidas
Partidas analisa_partidas(char *linha_csv);

#endif