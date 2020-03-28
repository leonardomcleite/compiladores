#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef enum TokenType {
  TEXTO=1,
  INTEIRO=2,
  REAL=3,
} TokenType;

typedef union Value {
  int i;
  double r;
  char *t;
} Value;

typedef struct tLista {
  TokenType tt;
  Value value;
  struct tLista *prox;
} *Lista;

void Imprimir(Lista l) {
  if (l->tt == TEXTO) {
    printf("%s\n", l->value.t);
  } else if (l->tt == INTEIRO) {
    printf("%d\n", l->value.i);
  } else if (l->tt == REAL) {
    printf("%f\n", l->value.r);
  } else {
    printf("Erro %d \n", l->tt);
  }
}

Lista CriarLista(Value value, TokenType tt) {
  Lista l = malloc(sizeof(struct tLista));
  
  l->tt = tt;
  if (tt == TEXTO) {
    l->value.t = value.t;
  } else if (tt == INTEIRO) {
    l->value.i = value.i;
  } else if (tt == REAL) {
    l->value.r = value.r;
  }

  return l;
}

int main(void) {
  Value v;
  v.i = 10;
  Lista l = CriarLista(v, INTEIRO);
  v.r = 11.0;
  l->prox = CriarLista(v, REAL);

  Imprimir(l);
  Imprimir(l->prox);

  return 0;
}