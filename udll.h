//Gabby Bermudez 10157238
//sujay nagaraj 10133356
//Wayne Liong 10111359
//Lemonte Alie-Lamarche 10153786

#include<stdio.h>

#ifndef UDLL_H
#define UDLL_H

typedef union Data;

typedef struct Node Node;

int length();
void insert(int index,  Data data, int dataType);
void removeNode(int index);

#endif
