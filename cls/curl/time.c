#include <stdio.h>
#include <sys/time.h>


int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    printf("%ld\n", ms);
}
