#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdio.h>

// #define DEBUG

typedef struct _Lista Lista;


struct _Lista
{
    void *data;
    Lista *proximo;
};

Lista *adicionarElemento(Lista *iterador, void *data, int sizeofdata);
void for_each(Lista *inicio, void (*p)(void *data));

#endif