#include <iostream>
using namespace std;

int sum(int x, int y);


int sum(int x, int y)
{
    return x + y;
}

int main()
{
    int a = 9, b = 10;
    std::cout << "Hello World!\n";
    
    std::cout << "sum: " << sum(a, b) << endl;

    return 0;
}

