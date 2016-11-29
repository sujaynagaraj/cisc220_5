#include<stdio.h>
#include<stdlib.h>
typedef union {
	int intData;
  int* intPointData;
  float floatData;
  float* floatPointData;
  char charData;
  char* charPointData;
} Data;

struct Node {
  
  Data data;
  int index;
  
  struct Node* previous;
  struct Node* next;
  
};

typedef struct Node Node;

Node* head = NULL;
Node* last = NULL;
Node* current=NULL;
void insert(int index,  Data data){
	int i;
	Node *newNode, *temp;
	if (head==NULL){
		newNode= (Node*)malloc(sizeof(Node)); 
		newNode->data=data;
		newNode->next=NULL;
		newNode->previous=NULL;
		newNode->index=0;
		head=newNode;
	}

	else {
		temp=head;
		i=0;
		while(i<index && temp!=NULL){ // traversing through list from head
			temp=temp->next;
			i++;

		}
		newNode= (Node*)malloc(sizeof(Node)); //allocate memory
		newNode->data=data;// put data into newNode
		newNode->next=temp->next;
		newNode->previous=temp;
		newNode->index=index;
		if (temp->next != NULL){
			temp->next->previous=newNode;
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
            printf("DATA of %d node = %d\n", n, temp->data.intData);
 
            n++;
 
            /* Moves the current pointer to next node */
            temp = temp->next;
        }
    }
}
int main(){

int n, choice=1;
Data newData;
int data;
 
    head = NULL;
    last = NULL;
 
    /*
     * Runs forever until user chooses 0
     */
    while(choice != 0)
    {
        /*
         * Menu creation to use the program
         */
        printf("============================================\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Insert node - at N\n");
        printf("5. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
 
        scanf("%d", &choice);
 
        /*
         * Chooses from different menu operation
         */
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
 
    
                break;
            case 2:
                printf("Enter data of first node : ");
               // scanf("%d", &data);
 
               // insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data of last node : ");
               // scanf("%d", &data);
 
                //insertAtEnd(data);
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);
 		newData.intData=data;
                insert(n, newData);
                break;
            case 5:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }
 
        printf("\n\n\n\n\n");
    }

return(0);
}

