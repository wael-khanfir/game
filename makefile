prog:jeu.o main.o
gcc jeu.o main.o -o prog
main.o:main.c
	gcc -c main.c 
jeu.o:jeu.c
	gcc -c jeu.c 
	
