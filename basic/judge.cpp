#include <iostream>

using namespace std;


int judge(int max)
{
    for(int i = 0; i < max; i++)
    {
        i % 2 == 0 ? cout << "偶数 " << i << endl : cout << "奇数 " << i << endl;
    }

    return 0;
}

int main()
{
    judge(10);

    return 0;
}
