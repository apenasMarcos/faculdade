#pragma once
#include "interface/Data.h"
#include "interface/Unidade.h"

// Representação do TAD: TProduto
//-----------
// Interface
//-----------

typedef struct produto tProduto;

tProduto* criar_produto();

void liberar_produto(tProduto* unidade);

void exibir_produto(tProduto* unidade);

//getters
char* getIdentificacao(tProduto* produto);
char* getCodigoBarras(tProduto* produto);
float getPreco(tProduto* produto);
int getQtUnidades(tProduto* produto);
tUnidade** getUnidades(tProduto* produto);

//setters
void setIdentificacao(tProduto* produto, char* identificacao);
void setCodigoBarras(tProduto* produto, char* codigoBarras);
void setPreco(tProduto* produto, float preco);
void setQtUnidades(tProduto* produto, int qtUnidades);
void setUnidades(tProduto* produto, tUnidade** unidades);