#Modifiable options
ROW = 10
COL = $(ROW)
LEN = 3
SEED = 5
THREAD = 2


FLAGS = -Wall -pthread -std=c11
INCLUDES = ./include

RUNOPTIONS1 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD)
RUNOPTIONS2 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) 

seek: seek.c
	gcc -I $(INCLUDES) -o seek seek.c $(FLAGS)

base: seeker-base.c
	gcc -I $(INCLUDES) -o base seeker-base.c $(FLAGS)

clean: 
	rm -f base seek seeker-base

test:
	./seek $(RUNOPTIONS1)

testbase:
	./seeker-base $(RUNOPTIONS2)