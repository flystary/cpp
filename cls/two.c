#include <stdio.h>

int main()
{
    int a[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int (*p)[4] = &a[0];
    for(int i=0; i<3; i++)
    {
        printf("*(p+%d)+%d", i, j, *(p+i)+j);
    }
    printf("\n");
}
