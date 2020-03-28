#ifndef __List_H__
#define __List_H__

typedef struct tList *List;
typedef enum TokenType TokenType;
typedef union Value Value;

List Create(Value value, TokenType tt);
void Print(List);

#endif