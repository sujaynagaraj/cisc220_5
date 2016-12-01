/*
Gabby Bermudez 10157238
sujay nagaraj 10133356
Wayne Liong 10111359
Lemonte Alie-Lamarche 10153786
*/

#include<stdio.h>

udll.o: udll.c udll.h;
	gcc -Wall -c udll.c udll.h

main.o: main.c udll.c udll.h;
	gcc -Wall -c main.c udll.c

universalDoubleLinkeList: main.o;
	gcc -Wall -o universalDoubleLinkeList main.o udll.o
