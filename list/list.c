#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef enum TokenType {
  TEXT=1,
  INTEGER=2,
  REAL=3,
} TokenType;

typedef union Value {
  int i;
  double r;
  char *t;
} Value;

typedef struct tList {
  TokenType tt;
  Value value;
  struct tList *prox;
} *List;

void Print(List l) {
  if (l->tt == TEXT) {
    printf("%s\n", l->value.t);
  } else if (l->tt == INTEGER) {
    printf("%d\n", l->value.i);
  } else if (l->tt == REAL) {
    printf("%f\n", l->value.r);
  } else {
    printf("Type undefined: %d \n", l->tt);
  }
}

List Create(Value value, TokenType tt) {
  List l = malloc(sizeof(struct tList));
  
  l->tt = tt;
  if (tt == TEXT) {
    l->value.t = value.t;
  } else if (tt == INTEGER) {
    l->value.i = value.i;
  } else if (tt == REAL) {
    l->value.r = value.r;
  }

  return l;
}

int main(void) {
  Value v;
  v.i = 10;
  List l = Create(v, INTEGER);
  v.r = 11.0;
  l->prox = Create(v, REAL);

  Print(l);
  Print(l->prox);

  return 0;
}