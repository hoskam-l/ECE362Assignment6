#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "myTools.h"
#include <time.h>

#define MAX_ROWS 16000
#define MAX_COLS 16000
#define DETECT_LEN 20
#define MAX_THREADS 16

int Rows = MAX_ROWS;
int Cols = MAX_COLS;
int Detect_len = DETECT_LEN;
int threads = 0;
int Image[MAX_ROWS][MAX_COLS];
typedef struct arg_struct {
    int ran1;
    int ran2;
    int col;
    int sum;
}args_t;

args_t args[MAX_THREADS];
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
  {
    for (int col = 0; col < Cols; col++)
    {
      Image[row][col] = rand() % 2;
     // printf("%d  ", Image[row][col]);
    }
  //printf("\n");
  }
}

/*
dmatch creates ranges for check for match which will go in place of printf
statement in the function below.
*/
void* dmatch(void *arg)
{
  int found = 0;
  int * result = malloc(sizeof(int));
  args_t *threadArgs = (args_t*)arg;
  for (int row = threadArgs->ran1; row < threadArgs->ran2; row++)
  {
    for (int col = 0; col < Cols; col++)
    {
      threadArgs->sum += checkForMatch(row,col);
      
      //printf("Row: %d Column: %d \n", row, col);
      
    }
  }
  printf("Number Found: %d\n", threadArgs->sum);
  *result = threadArgs->sum;
  return (void*) result;
}

int main(int argc, char *argv[])
{
  int begin, end;
  int found= 0;
  int *res;
  int quotient;
  int range1[MAX_THREADS], range2[MAX_THREADS]; 
  pthread_t tid[MAX_THREADS];
  begin = time(NULL);
  for (argc--, argv++; argc > 0; argc -= 2, argv += 2)
  {
    if (strcmp(argv[0], "-s") == 0)
      srand(atoi(argv[1]));
    else if (strcmp(argv[0], "-r") == 0)
      Rows = atoi(argv[1]);
    else if (strcmp(argv[0], "-c") == 0)
      Cols = atoi(argv[1]);
    else if (strcmp(argv[0], "-l") == 0)
      Detect_len = atoi(argv[1]);
    else if (strcmp(argv[0], "-t") == 0)
      threads = atoi(argv[1]); // stores -t value in threads
    else
    {
      printf("\nInvalid Arguments\n");
      exit(-1);
    }
  }

  makeAnImage();

  // The code below creates a number of threads based on the value input by the user
  // we need to then create a function that divides the numeber of rows by the number of
  // threads and loops through each one using the check for match function.
  // if we used 2 threads and there were 16 rows then thread one would loop through
  // rows 1-8 and thread 2 would loop through rows 9-1
  // currently pthread has not been used yet(althrough I did use pthread on a dummy function to test that the code below worked.

  //if (threads == 1 || threads == 2 || threads == 4 || threads == 8 || threads == 16)
  /* This is checking to see if the number of threads is divisible by the number of threads and also
  checking to see if the number of threads is less than or equal to the maximum number of threads. */
  if(MAX_THREADS % threads == 0  && threads <= MAX_THREADS)
  {
    // if rows are divisible by n threads
    if (Rows % threads == 0)
    {
      // divide rows by threads
      quotient = Rows / threads;
      int i = 0, j = 0;
      // creates the range of values that each thread will execute
      while (j < threads)
      {

        args[j].ran1= i;
        args[j].ran2= i + quotient;
        i = i + quotient;
        j++;
      }


      // executes the number of threads with the specified value
      // TODO: add threads and return value found
      int k = 0;
      while (k < threads)
      {
        printf("----------------------Number of Runs %d----------------------\n", k);
        // args.ran1 = range1[k];
        // args.ran2 = range2[k];
        //args.col = Cols;
        if(pthread_create(&tid[k],NULL,&dmatch, &args[k]) != 0) 
        {
          printf("pthread_create failed");
        }
        
        k++;
      }
      k = 0;
      while (k < threads)
      {
        if(pthread_join(tid[k],(void**) &res)!=0)
        {
          printf("pthread_join #%d failed", k);
        }
        found += *res;
        k++;
      }
    }

  }
  else
  {
    printf("error thread value must be 1, 4, 8, or 16");
    exit(-1);
  }

  /* old code

   for(int row=0; row < Rows; row++)
      for(int col=0; col < Cols; col++)
        found += checkForMatch(row,col);
   */
  printf("\nTOTAL DETECTED: %d\n", found);
  end = time(NULL) - begin;

  printf("elapsed time: %d\n",end);

  exit(0);
}
