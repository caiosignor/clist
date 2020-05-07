#include "clist.h"
#include <stdint.h>

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

Lista* _criarNodo(void *data, int sizeofdata){
    Lista *novo_nodo = (Lista*)malloc(sizeof(Lista));
    novo_nodo->data = malloc(sizeofdata);
    int offset;
    for (offset = 0; offset < sizeofdata; offset++)
        *((uint8_t *)(novo_nodo->data + offset)) = *((uint8_t *)(data + offset));
    novo_nodo->proximo = NULL;
    return novo_nodo;
}

Lista *adicionarElemento(Lista *iterador, void *data, int sizeofdata){
    Lista *novo_item = _criarNodo(data, sizeofdata);
    Lista *auxiliar_inicio = iterador;
    
    if (novo_item == NULL) NULL;

    if(iterador != NULL){
        while(iterador->proximo != NULL) iterador = iterador->proximo;
        iterador->proximo = novo_item;
#ifdef DEBUG
        printf("Adicionou na lista\n");
#endif
    }else{
        iterador = novo_item;
        iterador->proximo = NULL;
#ifdef DEBUG
        printf("Adicionou no inicio da lista\n");
#endif
    }
    return iterador;
}

void for_each(Lista *inicio, void (*p)(void *data))
{
    Lista *iterador = inicio;
    while(iterador->proximo != NULL){
        (*p)(iterador->data);
        iterador = iterador->proximo;
    }    
    (*p)(iterador->data);
}