#Modifiable options
ROW = 16000
COL = $(ROW)
LEN = 2
SEED = 1
THREAD = 16


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
	./seeker-base $(RUNOPTIONS2)

testbase:
	./seeker-base $(RUNOPTIONS2)