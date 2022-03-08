#Modifiable options
ROW = 16000
COL = $(ROW)
LEN = 22
SEED = 1
THREAD1 = 16
THREAD2 = 8 
THREAD3 = 4
THREAD4 = 2
THREAD5 = 1


FLAGS = -Wall -pthread -std=c11
INCLUDES = ./include

RUNOPTIONS1 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD1)
RUNOPTIONS2 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD2)
RUNOPTIONS3 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD3)
RUNOPTIONS4 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD4)
RUNOPTIONS5 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD5)

seek: seek.c
	gcc -I $(INCLUDES) $(FLAGS) -o seek seek.c 

seeker-base: seeker-base.c
	gcc -I $(INCLUDES) $(FLAGS) -o base seeker-base.c 

clean: 
	rm -f base seek seeker-base

test:  seek
	./seek  $(RUNOPTIONS1)
	./seek  $(RUNOPTIONS2)
	./seek  $(RUNOPTIONS3)
	./seek  $(RUNOPTIONS4)
	./seek  $(RUNOPTIONS5)

testbase: seeker-base
	./base $(RUNOPTIONS2)
