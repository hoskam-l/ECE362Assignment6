#ifndef __myTools_h__
#define __myTools_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <sched.h>

extern int Rows;
extern int Cols;

#define Pthread_create(thread, attr, start_routine, arg) assert(pthread_create(thread, attr, start_routine, arg) == 0);

double GetTime()
{
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double)t.tv_sec + (double)t.tv_usec / 1e6;
}

void Spin(int howlong)
{
    double t = GetTime();
    while ((GetTime() - t) < (double)howlong)
        ; // do nothing in loop
}

void checkSquare()
{
     if(Rows != Cols)
  {
    printf("\nPlease use equal numbers for -r and -c\n");
    printf("Try again\n");
    exit(-1);
  }
}

#endif // __myTools_h__