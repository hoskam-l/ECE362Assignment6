#Modifiable options
ROW = 5
COL = $(ROW)
LEN = 3
SEED = 1


FLAGS = -Wall -pthread -std=c11
INCLUDES = ./include

RUNOPTIONS = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED)

seek: seek.c
	gcc -I $(INCLUDES) -o seek seek.c $(FLAGS)

base: seeker-base.c
	gcc -I $(INCLUDES) -o base seeker-base.c $(FLAGS)

clean: 
	rm -f base seek

test:
	./seek $(RUNOPTIONS)
