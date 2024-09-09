//--------------
// Implementação
//--------------

#include "interface/Unidade.h"
#include <time.h>
#include <string.h>

struct unidade {
    tData* dataFabricacao;
    int lote;
};

// Criar unidade
tUnidade* criar_unidade() {
    tUnidade* unidade = (tUnidade*) malloc(sizeof(tUnidade));
    if (unidade == NULL) {
        return NULL;
    }

    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    unidade->dataFabricacao = dta_cria(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    unidade->lote = 0;
    
    return unidade;
}

// Liberar unidade
void liberar_unidade(tUnidade* unidade) {
    free(unidade->dataFabricacao);
    free(unidade);
}

// Exibir unidade
void exibir_unidade(tUnidade* unidade) {
    printf("\n Data = ");
    dta_exibe(unidade->dataFabricacao);
    printf("\n Lote = %d", unidade->lote);
}

// Getters
tData* get_dataFabricacao(tUnidade* unidade) {
    return unidade->dataFabricacao;
}

int get_lote(tUnidade* unidade) {
    return unidade->lote;
}

// Setters
void set_dataFabricacao(tUnidade* unidade, tData* dataFabricacao) {
    unidade->dataFabricacao = dataFabricacao;
}

void setLote(tUnidade* unidade, int lote) {
    unidade->lote = lote;
}

// Idade
int idade(tUnidade* unidade, tData* dataAlvo) {
    return dta_diferenca_em_dias(unidade->dataFabricacao, dataAlvo);
}

// Comparar unidades
int eh_menor(tUnidade* unidade1, tUnidade* unidade2) {
    int idade1 = idade(unidade1, dta_hoje());
    int idade2 = idade(unidade2, dta_hoje());
    
    if (idade1 < idade2) {
        return 1;
    } else if (idade1 > idade2) {
        return 0;
    } else {
        return unidade1->lote < unidade2->lote;
    }
}

// Get unidade como string
char* get_unidade(tUnidade* unidade) {
    char* str = (char*) malloc(50 * sizeof(char));
    char data[20];
    dta_formato(unidade->dataFabricacao, data);
    sprintf(str, "Data: %s, Lote: %d", data, unidade->lote);
    return str;
}