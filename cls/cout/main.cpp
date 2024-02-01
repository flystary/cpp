#include <iostream>
#include <libio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int i = 1;
    std::string j = "hello";

    printf("%d\n", i);
    printf("%s\n", j.c_str());

    return 0;
}