#ifndef __Lista_H__
#define __Lista_H__

typedef struct tLista *Lista;
typedef enum TokenType TokenType;
typedef union Value Value;

Lista CriarLista(Value value, TokenType tt);
void Imprimir(Lista);
// void DestruirLista(Lista *);

#endif