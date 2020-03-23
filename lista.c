#include <stdio.h>
#include <stdlib.h>

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

typedef struct Lista {
  TokenType tt;
  Value v;
  struct Lista *prox;
} Lista;

void Imprimir(Lista l) {
  if (l.tt == TEXTO) {
    printf("%s", l.v.t);
  } else if (l.tt == INTEIRO) {
    printf("%d", l.v.i);
  } else if (l.tt == REAL) {
    printf("%ls", l.v.r);
  } else {
    printf("Erro %d \n", l.tt);
  }
}

Lista CriarLista(Value v, TokenType tt) {
  Lista l = malloc(sizeof(struct Lista));;
  
  if (tt == TEXTO) {
    l.v.t = v.t;
  } else if (tt == INTEIRO) {
    l.v.i = v.i;
  } else if (tt == REAL) {
    l.v.r = v.r;
  }

  return l;
}

int main(void) {
  Value v;
  v.i = 10;
  Lista l = CriarLista(v, INTEIRO);
  // v.r = 11.0;
  // l.prox = &CriarLista(v, REAL);

  Imprimir(l);
  // Imprimir(*l.prox);

}