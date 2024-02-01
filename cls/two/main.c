#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *res)
{
    int len = 0;

    char *p = res;
    while (*p != 0)
    {
        len++;
        p++;
    }

    int i = 0;
    char c;

    while (i <= len / 2 - 1)
    {
        c = *(res + i);
        *(res + i) = *(res + len - 1 - i);
        *(res + len - 1 - i) = c;
        i++;
    }
}

void NPowerOfTwo(int n, char *res)
{
    int i, length, j, num, carry;
    for (i = 0; i < n; i++)
    {
        carry = 0;
        for (j = 0; j < strlen(res); j++)
        {
            num = res[j] - '0';
            num = (num << 1) + carry;
            
            carry  = num / 10;
            res[j] = num % 10 + '0';
        }

        if (carry > 0)
            res[j] = carry + '0';
    }
    reverse(res);
}

int main()
{
    char *res = (char *)malloc(sizeof(char *));
    int num = 1024;
    
    if (res != NULL) {
        NPowerOfTwo(num, res);
        // printf("%s\n", res);
    }
    
    free(res);
    
    return 0;   
}
