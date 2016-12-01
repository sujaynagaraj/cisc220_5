/*
Gabby Bermudez 10157238
sujay nagaraj 10133356
Wayne Liong 10111359
Lemonte Alie-Lamarche 10153786
*/

#include<stdio.h>

main.o: main.c udll.c udll.h;
	gcc -Wall -o main.c mystring.c

udll.o: udll.c;
	gcc -Wall -o udll.c udll.h

universalDoubleLinkeList: main.o;
	gcc -Wall -o universalDoubleLinkeList main.o udll.o
