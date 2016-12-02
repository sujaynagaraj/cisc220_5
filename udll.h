//Gabby Bermudez 10157238
//sujay nagaraj 10133356
//Wayne Liong 10111359
//Lemonte Alie-Lamarche 10153786

#include<stdio.h>

#ifndef UDLL_H
#define UDLL_H

typedef union {
  int intData;
  int* intPointData;
  float floatData;
  float* floatPointData;
  char charData;
  char* charPointData;
} Data;

typedef struct Node {
  
  Data data;

  int index;

  int length;
  
  struct Node* previous;

  struct Node* next;

  int dataType;  
} Node; 

int length();
void insert(int index,  Data data, int dataType);
void removeNode(int index);
int get(int index);
#endif
