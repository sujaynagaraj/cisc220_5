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
	int i;
	Node* newNode, *temp;
	if (head==NULL){
	}
	else {
		temp=head;
		i=1;
		while(i<index-1 && temp!=NULL){ // traversing through list from top
			temp=temp->next;
			i++

		}
		newNode= (Node*)malloc(sizeof(Node)); //allocate memory
		newNode->Data=data;// put data into newNode
		newNode->next=temp->next;
		newNode->prev=temp;
		if (temp->next != NULL){
			temp->next->prev=newNode;
		}
		temp->next=newNode;
	}
  
  
  
}

void displayList()
{
    Node * temp;
    int n = 1;
 
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
 
        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
 
            n++;
 
            /* Moves the current pointer to next node */
            temp = temp->next;
        }
    }
}
int main(){

return(0);
}

