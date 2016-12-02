/*
 * Wayne Liong 10111359
 * Lemonte Alie-Lamarche 10153786
 * Sujay Nagaraj 10133356
 * Gabby Bermudez 10157238
 */

#include<stdio.h>;
#include<stdlib.h>;
#include"udll.c";
#include"udll.h";

int main(){
	int userInput=-1;
	printf("Welcome to the linked list program!\n\n");	
	
	while (userInput != 0){
		printf("Enter 1 to insert a new node.\n");
		printf("Enter 2 to remove a node.\n");
		printf("Enter 3 to retrieve the value in a node.\n");
		printf("Enter 0 to exit the program.\n\n");

		printf("What will you do? :  ");
		scanf("%d",userInput);
		
		if (userInput==1){
			// call insert; 
		}	
		else if (userInput==2){
			// call remove;
		}
		else if (userInput==3){
			// call get;
		}
		else if (userInput < 0 || userInput > 3){
			printf("Error: '%d' is not a valid input. Enter int from 0-3.",userInput);
		}
		else{ //userInput==0;
			printf("Thanks for using our program!\n");
		}
		
		
	} // end while;
	return 0;
} // end function main;
