#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "ui.h"
#include "bd_times.h"
#include "bd_partidas.h"
#include "partidas.h"

void consultar_time(BDTime *bd_t){
  printf("Digite o nome ou o prefixo do time:\n");
  char prefixo[100];
  scanf("%99s", prefixo);
  buscar_por_nome(bd_t, prefixo, 10);
}

void consultar_partidas(BDPartidas *bd_p, BDTime *bd_t){
    printf("\nEscolha o modo de consulta:\n"
           "1 - Por time mandante\n"
           "2 - Por time visitante\n"
           "3 - Por time mandante ou visitante\n"
           "4 - Retornar ao menu principal\n");

    char opcao;
    scanf(" %c", &opcao); getchar(); //recebe a opção que o usuário digitar 

    switch(opcao){
        case '1': buscar_por_mandante(bd_p, bd_t, 10); break;
        case '2': buscar_por_visitante(bd_p, bd_t, 10); break;
        case '3': buscar_por_m_ou_v(bd_p, bd_t, 10); break;
        case '4': ; break;
        default: printf("Escolha uma opção válida.\n"); break;
    }
}

int imprimir_menu(BDPartidas *bd_p, BDTime *bd_t){
    char opcao;
    
    //continua printando o menu ate que Q ou q seja inserido
    while (opcao != 'Q' && opcao != 'q')  {

        printf("\n1 - Consultar time\n"
               "2 - Consultar partidas\n"
               "3 - Atualizar partida\n"
               "4 - Remover partida\n"
               "5 - Inserir partida\n"
               "6 - Imprimir tabela de classificação\n"
               "Q - Sair\n\n");

        scanf(" %c", &opcao); getchar(); //recebe a opção que o usuário digitar 

        switch(opcao){
            case '1': consultar_time(bd_t); break;
            case '2': consultar_partidas(bd_p, bd_t); break;
            case '6': /*imprimir_tabela_classificacao();*/ break;
            case 'Q': case 'q': printf("Encerrando...\n"); break;
            default: printf("Essas funções não estão disponíveis\n"); break;
        }
    }
    return 0;
}

