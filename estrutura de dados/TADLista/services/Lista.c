#include "Lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* Em seguida, um tipo para a lista */ 
struct tipo_lista 
{ 
    int* vnos; 
    int qtnos; 
    int maximo; 
    int classificada; // 1: classificada 0: não classificada 
    int repeticao; // 1: com repetição 0: sem repetição 
}; 
//////////////////////////////////////////
//FUNÇÔES AUXILIARES

//exibe item 
void exibe(int valor) ;

//Busca DESORDENADA sem repetição 
int buscaLinear(const tLista *pl,int chave,int *pos);
//Busca BINÁRIA 
int buscaBinaria(const tLista *pl, int chave, int *pos) ;

void removerRepetidos(tLista *lista, int valor, int pos);
//////////////////////////////////////////////////


/*cria lista vazia*/ 
tLista * lista_cria_vazia(int maximo,int classif, int repet) {
    tLista * pl= (tLista*) malloc(sizeof(tLista));
	pl->vnos=(int *) malloc(sizeof(int) * maximo);
	pl->qtnos = 0; 
    pl->maximo= maximo; 
    pl->classificada=classif; 
    pl->repeticao=repet; 
    return pl;
} 
//lista está vazia? 
int lista_vazia( const tLista *pl){ 
    return ( pl->qtnos == 0); 
}
//lista está cheia? 
int lista_cheia( const tLista *pl){ 
    return ( pl->qtnos == pl->maximo); 
} 
//lista com repetição? 
int lista_repet( const tLista *pl){ 
    return ( pl->repeticao == 1); 
} 
//lista classificada? 
int lista_classif( const tLista *pl){ 
    return ( pl->classificada == 1); 
} 
//percorre a lista 
void lista_percorre(const tLista *pl) { 
    int i; 
    for(i = 0; i < pl->qtnos; i++) 
        exibe(pl->vnos[i]); 
} 

//inclui um item na lista: verifica caso repetição e classificação
int lista_inclui(tLista *pl, int valor) {
    int pos;
    int st;
    if (lista_cheia(pl))
        return 0;
        
    //determinar a pos de inclusão
    if (!lista_classif( pl) && lista_repet(pl)){
        pos=pl->qtnos;
        st=0;
    }
    else if (lista_classif( pl)){
        st= buscaBinaria(pl,valor,&pos);
        if (lista_repet(pl))
            st=0;
    }
    else{
        st= buscaLinear(pl,valor,&pos);
    }
    
    // pode ou não incluir?
    if (st==1) 
        return -1; 
    
    // abrir o buraco pos
    if (pos <pl->qtnos){
        int qt= pl->qtnos-pos;
        memcpy(pl->vnos+pos+1, pl->vnos+pos, qt*sizeof(int)); //chegaprálá 1 posd
    }
    pl->vnos[pos]=valor;
    (pl->qtnos)++;
    return 1;
    
    
    
}






// Função para remover um valor da lista
int lista_remove(tLista *lista,int valor) {
  int pos, st;
  if (lista == NULL) {
    printf("Lista inexistente\n");
    return 0;
  }
  if (lista_vazia(lista)) {
    printf("Lista vazia\n");
    return 0;
  }
  // encontra a pos do valor
  if (lista_classif(lista)) { // Ordenado
    st = buscaBinaria(lista, valor, &pos);
  } else { // Não ordenado
    st = buscaLinear(lista, valor, &pos);
  }
  if (st == -1) { // Valor não encontrado
      printf("Valor não existe\n");
      return -1;
  }
  

  if (!lista_repet(lista)) { // Remover sem repetição
    memcpy(lista->vnos+pos, lista->vnos+pos+1,
           (lista->qtnos - pos - 1) * sizeof(int));
    lista->qtnos--;
    return 1;
  } else { // Remover repetidos
    removerRepetidos(lista, valor, pos);
    return 1;
  }
}

// Função auxiliar para remover repetidos
void removerRepetidos(tLista *lista, int valor, int pos) {
  int posInic,posFin;
  if (!lista_classif(lista)) { // Lista não ordenada
    while (pos < lista->qtnos ) {
        if ( lista->vnos[pos] == valor){
              memcpy(lista->vnos+pos, lista->vnos+pos+ 1,
             (lista->qtnos - pos - 1) * sizeof(int));
             lista->qtnos--;
        }
        else{
            pos++;
        }
        
    }
  } else { // Lista ordenada
    // POSIÇÃO INICIAL
    posInic=pos;
    while (posInic > 0 && lista->vnos[posInic - 1] == valor) {
      posInic--;
    }
    // POSIÇÃO FINAL
    posFin=pos;
    while (posFin <lista->qtnos-1 && lista->vnos[posFin+1] == valor) {
      posFin++;
    }
    // Movimentar que está depois da posFin para a posIni
    int qtrestante=lista->qtnos - posFin-1;
    if (qtrestante > 0)
      memcpy(lista->vnos+posInic, lista->vnos +posFin + 1,
             qtrestante * sizeof(int));
      lista->qtnos-=posFin-posInic +1;
    }
}


// ------------------OBTENÇÃO DE VALORES-------------------------
int *obterVetor(tLista *lista) {
  if (lista == NULL) {
    printf("Lista inexistente\n");
    return NULL;
  }
  return lista->vnos;
}

int lista_obterQuantidadeNos(tLista *lista) {
  if (lista == NULL) {
    printf("Lista inexistente\n");
    return -1; // Retorna -1 para indicar erro
  }
  return lista->qtnos;
}

int lista_obterMaximoNos(tLista *lista) {
  if (lista == NULL) {
    printf("Lista inexistente\n");
    return -1; // Retorna -1 para indicar erro
  }
  return lista->maximo;
}











//FUNÇÔES AUXILIARES

//exibe item 
void exibe(int valor) { 
    printf("\n%d",valor);
} 

//Busca DESORDENADA sem repetição 
int buscaLinear(const tLista *pl,int chave,int *pos){ 
    int i; 
    for(i=0; (i<pl->qtnos)&&(pl->vnos[i]!=chave); i++); 
    (*pos) = i; 
    return(i < pl->qtnos); 
} 
//Busca BINÁRIA 
int buscaBinaria(const tLista*pl, int chave, int *pos) 
{
    int inicio = 0;
    int meio;
    int fim= pl->qtnos-1;
    int achou = 0; 
    while((inicio <= fim) && (!achou)) { 
        meio = (inicio + fim) / 2; 
        if(pl->vnos[meio] == chave) 
            achou = 1; 
        else if(pl->vnos[meio] > chave) 
            fim=meio-1; 
        else 
            inicio= meio+1; 
    } 
    if(achou) { 
        (*pos) = meio; 
        /*
        if (lista_repet(pl)) { 
            do { 
                (*pos)--; 
            }while ((*pos)>=0) && (pl->vnos[(*pos)].chave ==chave); (*pos)++; 
        } 
        */
    } 
    else 
        (*pos) = inicio; 
    return achou; 
} 


// Função para criar uma sublista
tLista *lst_sublista_doi_Esimo_ao_j_Esimo(const tLista *original, int i, int j) {
    if (i < 0 || j < 0 || i >= original->qtnos || j >= original->qtnos || i > j) {
        return lista_cria_vazia(0, 0, 0); // Retorna uma lista vazia
    }
    
    int tamanho = j - i + 1;
    tLista *sublista = lista_cria_vazia(tamanho, original->classificada, original->repeticao);
    
    for (int pos = i; pos <= j; pos++) {
        lista_inclui(sublista, original->vnos[pos]);
    }
    
    return sublista;
}

// Função para somar duas listas
tLista *lst_soma_listas(const tLista *lst1, const tLista *lst2) {
    int tamanho_minimo = (lst1->qtnos < lst2->qtnos) ? lst1->qtnos : lst2->qtnos;
    tLista *soma = lista_cria_vazia(tamanho_minimo, 1, 0); // Nova lista classificada e sem repetição

    for (int i = 0; i < tamanho_minimo; i++) {
        lista_inclui(soma, lst1->vnos[i] + lst2->vnos[i]);
    }

    return soma;
}
