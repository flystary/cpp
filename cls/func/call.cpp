#include <iostream>

int callbackFun(int lhs, int rhs)
{
    return lhs + rhs;
}

int callbackRandy(int (*fp)(int, int), int lhs, int rhs)
{
    return fp(lhs, rhs);
}

int main()
{
    int sum = callbackRandy(callbackFun, 2, 13);
    std::cout << sum << std::endl;

    return 0;
}
