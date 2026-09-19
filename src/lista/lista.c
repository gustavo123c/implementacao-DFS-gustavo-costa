#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

No *criarNo(int vertice) {
  No *novo = malloc(sizeof(No));

  if (novo == NULL) {
    return NULL;
  }

  novo->vertice = vertice;
  novo->proximo = NULL;

  return novo;
}

void inicializarListaAdj(No *lista[]) {
  if (lista == NULL) {
    return;
  }

  for (int i = 0; i < MAX_VERTICES; i++) {
    lista[i] = NULL;
  }
}

void destruirListaAdj(No **lista) {
  if (lista == NULL) {
    return;
  }

  for (int i = 0; i < MAX_VERTICES; i++) {
    No *atual = lista[i];

    while (atual != NULL) {
      No *proximo = atual->proximo;

      free(atual);

      atual = proximo;
    }

    lista[i] = NULL;
  }
}