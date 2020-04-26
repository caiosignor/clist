#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include <stdio.h>

// #define DEBUG

typedef struct _Lista Lista;
typedef struct _Musica Musica;

struct _Musica
{   
    char *titulo;
    char *autor;
    int  duracao_em_segundos;
};

struct _Lista
{
    Musica musica;
    Lista *proximo;
};

void  InicializarLista(Lista *iterador, Musica data);
Lista *adicionarElemento(Lista *iterador, Musica data);
void for_each(Lista *inicio, void (*p)(void *data));

#endif