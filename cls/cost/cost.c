#include<stdio.h>

int main()
{
    const int num = 100;
    
    printf("%d\n", num);

    int *p = &num;
    *p = 200;
    printf("%d\n", num);
    
    return 0;
}
