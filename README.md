# Trabalho-1-EDD

Este projeto consiste em um sistema de gerenciamento de dados de um campeonato de futebol simplificado, desenvolvido em Linguagem C como parte do trabalho prático da disciplina estrutura de dados.

## Requisitos para executar

GCC 

Linux Ubuntu V24.04

## Como Executar

make - _Compila automaticamente todos os módulos_

./main - _Executa o programa_

## Modularização

`main.c`: Ponto de entrada do sistema e controle do loop do menu.

`time.h / time.c`: TAD que modela uma equipe individual e suas estatísticas (V, E, D, GM, GS, etc.).

`bd_times.h / bd_times.c`: TAD responsável por gerenciar a coleção de times e carregar o arquivo times.csv.

`partida.h / partida.c`: TAD que representa as informações de um jogo específico.

`bd_partidas.h / bd_partidas.c`: TAD que gerencia o histórico de jogos e carrega o arquivo partidas.csv.
