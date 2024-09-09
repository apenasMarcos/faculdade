#include "TADPonto.h"

/* Tipo exportado */
typedef struct candidato Candidato;


// CONSTRUCTOR
Candidato* criar_candidato(char* nome);

// GETTERS
char* get_candidato_nome(Candidato* candidato);
int get_candidato_idade(Candidato* candidato);
char* get_candidato_ponto(Ponto* p);

//SETTERS
void set_candidato_nome(Candidato* candidato, char* nome);
void set_candidato_idade(Candidato* candidato, int idade);
void set_candidato_ponto(Candidato* candidato, float x, float y);

//FREE
void liberar_candidato(Candidato* candidato);

// UTIL
int sorteio(int lInf,int lSup);