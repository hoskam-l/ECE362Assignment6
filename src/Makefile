#Modifiable options
ROW = 16000
COL = $(ROW)
LEN = 20
SEED = 15
THREAD = 16


FLAGS = -Wall -pthread -std=c11
INCLUDES = ./include

RUNOPTIONS1 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) -t $(THREAD)
RUNOPTIONS2 = -r $(ROW) -c $(COL) -l $(LEN) -s $(SEED) 

seek: seek.c
	gcc -I $(INCLUDES) $(FLAGS) -o seek seek.c 

seeker-base: seeker-base.c
	gcc -I $(INCLUDES) $(FLAGS) -o base seeker-base.c 

clean: 
	rm -f base seek seeker-base

test: seek seeker-base
	time -p ./seek $(RUNOPTIONS1)
	time -p ./base $(RUNOPTIONS2)

testbase: seeker-base
	time -p ./base $(RUNOPTIONS2)