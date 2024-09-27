typedef struct tipo_lista tLista; 
/*cria lista vazia*/ 
tLista * lista_cria_vazia(int maximo,int classif, int repet) ;
//lista está vazia? 
int lista_vazia( const tLista *pl);
//lista está cheia? 
int lista_cheia( const tLista *pl);
//lista com repetição? 
int lista_repet( const tLista *pl);
//lista classificada? 
int lista_classif( const tLista *pl);
//percorre a lista 
void lista_percorre(const tLista *pl) ;
//inclui um item na lista: verifica caso repetição e classificação
int lista_inclui(tLista *pl, int valor) ;
//exclui um item na lista: verifica caso repetição e classificação
int lista_remove(tLista *pl, int valor) ;
int lista_obterMaximoNos(tLista *lista);
int lista_obterQuantidadeNos(tLista *lista);

tLista *lst_sublista_doi_Esimo_ao_j_Esimo(const tLista *original, int i, int j);
tLista *lst_soma_listas(const tLista *lst1, const tLista *lst2);