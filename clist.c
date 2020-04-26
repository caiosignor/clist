#include "clist.h"

// void InicializarLista(Lista *iterador, Musica data){
//     Lista *lista;
//     lista = (Lista*)malloc(sizeof(Lista));
//     if(lista == NULL) {
//         printf("problema ao inicializar a lista\n");
//         return;
//     }
//     lista->musica = data;
//     lista->proximo = NULL;
// }



Lista* _criarNodo(Musica musica){
    Lista *novo_nodo = (Lista*)malloc(sizeof(Lista));
    novo_nodo->musica = musica;
    novo_nodo->proximo = NULL;
    return novo_nodo;
}

Lista *adicionarElemento(Lista *iterador, Musica data){
    Lista *novo_item = _criarNodo(data);
    Lista *auxiliar_inicio = iterador;

    if(iterador != NULL){
        while(iterador->proximo != NULL) iterador = iterador->proximo;
        iterador->proximo = novo_item;
    }else{
        iterador = novo_item;
        iterador->proximo = NULL;
#ifdef DEBUG
        printf("Adicionou %s - %s no inicio da lista\n",iterador->musica.titulo, iterador->musica.autor);
#endif
    }

#ifdef DEBUG
        // printf("Adicionou %s - %s na lista\n",iterador->musica.titulo, iterador->musica.autor);
#endif

    return iterador;
}

void for_each(Lista *inicio, void (*p)(void *data)){
    Lista *iterador = inicio;
    Musica msc;
    while(iterador->proximo != NULL){
        msc = iterador->musica;
        (*p)(&msc);
        iterador = iterador->proximo;
    }
    msc = iterador->musica;
    (*p)(&msc);
}