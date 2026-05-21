// Importa a própria interface pública
#include "bd_times.h"

// importa as bibliotecas padrões do C 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Importa interfaces públicas 
#include "time.h"
#include "bd_partidas.h"
#include "classificacao.h"

BDTime *criar_bd_time(void){
    BDTime *bd = malloc(sizeof(BDTime)); // Aloca dinamicamente uma lista de times
    if(bd) bd->inicio = NULL;
    return bd;
}

void destruir_bd_time(BDTime *bd){
    NoTime *atual = bd->inicio;
    // Enquanto faltar nós para serem liberados
    while(atual){
        NoTime *temp = atual;
        atual = atual->proximo;
        free(temp); // Libera nó a nó
    }
    free(bd); // Libera o banco de dados de time
}

void inserir_time(BDTime *bd, Time t){
    NoTime *novo = malloc(sizeof(NoTime)); // Cria um novo nó
    novo->time = t; // Atribui time
    novo->proximo = bd->inicio; // Insere no início
    bd->inicio = novo;
}

void bd_carregar_times_csv(BDTime *bd, const char *caminho_arquivo){
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

void imprimir_cabecalho(){
    printf("\n%-3s  %-10s  %-3s  %-3s  %-3s  %-3s  %-3s  %-3s  %-3s\n", 
           "ID", "Time", "V", "E", "D", "GM", "GS", "S", "PG"); // Imprime o cabeçalho formatado
}

void buscar_por_nome(BDTime *bd_t, void *bd_p, char *prefixo, int paginacao)
{
   NoTime *atual = bd_t->inicio;
    int encontrou = 0;
    int cont = 0;
    while (atual) {
        Time t = atual->time;
        if (strncasecmp(t.nome, prefixo, strlen(prefixo)) == 0){
            imprimir_cabecalho(); 
            classificacao_completa(bd_t, bd_p);
            imprimir_time(atual->time); // Imprime se encontrou
            encontrou = 1;
        }
        atual = atual->proximo;
        cont++;

        // Paginação, se imprimir x times passa para a próxima página
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

NoTime* buscar_por_id(BDTime *bd, int id) {
    NoTime *atual = bd->inicio;
    while (atual) {
        if (atual->time.id == id) // Verifica ID
            return atual;
        atual = atual->proximo;
    }
    return NULL; // Não achou
}

const char* time_get_nome(NoTime *n)
{
    if (n != NULL) {
        return n->time.nome; // Se n não for nulo ele receb o nome do time
    }
    return "Desconhecido";
}

void bd_salvar_arquivo(BDTime *bd, const char *caminho_arquivo) 
{
    FILE *arquivo = fopen(caminho_arquivo, "w"); // Abre arquivo para escrita
    if (!arquivo) {
        printf("Erro ao salvar em %s\n", caminho_arquivo); // Mensagem de erro
        return;
    }

    fprintf(arquivo, "ID\tTime\t\t\tV\tE\tD\tGM\tGS\tS\tPG\n"); // Cabeçalho CSV
    NoTime *atual = bd->inicio;
    while (atual) {
        Time t = atual->time;
        fprintf(arquivo, "%d,%s,%d,%d,%d,%d,%d,%d,%d\n", // Escreve as informaçõoes do time
                t.id, t.nome, t.vitorias, t.empates, t.derrotas, t.gols_m, t.gols_s, t.saldo_gols, t.pontos_ganhos);
        atual = atual->proximo;
    }
    fclose(arquivo); // Fecha arquivo
}

// Implementações futuras (talvez)

/*int atualizar_estatisticas_time(BDTime *bd, int id, Time novo) {
    NoTime *n = buscar_por_id(bd, id); // Busca nó por ID
    if (!n) return 0; // Não encontrou
    n->time = novo; // Atualiza dados
    return 1; // Sucesso
}

int remover_bd_times(BDTime *bd, int id)
{
    NoTime* atual = bd->inicio, *anterior = NULL;
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
*/
