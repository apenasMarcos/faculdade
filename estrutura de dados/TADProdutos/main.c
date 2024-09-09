/******************************************************************************

Programa TAD Produtos

*******************************************************************************/

#include "Produto.h"
#include "Unidade.h"
#include <stdio.h>
#include <string.h>

int main() {
    // Create a vector of product pointers
    tProduto* produtos[5];

    // Create some example products
    tUnidade* unidades1[] = {criar_unidade("Unidade 1", 10, "2022-12-25"), criar_unidade("Unidade 2", 20, "2022-12-28")};
    tProduto* produto1 = criar_produto(unidades1, 2);
    setIdentificacao(produto1, "Produto 1");
    setCodigoBarras(produto1, "1234567890");
    setPreco(produto1, 100.0);

    tUnidade* unidades2[] = {criar_unidade("Unidade 3", 30, "2022-12-20"), criar_unidade("Unidade 4", 40, "2022-12-22")};
    tProduto* produto2 = criar_produto(unidades2, 2);
    setIdentificacao(produto2, "Produto 2");
    setCodigoBarras(produto2, "9876543210");
    setPreco(produto2, 200.0);

    tUnidade* unidades3[] = {criar_unidade("Unidade 5", 50, "2022-12-18"), criar_unidade("Unidade 6", 60, "2022-12-19")};
    tProduto* produto3 = criar_produto(unidades3, 2);
    setIdentificacao(produto3, "Produto 3");
    setCodigoBarras(produto3, "1111111111");
    setPreco(produto3, 300.0);

    produtos[0] = produto1;
    produtos[1] = produto2;
    produtos[2] = produto3;

    // Ask the user for the target date
    char dataAlvo[10];
    printf("Informe a data alvo (formato YYYY-MM-DD): ");
    scanf("%s", dataAlvo);

    // For each product, show which units expire on the target date
    for (int i = 0; i < 3; i++) {
        tProduto* produto = produtos[i];
        printf("\nProduto %s:\n", getIdentificacao(produto));
        tUnidade** unidades = getUnidades(produto);
        for (int j = 0; j < getQtUnidades(produto); j++) {
            tUnidade* unidade = unidades[j];
            if (strcmp(getValidade(unidade), dataAlvo) == 0) {
                printf("  Unidade %d vence em %s\n", j + 1, getValidade(unidade));
            }
        }
    }

    // For products that have at least one unit that expires in 3 days from the target date, apply 25% discount
    for (int i = 0; i < 3; i++) {
        tProduto* produto = produtos[i];
        tUnidade** unidades = getUnidades(produto);
        int temUnidadeVencendo = 0;
        for (int j = 0; j < getQtUnidades(produto); j++) {
            tUnidade* unidade = unidades[j];
            if (strcmp(getValidade(unidade), dataAlvo) == 0 || strcmp(getValidade(unidade), "2022-12-27") == 0 || strcmp(getValidade(unidade), "2022-12-26") == 0) {
                temUnidadeVencendo = 1;
                break;
            }
        }
        if (temUnidadeVencendo) {
            reajuste(produto, -25);
            printf("\nProduto %s teve 25%% de desconto aplicado!\n", getIdentificacao(produto));
        }
    }

    // Free memory
    for (int i = 0; i < 3; i++) {
        liberar_produto(produtos[i]);
    }

    return 0;
}