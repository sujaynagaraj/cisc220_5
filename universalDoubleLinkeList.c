#include<stdio.h>

struct Node {
  
  union {
  int intData;
  int* intPointData
  float floatData;
  float* floatPointData;
  char charData;
  char* charPointData;
  }Data;
  
  int index;
  
  struct Node* previous;
  struct Node* next;
  
};

typedef struct Node Node;

Node* head = NULL;
Node* last = NULL;
Node* current=NULL;
void insert(int index, union Data data){
  Node* current=head;
  
  Node* new_node =(Node*) malloc(sizeof(Node)); // allocate memory for new_node
  
  
}

int main(){

return(0);
}
