#pragma once
#include "interface/Data.h"
#include <time.h>

// Representação do TAD: TUnidade
//-----------
// Interface
//-----------

typedef struct unidade tUnidade;

// Criar unidade
tUnidade* criar_unidade();

// Liberar unidade
void liberar_unidade(tUnidade* unidade);

// Exibir unidade
void exibir_unidade(tUnidade* unidade);

// Getters
tData* get_dataFabricacao(tUnidade* unidade);
int get_lote(tUnidade* unidade);

// Setters
void set_dataFabricacao(tUnidade* unidade, tData* dataFabricacao);
void setLote(tUnidade* unidade, int lote);

// Idade
int idade(tUnidade* unidade, tData* dataAlvo);

// Comparar unidades
int eh_menor(tUnidade* unidade1, tUnidade* unidade2);

// Get unidade como string
char* get_unidade(tUnidade* unidade);