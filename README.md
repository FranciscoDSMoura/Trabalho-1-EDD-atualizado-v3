# Trabalho-1-EDD

Este projeto consiste em um sistema de gerenciamento de dados de um campeonato de futebol simplificado, desenvolvido em Linguagem C como parte do trabalho prático da disciplina estrutura de dados.

## 1 Requisitos para executar

GCC 11

Linux Ubuntu V24.04

## 2 Como Executar

`make` - _Compila automaticamente todos os módulos_

`./main` - _Executa o programa_

`make clean` - _Realiza a limpeza dos arquivos criados_

## 3 Arquivos

`main.c`: Ponto de entrada que gerencia o fluxo principal e inicialização dos bancos de dados.

`time.h` / `time.c`: TAD que modela uma equipe individual e suas estatísticas (V, E, D, GM, GS, etc.).

`ui.c / .h`: Gerencia a Interface de Usuário, menus e interações de entrada.

`bd_times.h` / `bd_times.c`: TAD responsável por gerenciar a coleção de times e carregar o arquivo times.csv.

`partida.h` / `partida.c`: TAD que representa as informações de um jogo específico.

`bd_partidas.h` / `bd_partidas.c`: TAD que gerencia o histórico de jogos e carrega o arquivo partidas.csv.

`Makefile`: Arquivo de automação da compilação.

## 4 Estruturas utilizadas

+ O sistema utiliza listas encadeadas simples para os bancos de dados, garantindo que a memória seja utilizada conforme a necessidade.

## 5 Regras de pontuação:

+ Vitória: +3 pontos.

+ Empate: +1 ponto.

+ Derrota: 0 pontos.

## 6 Descrição das Funcionalidades (Parte I)

* 6.1 **Consulta de Times:** Busca por nome ou prefixo (case-insensitive).

Exemplo de Busca por Prefixo
Se o usuário desejar buscar os times que começam com "SE":
- **Entrada:** `se`
- **Saída:**
  - 2 - SemCTRL
  - 5 - SeQueLas
  
* 6.2 **Consulta de Partidas:** Filtros por mandante, visitante ou ambos.

+ 6.3 Imprimir Tabela de Classificação: Exibe a lista completa de times e seus pontos acumulados.

Ao selecionar a **opção 6** no menu, o sistema gera o seguinte relatório de desempenho dos times:

| ID | Time | Vitórias | Empates | Derrotas | GM | GS | Saldo | PG |
| :---: | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | JAVAlis | 3 | 1 | 0 | 10 | 4 | +6 | **10** |
| **4** | PYthons | 2 | 2 | - | - | - | - | **-** |
