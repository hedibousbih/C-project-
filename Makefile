prog:mini.o main.o
	gcc mini.o main.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
mini.o:mini.c
	gcc -c mini.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
