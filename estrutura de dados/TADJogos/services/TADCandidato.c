#include "interface/TADCandidato.h"
#include "interface/TADPonto.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/ 
struct candidato {
  char* nome;
  int idade;
  Ponto* ponto;
};


// Construtor
Candidato* criar_candidato(char* nome) {
    Candidato* candidato = (Candidato*) malloc(sizeof(Candidato*));
    if (candidato == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    }

    strcpy(candidato->nome, nome);

    candidato->idade = sorteio(10, 4);
    
    pto_atribui(candidato->ponto, (float) (sorteio(10, 4)), (sorteio(10, 4)));
    
    
    return candidato;
}


// Getters
char* get_candidato_nome(Candidato* candidato) {
  return candidato->nome;
}

int get_candidato_idade(Candidato* candidato) {
  return candidato->idade;
}

char* get_candidato_ponto(Ponto* p) {
    return pto_getPonto(p);
}

// Setters
void set_candidato_nome(Candidato* candidato, char* nome) {
  strncpy(candidato->nome, nome, 49);
  candidato->nome[49] = '\0';
}

void set_candidato_idade(Candidato* candidato, int idade) {
  candidato->idade = idade;
}

void set_candidato_ponto(Candidato* candidato, float x, float y) {
    pto_atribui(candidato->ponto, x, y);
}


//exibir_candidato
void exibir_candidato(Candidato* candidato) {

    printf ("\n Nome = %s",candidato->nome);
    printf("\n Idade = %d", candidato->idade);
    printf("\n Data = ");
    pto_exibe(candidato->ponto);    
}

// toString
char* to_string(Candidato* candidato) {
  char* retorno;
  sprintf(retorno, "Nome: %s, Idade: %d, Ponto: %s", candidato->nome, candidato->idade, pto_getPonto(candidato->ponto));
  return retorno;
}


//liberar_candidato
void liberar_candidato(Candidato* candidato) {
    free(candidato->nome);
    free(candidato);
    pto_libera(candidato->ponto);
}


//verificar_testador
int verificar_testador(Ponto* p1) {
    
    if(p1 == NULL) {
      printf("Pontuação inválida!\n");
      return 0;
    }
    Ponto* pontoPerfeito = pto_cria(5.0, 8.0);

    float distancia = pto_distancia(pontoPerfeito, p1);

    if(distancia >= 1.5) {
        return 1;
    } return 0;
}

// Comparar idade entre candidatos
int comparar_idade(Candidato* c1, Candidato* c2) {
  if (c1->idade < c2->idade) {
    return -1; // c1 é mais jovem que c2
  } else if (c1->idade == c2->idade) {
    return 0; // c1 e c2 têm a mesma idade
  } else {
    return 1; // c1 é mais velho que c2
  }
}



// util
int sorteio(int lInf,int lSup){
  return (rand()%((lSup-lInf)+1))+lInf;
}