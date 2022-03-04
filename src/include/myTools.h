#ifndef __myTools_h__
#define __myTools_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <sched.h>

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

#endif // __myTools_h__