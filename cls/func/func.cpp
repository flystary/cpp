#include <iostream>

typedef int (*fp)(int, int);

int Sum(int lhs, int rhs)
{
    return lhs + rhs;
}

int Minus(int lhs, int rhs)
{
    return lhs - rhs;
}

int main()
{
    int (*randy)(int, int);

    randy = Sum;
    std::cout << randy(2, 13) << std::endl;

    fp sesame = Minus;
    std::cout << sesame(22, 1) << std::endl;

    return 0;
}
