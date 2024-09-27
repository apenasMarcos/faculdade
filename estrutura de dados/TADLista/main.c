#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Lista.h"

void gerar_lista_aleatoria(tLista *lista, int n) {
    for (int i = 0; i < n; i++) {
        int valor = rand() % 41 + 10; // Gera valores entre 10 e 50
        lista_inclui(lista, valor);
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int n;
    printf("Digite o tamanho das listas: ");
    scanf("%d", &n);

    int tipo1, tipo2;
    printf("Digite o tipo da primeira lista (0: não classificada, 1: classificada): ");
    scanf("%d", &tipo1);
    printf("Digite o tipo da segunda lista (0: não classificada, 1: classificada): ");
    scanf("%d", &tipo2);

    // Cria as listas
    tLista *lista1 = lista_cria_vazia(n, tipo1, 0);
    tLista *lista2 = lista_cria_vazia(n, tipo2, 0);

    // Gera listas aleatórias
    gerar_lista_aleatoria(lista1, n);
    gerar_lista_aleatoria(lista2, n);

    // Exibe listas geradas
    printf("Lista 1: ");
    lista_percorre(lista1);
    printf("\nLista 2: ");
    lista_percorre(lista2);

    // Soma as listas
    tLista *soma = lst_soma_listas(lista1, lista2);
    printf("\nSoma das listas: ");
    lista_percorre(soma);

    // Liberação de memória
    free(lista1);
    free(lista2);
    free(soma);

    return 0;
}
