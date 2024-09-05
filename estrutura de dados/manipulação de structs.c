#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct p {
  char *nome;
  int idade;
  char *email;
};

typedef struct p tPessoa;

void preenchePessoa(tPessoa *pPessoa) {
  char aux[100];
  printf("Digite o nome: ");
  scanf(" %[^\n]", aux);
  pPessoa->nome = (char *)malloc(strlen(aux) + 1);
  strcpy(pPessoa->nome, aux);

  printf("Digite o email: ");
  scanf(" %[^\n]", aux);
  pPessoa->email = (char *)malloc(strlen(aux) + 1);
  strcpy(pPessoa->email, aux);

  printf("Digite a idade: ");
  scanf("%d", &(pPessoa->idade));
}

tPessoa copia(tPessoa p1) {
  tPessoa p2;

  p2.nome = malloc(strlen(p1.nome) + 1);
  strcpy(p2.nome, p1.nome);

  p2.email = malloc(strlen(p1.email) + 1);
  strcpy(p2.email, p1.email);

  p2.idade = p1.idade;

  return p2;
}

int main() {
  tPessoa *pessoas[3];
  tPessoa pessoaCopiada;

  // Preencher pessoas
  for (int i = 0; i < 3; i++) {
    printf("Pessoa %d:\n", i + 1);
    pessoas[i] = (tPessoa *)malloc(sizeof(tPessoa));
    preenchePessoa(pessoas[i]);
  }

  // Funcionalidade de cópia
  pessoaCopiada = copia(*pessoas[0]);

  // Imprimir pessoa copiada
  printf("------------------\n");
  printf("Pessoa numero 1 Copiada:\n");
  printf("Nome: %s\n", pessoaCopiada.nome);
  printf("Email: %s\n", pessoaCopiada.email);
  printf("Idade: %d\n", pessoaCopiada.idade);
  printf("\n");

  // Imprimir as pessoas criadas
  for (int i = 0; i < 3; i++) {
    printf("------------------\n");
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: %s\n", pessoas[i]->nome);
    printf("Email: %s\n", pessoas[i]->email);
    printf("Idade: %d\n", pessoas[i]->idade);
    printf("\n");
  }

  // Liberar a memória alocada
  for (int i = 0; i < 3; i++) {
    free(pessoas[i]->nome);
    free(pessoas[i]->email);
    free(pessoas[i]);
  }
  free(pessoaCopiada.nome);
  free(pessoaCopiada.email);

  return 0;
}