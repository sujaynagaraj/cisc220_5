/*
Wayne Liong 10111359
Lemonte Alie-Lamarche 10153786
Sujay Nagaraj 10133356
Gabby Bermudez 10157238
*/

#include<stdio.h>
#include<stdlib.h>
#include "udll.h"

/*
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
*/

Node* head=NULL;
Node* last=NULL;

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

		head=newNode;
		last=newNode;//because the newNode is the only node now
		newNode->dataType = dataType;
		head->length=1;
	}
	//adding to the beginning of the list
	else if (index==0){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->dataType=dataType;
		newNode->next=head;
		newNode->previous=NULL;
		newNode->length=length();
		head->previous=newNode;
		head=newNode;
		head->length=head->length+1;
	}	
	//elif adding to end of list
	//this can be implemented once we have a length function
	else if (index==head->length){
		temp=last;
		newNode=(Node*)malloc(sizeof(Node));
		newNode->data=data;
		newNode->dataType=dataType;
		temp->next=newNode;
		newNode->previous=temp;
		newNode->next=NULL;
		last=newNode;
		head->length=head->length+1;
	}
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
		newNode->dataType=dataType;
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
		newNode->dataType=dataType;
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

/*
For the get function, I had to make the return type void so that I can properly return to the user the value of whatever is in the node
in the form of a print statement. We tried implementing the function as shown in the assigment where the return type of this function is
a union called Data. However, using multiple different methods, we kept getting compilation errors (refer to change history). 
As such, we deemed this to be the best way to show the user what the value is in the node.

*/
void get(int index){
	Node *temp;
	int currentIndex;
	int distance = ((length() -1) - index);
	
	if( head == NULL )
		return;
	else if (index < 0  || index >= length())
		return;
	else if (distance >index) {
		temp=head;
		currentIndex=0;
		while (currentIndex < index){
			temp = temp->next;
			currentIndex=currentIndex+1;
		}
	}// end else if
	
	else {
		temp=last;
		currentIndex = length()-1;
		while (currentIndex > index){
			temp = temp->previous;
			currentIndex=currentIndex-1;
		}
	}
	
	//Set of if statements that determine which union variable is used
	if ((temp->dataType) == 0)
		printf("The value at node %d is: '%d' \n ", index, temp->data.intData) ;
	else if ((temp->dataType) == 1)
		printf("The value at node %d is: '%p' \n ",index,temp->data.intPointData);
	else if ((temp->dataType) == 2)
		printf("The value at node %d is: '%f'",index, temp->data.floatData);
	else if ((temp->dataType) == 3)
		printf("The value at node %d is: '%p' ",index, temp->data.floatPointData);
	else if ((temp->dataType) == 4)
		printf("The value at node %d is: '%c'",index, temp->data.charData);
	else //((temp->dataType) == 5)
		printf("The value at node %d is: '%p'",index, temp->data.charPointData);
}// end of Get

void freeSpace(){
	Node* temp = head;
	if (temp==NULL){
		return;	
	}
	else{
		while (temp->next!=NULL){
			temp=temp->next;
			free(temp->previous);
		}
		
		free(temp);
	}
}


