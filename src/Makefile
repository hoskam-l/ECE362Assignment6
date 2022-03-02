FLAGS = -ggdb -Wall -pthread -std=c11
INCLUDES = ./include

seek: seek.c
	gcc -I $(INCLUDES) -o seek seek.c $(FLAGS)

base: seeker-base.c
	gcc -I $(INCLUDES) -o base seeker-base.c $(FLAGS)

clean: 
	rm -f base seek


