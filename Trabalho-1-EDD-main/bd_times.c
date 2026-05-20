#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "bd_times.h"
#include "time.h"

BDTime *criar_bd_time(void)
{
    BDTime *bd = malloc(sizeof(BDTime));
    if(bd) bd->inicio = NULL;
    return bd;
}

void destruir_bd_time(BDTime *bd)
{
    No *atual = bd->inicio;
    while(atual){
        No *temp = atual;
        atual = atual->proximo;
        free(temp); // Libera nó a nó
    }
    free(bd); // Libera o banco de dados de time
}

void inserir_time(BDTime *bd, Time t)
{
    No *novo = malloc(sizeof(No)); // Cria um novo nó
    novo->time = t; // Atribui time
    novo->proximo = bd->inicio; // Insere no início
    bd->inicio = novo;
}

void bd_carregar_times_csv(BDTime *bd, const char *caminho_arquivo)
{
    FILE *arquivo;
    arquivo = fopen(caminho_arquivo, "r"); // Abre e Lê o arquivo

    // Verifica se realmente há um arquivo com esse nome e caminho
    if(!arquivo){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    fgets(linha, sizeof(linha), arquivo); // Pula a primeira linha (cabeçalho)
    while(fgets(linha, sizeof(linha), arquivo)){
        Time t = analisa_time(linha); // Converte uma linha para time
        inserir_time(bd, t); // Insere time no banco de dados
    }
    fclose(arquivo); // Fecha o arquivo
}

void bd_salvar_arquivo(BDTime *bd, const char *caminho_arquivo) 
{
    FILE *arquivo = fopen(caminho_arquivo, "w"); // Abre arquivo para escrita
    if (!arquivo) {
        printf("Erro ao salvar em %s\n", caminho_arquivo);
        return;
    }

    fprintf(arquivo, "ID\tTime\t\t\tV\tE\tD\tGM\tGS\tS\tPG\n"); // Cabeçalho CSV
    No *atual = bd->inicio;
    while (atual) {
        Time t = atual->time;
        fprintf(arquivo, "%d,%s,%d,%d,%d,%d,%d,%d,%d\n", // Escreve as informaçõoes do time
                t.id, t.nome, t.vitorias, t.empates, t.derrotas, t.gols_m, t.gols_s, t.saldo_gols, t.pontos_ganhos);
        atual = atual->proximo;
    }
    fclose(arquivo); // Fecha arquivo
}

void imprimir_cabecalho()
{
    printf("\n%-3s  %-10s  %-1s  %-1s  %-1s  %-2s  %-2s  %-2s  %-2s\n",
           "ID", "Time", "V", "E", "D", "GM", "GS", "S", "PG");
}

void buscar_por_nome(BDTime *bd, char *prefixo, int paginacao)
{
   No *atual = bd->inicio;
    int encontrou = 0;
    int cont = 0;
    while (atual) {
        Time t = atual->time;
        if (strncasecmp(t.nome, prefixo, strlen(prefixo)) == 0){
            imprimir_cabecalho(); 
            imprimir_time(atual->time); // Imprime se encontrou
            encontrou = 1;
        }
        atual = atual->proximo;
        cont++;

        if(cont < 10){
            if (cont % paginacao == 0){
                char op;
                printf("\n-- Página %d -- ENTER p/ continuar, Q p/ sair: ", cont/paginacao);
                op = getchar();
                if (op == 'Q' || op == 'q') break;
            }
        }
    }
    if (!encontrou)
        printf("Nenhum time encontrado com o nome/prefixo informado.\n");
}

No* buscar_por_id(BDTime *bd, int id) {
    No *atual = bd->inicio;
    while (atual) {
        if (atual->time.id == id) // Verifica ID
            return atual;
        atual = atual->proximo;
    }
    return NULL; // Não achou
}

int atualizar_estatisticas_time(BDTime *bd, int id, Time novo) {
    No *n = buscar_por_id(bd, id); // Busca nó por ID
    if (!n) return 0; // Não encontrou
    n->time = novo; // Atualiza dados
    return 1; // Sucesso
}

int remover_bd_times(BDTime *bd, int id)
{
    No* atual = bd->inicio, *anterior = NULL;
    while(atual){
        if(atual->time.id == id) { // Achou o time
            if (anterior)
                anterior->proximo = atual->proximo; // Remove do meio/fim
            else
                bd->inicio = atual->proximo; // Remove do inicio
            free(atual); // Libera a memória
            return 1; // Sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // Não encontrou o time
}

const char* time_get_nome(No *n)
{
    if (n != NULL) {
        return n->time.nome;
    }
    return "Desconhecido";
}