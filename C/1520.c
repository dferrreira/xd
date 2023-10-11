#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int n;
  struct element *prox;
} NO;

typedef struct {
  NO *inicio;
} LISTA;

void iniList(LISTA *l) { l->inicio = NULL; }

void restart(LISTA *l) {
  NO *aux = l->inicio;
  while (aux != NULL) {
    l->inicio = l->inicio->prox;
    free(aux);
    aux = l->inicio;
  }
  iniList(l);
}

int empty(LISTA *l) {
  if (l->inicio == NULL)
    return 1;
  return 0;
}

void insert(LISTA *l, int key) {
  NO *ele = (NO *)malloc(sizeof(NO));
  ele->n = key;
  if (empty(l)) {
    l->inicio = ele;
    ele->prox = NULL;
  } else {
    NO *aux = l->inicio;
    NO *ant = NULL;
    while (aux->prox != NULL && aux->n <= ele->n) {
      ant = aux;
      aux = aux->prox;
    }
    if (aux->prox == NULL && aux->n <= ele->n) {
      aux->prox = ele;
      ele->prox = NULL;
    } else if (aux == l->inicio) {
      ele->prox = l->inicio;
      l->inicio = ele;
    } else {
      ele->prox = aux;
      ant->prox = ele;
    }
  }
}

int search(LISTA *l, int key, int *y) {
  NO *aux = l->inicio;
  int x = 0;
  while (aux != NULL) {
    printf("%d\n", aux->n);
    if (key == aux->n) {
      *y = *y + 1;
      if (aux->prox == NULL || aux->prox->n != key)
        break;
    } else
      x++;
    aux = aux->prox;
  }
  return x;
}

int main(void) {
  LISTA *l = (LISTA *)malloc(sizeof(LISTA));
  iniList(l);
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      while (a <= b) {
        insert(l, a);
        a++;
      }
    }
    int p, x, y = -1;
    scanf("%d", &p);
    int *ptr = &y;
    x = search(l, p, ptr);
    //printf("%d %d\n", x, *ptr);
    if (*ptr == -1)
      printf("%d not found\n", p);
    else{
      *ptr = *ptr + x;
      printf("%d found from %d to %d\n", p, x, y);
    }
    restart(l);
    x = 0;
    *ptr = 0;
  }
  free(l);
  return 0;
}