# Trabalho-1-EDD

Este projeto consiste em um sistema de gerenciamento de dados de um campeonato de futebol simplificado, desenvolvido em Linguagem C como parte do trabalho prático da disciplina estrutura de dados.

## Requisitos para executar

GCC 

Linux Ubuntu V24.04

## Como Executar

`make` - _Compila automaticamente todos os módulos_

`./main` - _Executa o programa_

## Arquivos

`main.c`: Ponto de entrada que gerencia o fluxo principal e inicialização dos bancos de dados.

`time.h` / `time.c`: TAD que modela uma equipe individual e suas estatísticas (V, E, D, GM, GS, etc.).

`ui.c / .h`: Gerencia a Interface de Usuário, menus e interações de entrada.

`bd_times.h` / `bd_times.c`: TAD responsável por gerenciar a coleção de times e carregar o arquivo times.csv.

`partida.h` / `partida.c`: TAD que representa as informações de um jogo específico.

`bd_partidas.h` / `bd_partidas.c`: TAD que gerencia o histórico de jogos e carrega o arquivo partidas.csv.

`Makefile`: Arquivo de automação da compilação.

## Estruturas utilizadas

+ O sistema utiliza listas encadeadas simples para os bancos de dados, garantindo que a memória seja utilizada conforme a necessidade

## Regras de pontuação:

+ Vitória: +3 pontos.

+ Empate: +1 ponto.

+ Derrota: 0 pontos.

## Funcionalidades Implementadas (Parte I)

+ Consultar Time: Exibe o desempenho de equipes por nome ou prefixo.
+ Imprimir Tabela de Classificação: Exibe a lista completa de times e seus pontos acumulados.
