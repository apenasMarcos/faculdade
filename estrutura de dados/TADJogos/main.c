/******************************************************************************

Projeto TADJogos

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "services/interface/TADCandidato.h"

int main() {
  int n;
  printf("Digite o número de candidatos: ");
  scanf("%d", &n);

  Candidato** candidatos = malloc(n * sizeof(Candidato*));

  for (int i = 0; i < n; i++) {
    char nome[50];
    printf("Digite o nome do candidato %d: ", i + 1);
    scanf("%49s", nome);
    candidatos[i] = criar_candidato(nome);
  }

  // Criar vetor de ponteiros para os candidatos que podem ser testadores
  int m = 0;
  Candidato** testadores = malloc(n * sizeof(Candidato*));
  for (int i = 0; i < n; i++) {
    if (verificar_testador(get_candidato_ponto(candidatos[i]))) {
      testadores[m++] = candidatos[i];
    }
  }

  // Ordenar os testadores por idade
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (get_candidato_idade(testadores[i]) > get_candidato_idade(testadores[j])) {
        Candidato* temp = testadores[i];
        testadores[i] = testadores[j];
        testadores[j] = temp;
      }
    }
  }

  // Mostrar os testadores selecionados
  printf("Testadores selecionados:\n");
  for (int i = 0; i < m; i++) {
    printf("Nome: %s, Idade: %d\n", get_candidato_nome(testadores[i]), get_candidato_idade(testadores[i]));
  }

  // Liberar memória
  for (int i = 0; i < n; i++) {
    liberar_candidato(candidatos[i]);
  }

  return 0;
}