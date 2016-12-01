/.


#include<stdio.h>
#include<stdlib.h>

//Union that can contain different types of data
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
  
} Node;


Node* head = NULL;
Node* last = NULL;

int length()
	int len = 0;
	struct Node* currentnode;

	currentnode = head;
	while(currentnode.next != NULL){
		len++;
		currentnode=currentnode->next;
	}
	
return len;
}

void insert(int index,  Data data){
	int i;
	Node *newNode, *temp; // *newNode is a pointer to the newNode to insert. *temp is a pointer that helps us traverse through list
	
	//dealing with an empty linked list
	if (head==NULL){ 
		newNode= (Node*)malloc(sizeof(Node)); //allocating memory
		newNode->data=data;
		newNode->next=NULL;
		newNode->previous=NULL;
		newNode->length=length();
		head=newnode;
		last=newNode;//because the newNode is the only node now
	}
	//adding to the beginning of the list
	else if (index==0){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->next=head;
		newNode->previous=NULL;
		newNode->length=length;
		head->previous=newNode;
		head=newNode;
	}	
	//elif adding to end of list
	//this can be implemented once we have a length function

	else {
		temp=head;
		i=0;
		
		//need to add: traversal from tail to head if it is more efficient. Need length function
		while(i<index-1 && temp!=NULL){ // traversing through list from head
			temp=temp->next; //incrementing the pointer
			i++;
		}
		newNode= (Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->next=temp->next;
		newNode->previous=temp;
		if (temp->next != NULL){
			temp->next->previous=newNode;
		}
		temp->next=newNode;
		head->length=length()
	}
  
  
}

//Copied from another website. Helps with testing. NEED TO DELETE BEFORE SUBMISSION.
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

//COPIED FROM ANOTHER WEBSITE. GOOD FOR TESTING. NEED TO DELETE BEFORE SUBMISSION. Feel free to add code to help test your individual functions.
int main(){

int n, choice=1;
Data newData;
int dataToAdd;
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
                scanf("%d", &dataToAdd);
 		newData.intData=dataToAdd;
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

