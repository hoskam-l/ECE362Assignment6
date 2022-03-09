# ECE362
# Assignment 6 
# Dr. Schubert
# by luke hoskam
# by Hayden Galante
# Makefile for Assignment 6

#Modifiable options
ROW = 16000
COL = $(ROW)
LEN = 30
SEED = 46548
THREAD_A = 1
THREAD_B = 2
THREAD_C = 4
THREAD_D = 8
THREAD_E = 16

FLAGS = -Wall -pthread -std=c11
INCLUDES = ./include

RUNOPTIONS1 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD_A)
RUNOPTIONS2 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD_B)
RUNOPTIONS3 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD_C)
RUNOPTIONS4 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD_D)
RUNOPTIONS5 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD_E)
RUNOPTIONS6 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) 

seek: seek.c
	gcc -I $(INCLUDES) $(FLAGS) -o seek seek.c 

seeker-base: seeker-base.c
	gcc -I $(INCLUDES) $(FLAGS) -o base seeker-base.c 

clean: 
	rm -f base seek seeker-base

test: seek seeker-base
	time -p ./base $(RUNOPTIONS6)
	time -p ./seek $(RUNOPTIONS1)
	time -p ./seek $(RUNOPTIONS2)
	time -p ./seek $(RUNOPTIONS3)
	time -p ./seek $(RUNOPTIONS4)
	time -p ./seek $(RUNOPTIONS5)
	

testbase: seeker-base
	time -p ./base $(RUNOPTIONS2)