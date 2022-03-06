#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "myTools.h"

#define MAX_ROWS 16000
#define MAX_COLS 16000
#define DETECT_LEN 20

int Rows = MAX_ROWS;
int Cols = MAX_COLS;
int Detect_len = DETECT_LEN;
int Image[MAX_ROWS][MAX_COLS];



/**
 * Check for a match of the given length in the image
 *
 * @param row The row of the first pixel in the line.
 * @param col The column to start the search
 *
 * @return The number of matches found.
 */
int checkForMatch(int row, int col)
{
  int r, c, length;
  int detect = 0;

  for (length = 0, c = col; c < Cols; c++)
    if (Image[row][c] == 1)
    {
      if (++length == Detect_len)
      {
        detect++;
        break;
      }
    }
    else
      break;

  for (length = 0, r = row; r < Rows; r++)
    if (Image[r][col] == 1)
    {
      if (++length == Detect_len)
      {
        detect++;
        break;
      }
    }
    else
      break;

  return detect;
}

/**
 *  creates an image of the table
 */
void makeAnImage()
{
  for (int row = 0; row < Rows; row++)
    for (int col = 0; col < Cols; col++)
      Image[row][col] = rand() % 2;
}


/*
dmatch creates ranges for check for match which will go in place of printf 
statement in the function below.
*/
void dmatch(int range1, int range2, int Cols)
{
    for(int row=range1; row < range2; row++)
    {
        for(int col=0; col < Cols; col++)
        {
            printf("Row: %d Column: %d \n", row, col);
        }
    }
}

int main(int argc, char *argv[]) {
  int found =0;
  int threads =0;
  int quotient;
  int range1[20], range2[20]; //DEBUG: remove hard coding
  pthread_t tid;  

  for( argc--, argv++; argc > 0; argc-=2, argv+=2  ) {
          if      (strcmp(argv[0], "-s" ) == 0 ) srand ( atoi(argv[1]) );
          else if (strcmp(argv[0], "-r" ) == 0 ) Rows = atoi(argv[1]);
          else if (strcmp(argv[0], "-c" ) == 0 ) Cols = atoi(argv[1]);
          else if (strcmp(argv[0], "-l" ) == 0 ) Detect_len = atoi(argv[1]);
		  else if(strcmp(argv[0], "-t" ) == 0 ) threads = atoi(argv[1]); //stores -t value in threads
          else { printf("\nInvalid Arguments\n"); exit(-1); }
      }

  makeAnImage();
  
  //The code below creates a number of threads based on the value input by the user
  //we need to then create a function that divides the numeber of rows by the number of 
  //threads and loops through each one using the check for match function. 
  //if we used 2 threads and there were 16 rows then thread one would loop through
  //rows 1-8 and thread 2 would loop through rows 9-16
  
	
	if(threads == 1 || threads == 2 || threads == 4 || threads == 8 || threads == 16)
	  {
		//if rows are divisible by n threads
		if(rows%threads == 0)
		{
			//divide rows by threads
			quotient = rows/threads;
			int i = 0, j = 0;
			//creates the range of values that each thread will execute
			while(j < threads)
			{

				range1[j] = i;
				range2[j] = i + quotient;
				i = i + quotient;
				j++;
			}
			//executes the number of threads with the specified value
			//TODO: add threads and return value found
			int k; 
			while(k < threads)
			{
				printf("----------------------Number of Runs %d----------------------\n", k);
				dmatch(range1[k], range2[k], Cols);
				k++;
			}
	  }
	  else
	  {
		  perror("error thread value must be 1, 4, 8, or 16");
	  }
	  
	  
	  
	  
 /* old code
 
  for(int row=0; row < Rows; row++)
     for(int col=0; col < Cols; col++)
       found += checkForMatch(row,col);
	*/
  printf("\nTOTAL DETECTED: %d\n", found);

  exit(0);
}
