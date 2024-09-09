//--------------
// Implementação
//--------------

#include "interface/Produto.h"
#include <string.h>

struct produto {
    char identificacao[20];
    char codigoBarras[20];
    float preco;
    int qtUnidades;
    tUnidade** unidades;
};

// Criar produto
tProduto* criar_produto(tUnidade** unidades) {
    tProduto* produto = (tProduto*) malloc(sizeof(tProduto));
    produto->identificacao[0] = '\0';
    strcpy(produto->identificacao, "Produto");
    produto->codigoBarras[0] = '\0';
    produto->preco = 0.0;
    produto->qtUnidades = 0;
    produto->unidades = unidades;
    return produto;
}

// Liberar produto
void liberar_produto(tProduto* produto) {
    for (int i = 0; i < produto->qtUnidades; i++) {
        liberar_unidade(produto->unidades[i]);
    }
    free(produto->unidades);
    free(produto);
}

// Exibir produto
void exibir_produto(tProduto* produto) {
    printf("\n Identificação: %s", getIdentificacao(produto));
    printf("\n Código de Barras: %s", getCodigoBarras(produto));
    printf("\n Preço: R$ %.2f", getPreco(produto));
    printf("\n Quantidade de Unidades: %d", getQtUnidades(produto));

    tUnidade** unidades = getUnidades(produto);
    if (unidades != NULL) {
        printf("\n Unidades:");
        for (int i = 0; i < getQtUnidades(produto); i++) {
            printf("\n Unidade %d:", i + 1);
            exibir_unidade(unidades[i]);
        }
    }
}

// Getters
char* getIdentificacao(tProduto* produto) {
    return produto->identificacao;
}

char* getCodigoBarras(tProduto* produto) {
    return produto->codigoBarras;
}

float getPreco(tProduto* produto) {
    return produto->preco;
}

int getQtUnidades(tProduto* produto) {
    return produto->qtUnidades;
}

tUnidade** getUnidades(tProduto* produto) {
    return produto->unidades;
}

// Setters
void setIdentificacao(tProduto* produto, char* identificacao) {
    strcpy(produto->identificacao, identificacao);
}

void setCodigoBarras(tProduto* produto, char* codigoBarras) {
    strcpy(produto->codigoBarras, codigoBarras);
}

void setPreco(tProduto* produto, float preco) {
    produto->preco = preco;
}

void setQtUnidades(tProduto* produto, int qtUnidades) {
    produto->qtUnidades = qtUnidades;
}

void setUnidades(tProduto* produto, tUnidade** unidades) {
    produto->unidades = unidades;
}

// Eh semelhante
int ehSemelhante(tProduto* produto1, tProduto* produto2) {
    return strcmp(produto1->identificacao, produto2->identificacao) == 0;
}

// Reajuste
void reajuste(tProduto* produto, float percentual) {
    produto->preco *= (1 + percentual / 100);
}

// Get produto como string
char* getProduto(tProduto* produto) {
    char* str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "Identificação: %s, Código de Barras: %s, Preço: R$ %.2f, Quantidade de Unidades: %d",
            produto->identificacao, produto->codigoBarras, produto->preco, produto->qtUnidades);
    return str;
}

// Eh igual
int ehIgual(tProduto* produto1, tProduto* produto2) {
    return strcmp(produto1->identificacao, produto2->identificacao) == 0 &&
           strcmp(produto1->codigoBarras, produto2->codigoBarras) == 0 &&
           produto1->preco == produto2->preco &&
           produto1->qtUnidades == produto2->qtUnidades &&
           ehIgualUnidades(produto1->unidades, produto2->unidades, produto1->qtUnidades);
}

int ehIgualUnidades(tUnidade** unidades1, tUnidade** unidades2, int qtUnidades) {
    for (int i = 0; i < qtUnidades1, i++) {
        if (!ehIgualUnidade(unidades1[i], unidades2[i])) { 
            return 0; 
        } 
    } return 1; 
    
}

int ehIgualUnidade(tUnidade* unidade1, tUnidade* unidade2) {
    return strcmp(getDescricao(unidade1), getDescricao(unidade2)) == 0 &&
           getQuantidade(unidade1) == getQuantidade(unidade2);
}