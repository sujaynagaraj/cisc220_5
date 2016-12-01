/*
Wayne Liong 10111359
Lemonte Alie-Lamarche 10153786
Sujay Nagaraj 10133356
Gabby Bermudez 10157238
*/


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

  void* dataType;  
} Node;

Node* head = NULL;
Node* last = NULL;

int length() {
	int len = 0;
	if(head != NULL){
		len=(head->length);
	}
return len;
}


void insert(int index,  Data data, int dataType){
	int i;
	Node *newNode, *temp; // *newNode is a pointer to the newNode to insert. *temp is a pointer that helps us traverse through list
	
	//dealing with an empty linked list
	if (head==NULL){ 
		newNode= (Node*)malloc(sizeof(Node)); //allocating memory
		newNode->data=data;
		newNode->next=NULL;
		newNode->previous=NULL;
		newNode->length=(length()+1);

		head=newNode;
		last=newNode;//because the newNode is the only node now
		head->length=head->length+1;
	}
	//adding to the beginning of the list
	else if (index==0){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->next=head;
		newNode->previous=NULL;
		newNode->length=length();
		head->previous=newNode;
		head=newNode;
		head->length=head->length+1;
	}	
	//elif adding to end of list
	//this can be implemented once we have a length function

	else {
		temp=head;
		int len = head->length;
		int distanceFromHead=index;
		int distanceFromLast=(len-1)-index;
		
		
		if (distanceFromLast<=distanceFromHead){
			temp=last;
			i=len-1;
			while(i>index && temp!=NULL){ // traversing through list from tail
			temp=temp->previous; //decrementing the pointer
			i--;
				
				
			}
			
			
		newNode= (Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->next=temp;
		
		if (temp->previous != NULL){
			newNode->previous=temp->previous;
			temp->previous->next=newNode;
		}
		temp->previous=newNode;
		head->length=head->length+1;
			
		}
		else {
			i=0;
		
		//need to add: traversal from tail to head if it is more efficient. Need length function
		while(i<index-1 && temp!=NULL){ // traversing through list from head
			temp=temp->next; //incrementing the pointer
			i++;
		}
		}
		
		newNode= (Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->next=temp->next;
		newNode->previous=temp;
		if (temp->next != NULL){
			temp->next->previous=newNode;
		}
		temp->next=newNode;
		head->length=head->length+1;
	}
  
  
}



// deletes the node with the specified index. It should connect the previous node [index-1] to
// the following node [index+1]. If the node is at the beginning of the linked list, make sure 
// to update the head pointer. If the node is at the end of the linked list, make sure to 
// update the last pointer. Achieve this in the minimum number of iterations possible.

/****** UPDATE FUNCTION TO PREVENT MEMORY LEAKS; FREE MEMORY UPON DELETING NODES *****/

void removeNode(int index){
	// We will first consider the possible edge cases (not all need to be done on their own,
	// but this is a group assignment and doing so makes the code easier to follow).
	
	int lengthOfList = 0;
	if (head != NULL){ // Assume list is empty, and update length if it is not.
		lengthOfList = head->length;
	}
	// i) If list is empty, we are done.
	if (head==NULL){
		return;
	}
	// ii) The index is out of range; do nothing.
	else if (index+1 > lengthOfList){
		return;
	} 		
	// iii) We are removing the only node in the list.
	// to achieve this, point head to NULL and last to NULL. This creates an empty list.
	else if (index==0 && head->next==NULL){
		Node *toBeDeleted=head;
		free(toBeDeleted);
		head=NULL;
		last=NULL;
	}		
	// iv) We are removing the first node in the list and it contains more than one element.
	// to acheive this, head to the first node, store its 'next pointer' in a temporary variable
	// and point head to this temporary variable.
	else if (index==0){
 		Node *toBeDeleted;
		toBeDeleted=head; //temporary pointer to current head node
		head=head->next; //point the current head pointer to the second node
		free(toBeDeleted);
		head->length-=1;
	}
	// v) We are removing the last node in the list and it contains more than one element.
	// to achieve this, head to the last node, and then head to its previous node. Then,
	//  point the penultimate node's next pointer to NULL. 
	else if (index+1==lengthOfList){ 
		Node *toBeDeleted;
		toBeDeleted=last;
		last=last->previous;
		last->next=NULL;
		free(toBeDeleted);
		head->length-=1;
	}
	// Finally, if the node is any other node, we will use the length function to determine 
	// whether iteration from head or iteration from last is faster. The structure of the 
	// conditional statements should guarantee that this block only executes if index is in 
	// range, and it is neither the head nor tail of the list. 	
	else{
		int currentIndex;
		Node *currentNode=head;
		int distanceFromLast=((lengthOfList-1)-index);
		int distanceFromHead=index;
			
		if (distanceFromHead <= distanceFromLast){
		 	currentIndex=0;
			currentNode=head;
			while (currentIndex < index){ // stops at node before node being removed
				currentIndex++;
				currentNode=currentNode->next; // move forward one node
			}
		} //end if 
		else { // distanceFromHead > distanceFromTail
			currentIndex=lengthOfList-1;
			currentNode=last;
			while (currentIndex > index){
				currentIndex--; // stops at node being removed
				currentNode=currentNode->previous; //move back one node
			}
		} // end else
		
		Node *toBeDeleted=currentNode;
		
		Node *nodeBefore=currentNode->previous; 
		Node *nodeAfter=currentNode->next; 

		nodeBefore->next=nodeAfter;
		nodeAfter->previous=nodeBefore;	
		
		free(toBeDeleted);
		head->length-=1;
	} 
} // end funtion removeNode


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
		int dataType=0;
                insert(n, newData, dataType);
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

